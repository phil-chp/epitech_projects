import { Request, Response, Router } from 'express';
const router: Router = Router();

import { firebaseAdmin } from '../../services/firebase-admin';

router.post('/logout', async (req, res) => {
    const idToken = req.headers.authorization?.slice(7);
    if (!idToken) {
        res.status(401).send({ message: 'Missing Authorization token or token format incorrect' });
        return;
    }
    try {
      // Verify the ID token and decode its claims
      const decodedIdToken = await firebaseAdmin.auth().verifyIdToken(idToken);
  
      // Get the user ID from the decoded ID token
      const userId = decodedIdToken.uid;
  
      // Revoke the ID token
      await firebaseAdmin.auth().revokeRefreshTokens(userId);
  
      // Send a success response
      res.status(200).send({ message: 'Successfully logged out.' });
    } catch (error) {
      // Send an error response
      res.status(401).send({ message: 'Invalid or expired ID token.' });
    }
});

export const UserLogoutExpress: Router = router;