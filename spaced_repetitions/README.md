# Spaced Repetitions

This folder contains the script used to schedule spaced-repetition review sessions on Google Calendar based on the *leetCode.xlsx* file.

## How it works

The script:

1. Reads the sessions sheet from leetCode.xlsx.
1. Reads the following columns:
    - \#
    - name
    - review session
1. For each review session scheduled for today or a future date:
    - creates an event at 21:00;
    - sets the duration to 45 minutes;
    - names the event <#> <name>;
1. Before creating an event, it checks whether an event with the same name already exists on that day.
1. Past review sessions are ignored.
1. Existing events are never modified.

## First-time setup

Create a Python virtual environment:

> python3 -m venv .venv
> source .venv/bin/activate

Install the required dependencies:

> python3 -m pip install openpyxl google-api-python-client google-auth-httplib2 google-auth-oauthlib

Google Calendar API credentials are also required.

Place the OAuth client credentials downloaded from Google Cloud in this folder as:

> credentials.json

## First run

Run:

> python3 sessionPushOnCalendar.py

On the first run, Google OAuth authorization is required.

The script may not be able to open the browser automatically when running inside WSL. If this happens, copy the URL printed in the terminal and open it manually in a browser.

After successful authorization, a token.json file is created. This file is used for subsequent runs.

## Running the script

Activate the virtual environment:

> source .venv/bin/activate

Then run:

> python3 sessionPushOnCalendar.py

When finished, the script prints a summary such as:

> Done. Created: 5, skipped: 3, past: 11
- **created**: new calendar events created.
- **skipped**: review sessions for which an event with the same name already exists on that day.
- **past**: review sessions before today's date.

## Files
spaced-repetitions/  
├── leetCode.xlsx  
├── sessionPushOnCalendar.py  
├── credentials.json  
├── token.json  
├── .venv/  
└── README.md  

**N.B.:credentials.json, token.json, and .venv/ are local files and should not be committed to Git!**