
import { BACKEND_URL } from '../../config';
import { Request, Response, Router } from 'express';
const router: Router = Router();
const axios = require('axios')
const querystring = require('querystring');
const clientID = 'XXXXXXXXXXXX'
const clientSecret = 'XXXXXXXXXXXX'

var uid = "";

const encodeFormData = (data : any) => {
    return Object.keys(data)
      .map(key => encodeURIComponent(key) + '=' + encodeURIComponent(data[key]))
      .join('&');
}

const scope =
      `ugc-image-upload
      user-read-playback-state
      user-modify-playback-state
      user-read-currently-playing
      app-remote-control
      streaming
      playlist-read-private
      playlist-read-collaborative
      playlist-modify-private
      playlist-modify-public
      user-follow-modify
      user-follow-read
      user-read-playback-position
      user-top-read
      user-read-recently-played
      user-library-modify
      user-library-read
      user-read-email
      user-read-private`;

router.get('/auth/spotify', async (req, res) => {
    uid = req.query.uid as string;

    console.log("Spotify; uid", uid);
    res.redirect('https://accounts.spotify.com/authorize?' +
      querystring.stringify({
        response_type: 'code',
        client_id: clientID,
        scope: scope,
        redirect_uri: `${BACKEND_URL}/api/spotify/callback`
      })
    );
})

router.get('/spotify/callback', async (req, res) => {
    const requestToken = req.query.code
    console.log(requestToken);
    console.log("Spotify callback");
    const body = {
        grant_type: 'authorization_code',
        code: req.query.code,
        redirect_uri: `${BACKEND_URL}/api/spotify/callback`,
        client_id: clientID,
        client_secret: clientSecret,
    }
    console.log(body.redirect_uri);
    await fetch('https://accounts.spotify.com/api/token', {
        method: 'POST',
        headers: {
        "Content-Type": "application/x-www-form-urlencoded",
        "Accept": "application/json"
        },
        body: encodeFormData(body)
    }).then((response: any) => response.json())
    .then((data: any) => {
        console.log("data : ", data);

        axios({
          method: 'post',
          url: `${BACKEND_URL}/api/user/${uid}/service`,
          data: {
            name: "spotify",
            serviceId: 5,
            auth: {
              token: data.access_token,
              refresh_token: data.refresh_token,
              token_type: data.token_type
            }
          }
        }).then((response: any) => {
            console.log('close');
            res.send(`<script>window.close()</script>`);
        }).catch((error: any) => {
            console.log(error)
        })
    }).catch((error: any) => {
        console.log(error)
    })
})


export const SpotifyOAuth: Router = router;
