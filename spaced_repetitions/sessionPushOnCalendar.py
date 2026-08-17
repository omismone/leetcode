from datetime import datetime, timedelta
from pathlib import Path
from zoneinfo import ZoneInfo

import openpyxl

from google.auth.transport.requests import Request
from google.oauth2.credentials import Credentials
from google_auth_oauthlib.flow import InstalledAppFlow
from googleapiclient.discovery import build


# Google Calendar API scope
SCOPES = ["https://www.googleapis.com/auth/calendar"]

EXCEL_FILE = "leetCode.xlsx"
SHEET_NAME = "sessions"
CALENDAR_ID = "primary"

TIMEZONE = "Europe/Rome"

EVENT_HOUR = 21
EVENT_MINUTE = 0
EVENT_DURATION_MINUTES = 45

# Google Calendar event color: Banana
EVENT_COLOR_ID = "5"


def get_calendar_service():
    """Authenticate with Google Calendar and return the API service."""
    creds = None

    token_file = Path("token.json")
    credentials_file = Path("credentials.json")

    if token_file.exists():
        creds = Credentials.from_authorized_user_file(
            token_file,
            SCOPES,
        )

    if not creds or not creds.valid:
        if creds and creds.expired and creds.refresh_token:
            creds.refresh(Request())
        else:
            flow = InstalledAppFlow.from_client_secrets_file(
                credentials_file,
                SCOPES,
            )

            # The browser must be opened manually on the first run.
            creds = flow.run_local_server(
                port=0,
                open_browser=False,
            )

        token_file.write_text(creds.to_json())

    return build("calendar", "v3", credentials=creds)


def event_already_exists(
    service,
    calendar_id,
    title,
    review_date,
):
    """Check whether an event with the same title exists on the given date."""
    timezone = ZoneInfo(TIMEZONE)

    start_of_day = datetime(
        year=review_date.year,
        month=review_date.month,
        day=review_date.day,
        tzinfo=timezone,
    )

    start_of_next_day = start_of_day + timedelta(days=1)

    response = service.events().list(
        calendarId=calendar_id,
        timeMin=start_of_day.isoformat(),
        timeMax=start_of_next_day.isoformat(),
        singleEvents=True,
        orderBy="startTime",
    ).execute()

    events = response.get("items", [])

    for event in events:
        if event.get("summary") == title:
            return True

    return False


def parse_review_date(value):
    """Convert an Excel value into a date."""
    if isinstance(value, datetime):
        return value.date()

    return datetime.strptime(
        str(value).strip(),
        "%m/%d/%Y",
    ).date()


def main():
    # Load Excel workbook.
    workbook = openpyxl.load_workbook(
        EXCEL_FILE,
        data_only=True,
    )

    worksheet = workbook[SHEET_NAME]

    # Read header row.
    headers = {}

    for cell in worksheet[1]:
        if cell.value is not None:
            headers[str(cell.value).strip()] = cell.column

    required_columns = ["#", "name", "review session"]

    for column in required_columns:
        if column not in headers:
            raise ValueError(
                f"Missing required column: {column}"
            )

    # Connect to Google Calendar.
    service = get_calendar_service()

    timezone = ZoneInfo(TIMEZONE)
    today = datetime.now(timezone).date()

    created = 0
    skipped = 0
    skipped_past = 0

    for row in worksheet.iter_rows(min_row=2):
        number = row[headers["#"] - 1].value
        name = row[headers["name"] - 1].value
        review_session = row[headers["review session"] - 1].value

        # Skip incomplete rows.
        if number is None or name is None or review_session is None:
            continue

        # Convert Review Session to a date.
        review_date = parse_review_date(review_session)

        # Build event title.
        title = f"{number} {name}"

        # Ignore dates before today.
        if review_date < today:
            print(
                f"SKIPPED PAST: {title} - {review_date}"
            )
            skipped_past += 1
            continue

        # Check whether an event with the same title
        # already exists anywhere on this date.
        if event_already_exists(
            service,
            CALENDAR_ID,
            title,
            review_date,
        ):
            print(
                f"SKIPPED: {title} - "
                f"{review_date}"
            )
            skipped += 1
            continue

        # Create event at 21:00 Europe/Rome.
        start_datetime = datetime(
            year=review_date.year,
            month=review_date.month,
            day=review_date.day,
            hour=EVENT_HOUR,
            minute=EVENT_MINUTE,
            tzinfo=timezone,
        )

        end_datetime = start_datetime + timedelta(
            minutes=EVENT_DURATION_MINUTES
        )

        # Convert to RFC3339 strings.
        start_time = start_datetime.isoformat()
        end_time = end_datetime.isoformat()

        # Create event.
        event = {
            "summary": title,
            "start": {
                "dateTime": start_time,
                "timeZone": TIMEZONE,
            },
            "end": {
                "dateTime": end_time,
                "timeZone": TIMEZONE,
            },
            "colorId": EVENT_COLOR_ID,
        }

        service.events().insert(
            calendarId=CALENDAR_ID,
            body=event,
        ).execute()

        print(
            f"CREATED: {title} - "
            f"{review_date} 21:00"
        )

        created += 1

    print()
    print(
        f"Done. Created: {created}, "
        f"skipped: {skipped}, "
        f"past: {skipped_past}"
    )


if __name__ == "__main__":
    main()