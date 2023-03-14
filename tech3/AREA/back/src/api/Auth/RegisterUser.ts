import { Request, Response, Router } from 'express';
const router: Router = Router();

import { firebaseAdmin } from '../../services/firebase-admin';

router.post('/register', async (req, res) => {
    try {
        const { email, password } = req.body;
        const user = await firebaseAdmin.auth().createUser({
            email,
            password
        });

        res.status(200).json({ message: 'User registered successfully', user });
    } catch (error : any) {
        res.status(500).json({ message: error.message });
    }
});

router.post('/register/google', async (req, res) => {
    try {
        const { email, password } = req.body;

        // TODO: Oauth
        const user = await firebaseAdmin.auth().createUser({
            email,
            password
        });

        res.status(200).json({ message: 'User registered successfully', user });
    } catch (error : any) {
        res.status(500).json({ message: error.message });
    }
});

export const UserRegisterExpress: Router = router;
