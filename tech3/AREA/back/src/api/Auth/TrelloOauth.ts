// index.js
import { BACKEND_URL } from '../../config';
import console = require('console');
import { Request, Response, Router } from 'express';
const router: Router = Router();
const url = require('url');

// Import the axios library, to make HTTP requests
const axios = require('axios')
// This is the client ID and client secret that you obtained
// while registering on github app
const APIKEY = 'XXXXXXXXXXXX'
const clientSecret = 'XXXXXXXXXXXX'

var uid = "";
var tokenSS = "";

const express = require('express');
const oauth = require('oauth');
const bodyParser = require('body-parser');


router.use(bodyParser.json());

const trelloOAuth = new oauth.OAuth(
  'https://trello.com/1/OAuthGetRequestToken',
  'https://trello.com/1/OAuthGetAccessToken',
  APIKEY,
  clientSecret,
  '1.0A',
  `${BACKEND_URL}/api/auth/trello/callback`,
  'HMAC-SHA1'
);

router.get('/auth/trello', (req, res) => {
  uid = req.query.uid as string;
  trelloOAuth.getOAuthRequestToken((error: any, token: string, tokenSecret: any) => {
    if (error) {
      console.log('Error getting OAuth request token:', error);
      res.sendStatus(500);
    } else {
      tokenSS = tokenSecret;
      const authUrl = `https://trello.com/1/OAuthAuthorizeToken?oauth_token=${token}&name=[YOUR APP NAME]&scope=read,write`;
      console.log(authUrl);
      res.redirect(authUrl);
    }
  });
});

router.get('/auth/trello/callback', (req, res) => {
  const token = req.query.oauth_token;
  const verifier = req.query.oauth_verifier;
  console.log("token", token);
  console.log("verifier", verifier);
  console.log("tokenSecret", tokenSS);
  // var token2 = ""

  trelloOAuth.getOAuthAccessToken(token, tokenSS, verifier, (error: any, accessToken: string, accessTokenSecret: string) => {
    if (error) {
      console.log('Error getting OAuth access token:', error);
      res.sendStatus(500);
    } else {
      // Use the accessToken and accessTokenSecret to make API calls on behalf of the user
      console.log('Access token:', accessToken);
      console.log('Access token secret:', accessTokenSecret);

      axios({
        method: 'post',
        url: `http://localhost:8080/api/user/${uid}/service`,
        data: {
          name: "trello",
          serviceId: 1,
          auth: {
            APIKey: APIKEY,
            OauthToken: accessToken
          }
        }
      }).then((response: any) => {
        res.send(`<script>window.close()</script>`);
      }).catch((error: any) => {
        console.log(error)
      }
      )
    }
  });
});

// router.get('/success', function(req, res) {


// });

export const TrelloOAuth: Router = router;
