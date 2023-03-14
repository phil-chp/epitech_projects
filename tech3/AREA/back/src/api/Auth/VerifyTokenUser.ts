import { Request, Response, Router } from 'express';
const router: Router = Router();

import { firebaseAdmin } from '../../services/firebase-admin';

router.post('/verify_token', async (req, res) => {
  const idToken = req.headers.authorization?.slice(7);
  if (!idToken) {
    res.status(401).send({ message: 'Missing Authorization token or token format incorrect' });
    return;
  }
    try {
      // Verify the ID token and decode its claims
      await firebaseAdmin.auth().verifyIdToken(idToken);
      // Send a success response
      res.status(200).send({ message: 'ID token is valid.' });
    } catch (error) {
      // Send an error response
      res.status(401).send({ message: 'Invalid or expired ID token.' });
    }
});

export const VerifyToken: Router = router;