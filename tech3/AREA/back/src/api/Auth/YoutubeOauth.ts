const { google } = require('googleapis');
import { BACKEND_URL } from '../../config';
import { Request, Response, Router } from 'express';
const axios = require('axios')
const router: Router = Router();
const session = require('express-session');

const CLIENT_ID = 'XXXXXXXXXXXX.apps.googleusercontent.com';
const CLIENT_SECRET = 'XXXXXXXXXXXX';
const REDIRECT_URI = `${BACKEND_URL}/api/auth/Youtube/callback`;

const oAuth2Client = new google.auth.OAuth2(
  CLIENT_ID,
  CLIENT_SECRET,
  REDIRECT_URI
);

const SCOPES = ['https://www.googleapis.com/auth/youtube.readonly'];
var uid = "";


router.use(
  session({
    secret: 'secret_key',
    resave: false,
    saveUninitialized: true,
    cookie: {
      secure: true,
      httpOnly: true,
      maxAge: 60 * 60 * 1000, // 1 hour
    },
  })
);

router.get('/auth/Youtube', (req, res) => {
    uid = req.query.uid as string;
    console.log("uid", uid);
    const authUrl = oAuth2Client.generateAuthUrl({
        access_type: 'offline',
        scope: SCOPES,
    });
    res.redirect(authUrl);
});

router.get('/auth/Youtube/callback', async (req, res) => {
  const code = req.query.code;
  var user = "";
  try {
    const { tokens } = await oAuth2Client.getToken(code);
    oAuth2Client.setCredentials(tokens);
    console.log(tokens);
    axios.get('https://www.googleapis.com/youtube/v3/channels?part=id&mine=true', {
      headers: {
        'Authorization': `Bearer ${tokens.access_token}`
      }
    })
    .then((response: any) => {
      user = response.data.items[0].id;
      console.log("user", user);
      axios({
        method: 'post',
        url: `${BACKEND_URL}/api/user/${uid}/service`,
        data: {
          name: "Youtube",
          serviceId: 7,
          auth: {
            username: user,
            APIKey: CLIENT_ID,
            token: tokens.access_token,
          }
        }
      }).then((response: any) => {
        res.send(`<script>window.close()</script>`);
      }).catch((error: any) => {
        console.log(error)
      }
    )
    })
    .catch((error: any) => {
      console.log(error);
    });

  } catch (err) {
    console.error('Error retrieving access token', err);
  }
});


export const YoutubeOAuth: Router = router;
