What to change in the file : 

[1] Get a GitHub Token (recommended) :

1. Without a token, you'll be limited to 60 searches per hour. To get one:
2. Go to: https://github.com/settings/tokens
3. Click "Generate new token" → "Generate new token (classic)"
4. Give it a name like "API Key Scanner"
5. Check the "repo" permission checkbox
6. Click "Generate token"
7. Copy the token

Then set it as an environment variable:
# On Windows (Command Prompt):
set GITHUB_TOKEN=your_token_here
# On Windows (PowerShell):
$env:GITHUB_TOKEN="your_token_here"
# On Mac/Linux:
export GITHUB_TOKEN="your_token_here"

[2] HOW TO RUN THE FILE ->

Step-by-step instructions:
Step 1: 
    Save the Python code to a file
    Create a new file called github_key_scanner.py
    Copy and paste the entire code I provided
    Save the file

Step 2: Install dependencies :
    pip install requests openai
Step 3: Run the program :
    python github_key_scanner.py

_____________________________________
or alternatively : 
Create a file setup_and_run.bat (on Windows) or setup_and_run.sh (on Mac/Linux):

-->For Windows (setup_and_run.bat):
@echo off
echo Installing dependencies...
pip install requests openai
echo.
echo Running GitHub API Key Scanner...
python github_key_scanner.py
pause

-->For Mac/Linux (setup_and_run.sh):
#!/bin/bash
echo "Installing dependencies..."
pip install requests openai
echo
echo "Running GitHub API Key Scanner..."
python github_key_scanner.py

Then just double-click the batch file or run the shell script.
_____________________________________

At last the final instructions : 
1. get the GITHUB_TOKEN as instructed in [1]
2. Then Run the setup_and_run.sh file and get the keys in your txt file.

how to run , run below two commands: 
chmod +x setup_and_run.sh
./setup_and_run.sh

_____________________________________
Edits you can do : 
-we can change SEARCH_PATTERNS if you have any more ideas.
-You can change pagination like instead of 10 how many pages you want to go through.
_____________________________________

This is just for educational purpose.
