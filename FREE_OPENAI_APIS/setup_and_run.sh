#!/bin/bash
echo "Installing dependencies..."
pip3 install requests openai
echo
echo "Running GitHub API Key Scanner..."
python3 github_key_scanner.py