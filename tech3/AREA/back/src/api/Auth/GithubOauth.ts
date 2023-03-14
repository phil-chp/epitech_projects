// index.js
import { BACKEND_URL } from '../../config';
import { Request, Response, Router } from 'express';
const router: Router = Router();
// Import the axios library, to make HTTP requests
const axios = require('axios')
// This is the client ID and client secret that you obtained
// while registering on github app
const clientID = 'XXXXXXXXXXXX'
const clientSecret = 'XXXXXXXXXXXX'

var uid = "";

// Declare the callback route

router.get('/auth/github', async (req, res) => {
  uid = req.query.uid as string;
  console.log("uid", uid);
  res.redirect(`https://github.com/login/oauth/authorize?client_id=${clientID}`);
});

router.get('/github/callback', async (req, res) => {

  // The req.query object has the query params that were sent to this route.
  const requestToken = req.query.code
  console.log(requestToken);

  axios({
    method: 'post',
    url: `https://github.com/login/oauth/access_token?client_id=${clientID}&client_secret=${clientSecret}&code=${requestToken}`,
    // Set the content type header, so that we get the response in JSON
    headers: {
         accept: 'application/json'
    }
  }).then((response: any) => {

    axios({
      method: 'post',
      url: `${BACKEND_URL}/api/user/${uid}/service`,
      data: {
        name: "github",
        serviceId: 2,
        auth: {
          token: response.data.access_token,
        }
      }
    }).then((response: any) => {
      res.send(`<script>window.close()</script>`);
    }).catch((error: any) => {
      console.log(error)
    }
    )

    // res.redirect('/api/success');
  })
})

// router.get('/success', function(req, res) {


// });

export const GithubOAuth: Router = router;
