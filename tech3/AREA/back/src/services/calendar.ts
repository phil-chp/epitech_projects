const {google} = require('googleapis');

import { firebaseAdmin, updateAction } from './firebase-admin';
import { getServiceFromUserInDB } from '../services/user'
const moment = require('moment');

const ServiceName = "Calendar"
const ServiceId = "6"

// event exemple
// const event = {
//     'summary': 'Google I/O 2015',
//     'location': '800 Howard St., San Francisco, CA 94103',
//     'description': 'A chance to hear more about Google\'s developer products.',
//     'start': {
//       'dateTime': '2015-05-28T09:00:00-07:00',
//       'timeZone': 'America/Los_Angeles',
//     },
//     'end': {
//       'dateTime': '2015-05-28T17:00:00-07:00',
//       'timeZone': 'America/Los_Angeles',
//     },
//     'recurrence': [
//       'RRULE:FREQ=DAILY;COUNT=2'
//     ],
//     'attendees': [
//       {'email': 'lpage@example.com'},
//       {'email': 'sbrin@example.com'},
//     ],
//     'reminders': {
//       'useDefault': false,
//       'overrides': [
//         {'method': 'email', 'minutes': 24 * 60},
//         {'method': 'popup', 'minutes': 10},
//       ],
//     },
//   };

async function initCalendar(UserAuth : any) {
    const token  = UserAuth.token
    const calendar = await google.calendar({
        version: 'v3',
        token
    });
    return calendar
 }
 
async function addEvent(calendar : any, event : any) {
    await calendar.events.insert({
        calendarId: 'primary',
        ressource: event,
    }, function(err : any, event : any) {
        if (err) {
            console.log('There was an error contacting the Calendar service: ' + err)
        }
        console.log('Event created: %s', event.htmlLink);
    });
}

// Acquire an auth client, and bind it to all future calls
// const authClient = await auth.getClient();
// google.options({auth: authClient});

async function getEvent(action : any, user : any) {
    let UserAuthVal = await getServiceFromUserInDB(user.uid, ServiceId)
    const UserAuth = UserAuthVal.val();
    const calendar = await initCalendar(UserAuth.auth)
    const res = await calendar.events.get({
      // Deprecated and ignored. A value will always be returned in the email field for the organizer, creator and attendees, even if no real email address is available (i.e. a generated, non-working value will be provided).
      alwaysIncludeEmail: 'placeholder-value',
      // Calendar identifier. To retrieve calendar IDs call the calendarList.list method. If you want to access the primary calendar of the currently logged in user, use the "primary" keyword.
      calendarId: 'primary',
      // Event identifier.
      eventId: action.eventId,
      // The maximum number of attendees to include in the response. If there are more than the specified number of attendees, only the participant is returned. Optional.
      maxAttendees: 10,
      // Time zone used in the response. Optional. The default is the time zone of the calendar.
    });
    console.log(res.data);
}

async function getTodayEvent(action : any, user : any) {
    const now = new Date();
    const startOfDay = new Date(now.getUTCFullYear(), now.getUTCMonth(), now.getUTCDate());
    const endOfDay = new Date(startOfDay.getTime() + 24 * 60 * 60 * 1000);
    var beginning = Date.now()//.format("YYYY-MM-DDT23:59:00Z") TODO: format
    var end = beginning + 1
    let UserAuthVal = await getServiceFromUserInDB(user.uid, ServiceId)
    const UserAuth = UserAuthVal.val();
    const calendar = await initCalendar(UserAuth.auth)
    var res : any[] = [];
    await calendar.events.list({
        calendarId: 'primary',
        timeMin: startOfDay.toISOString(),
        timeMax: endOfDay.toISOString(),
        singleEvents: true,
        orderBy: 'startTime'
      }, (err : any, res : any) => {
        if (err) return console.log(`The API returned an error: ${err}`);
        const events = res.data.items;
        if (!events || events.length === 0) {
          console.log('No events found for today.');
        } else {
          console.log(`Upcoming events for today (${startOfDay.toLocaleDateString()}):`);
          events.forEach((event : any) => {
            const start = event.start.dateTime || event.start.date;
            res.push({start: start, summary: event.summary});
          });
        }
      });
    if (res.length === 0) {
        return {res: false, data : null}
    }
    return {res: true, data : res}
}


//-------------------------------------
async function addEventToday(Action : any, user : any) {
    const start = moment().set({hour: 18, minute: 0, second: 0});
    const end = moment().set({hour: 19, minute: 0, second: 0});

    // Create the event resource
    const event = {
      summary: "area-generated",
      start: {
        dateTime: start.toISOString()
      },
      end: {
        dateTime: end.toISOString()
      }
    };

    // Create the event using the Google Calendar API
    let UserAuthVal = await getServiceFromUserInDB(user.uid, ServiceId)
    const UserAuth = UserAuthVal.val();
    const calendar = await initCalendar(UserAuth.auth)
    const response = await calendar.events.insert({
      calendarId: 'primary',
      resource: event
    });

    console.log(`Event created: ${response.data.htmlLink}`);
    return response.data
}

export { getTodayEvent, getEvent, addEventToday };
