import { Request, Response, Router } from 'express';
import { getAuth, signInWithEmailAndPassword } from 'firebase/auth';
import { firebase } from '../../services/firebase';

const router: Router = Router();


router.post('/login', async (req, res) => {
    try {
      const { email, password } = req.body;

      // Sign in user with Firebase Auth
      const user = await signInWithEmailAndPassword(getAuth(firebase), email, password);
      res.status(200).json(user);

    } catch (error : any) {
      // Return error
      res.status(401).json({ message: error.message });
    }
});

export const UserLoginExpress: Router = router;
