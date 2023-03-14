import { Request, Response, Router } from 'express';
const router: Router = Router();

import { firebaseAdmin } from '../../services/firebase-admin';
import { getAuth, signInWithEmailAndPassword, signInWithCustomToken } from 'firebase/auth';
import { firebase } from '../../services/firebase';
import axios from 'axios';
import { refreshToken } from 'firebase-admin/app';

const API_KEY = 'XXXXXXXXXXXX';

const refreshAccessToken = async (idToken : String) => {
  try {
    const response = await axios.post(
      `https://securetoken.googleapis.com/v1/token?key=${API_KEY}`,
      {
        grant_type: 'refresh_token',
        refresh_token: idToken,
      },
      {
        headers: {
          'Content-Type': 'application/x-www-form-urlencoded',
        },
      }
    );

    return response.data;
  } catch (error) {
    console.error(error);
  }
};



router.post('/refresh_token', async (req, res) => {
    // Get the access token from the request (remove the 'Bearer ' prefix)
    const idToken = req.headers.authorization?.slice(7);
    if (!idToken) {
        res.status(401).send({ message: 'Missing Authorization token or token format incorrect' });
        return;
    }
    try {
        const response = await refreshAccessToken(idToken);
        res.status(200).send(response);

    } catch (error) {
        // Send an error response
        res.status(401).send({ message: 'Invalid or expired token.' });
    }
});

export const RefreshToken: Router = router;
