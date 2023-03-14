const { google } = require('googleapis');
import { BACKEND_URL } from '../../config';
import { Request, Response, Router } from 'express';
const axios = require('axios')
const router: Router = Router();
const session = require('express-session');

const CLIENT_ID = 'XXXXXXXXXXXX.apps.googleusercontent.com';
const CLIENT_SECRET = 'XXXXXXXXXXXX';
const REDIRECT_URI = `${BACKEND_URL}/api/auth/calendar/callback`;

const oAuth2Client = new google.auth.OAuth2(
  CLIENT_ID,
  CLIENT_SECRET,
  REDIRECT_URI
);

var uid = "";


router.get('/auth/calendar', (req, res) => {
    uid = req.query.uid as string;
    console.log("uid", uid);
    const authUrl = oAuth2Client.generateAuthUrl({
        access_type: 'offline',
        scope: ['https://www.googleapis.com/auth/calendar.events'],
    });
    res.redirect(authUrl);
});

router.get('/auth/calendar/callback', async (req, res) => {
  const code = req.query.code;

  try {
    const { tokens } = await oAuth2Client.getToken(code);
    oAuth2Client.setCredentials(tokens);
    console.log(tokens);
    axios({
        method: 'post',
        url: `${BACKEND_URL}/api/user/${uid}/service`,
        data: {
          name: "calendar",
          serviceId: 6,
          auth: {
            token: tokens.access_token,
          }
        }
      }).then((response: any) => {
        res.send(`<script>window.close()</script>`);
      }).catch((error: any) => {
        console.log(error)
      }
    )

  } catch (err) {
    console.error('Error retrieving access token', err);
  }
});


export const CalendarOAuth: Router = router;
