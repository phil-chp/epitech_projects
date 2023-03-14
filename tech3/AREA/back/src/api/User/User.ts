import { Request, Response, Router } from 'express';
import { createUserInDB, getAllUsersFromDB, updateUserInDB, getUserFromDB, deleteUserFromDB } from '../../services/user';

const router: Router = Router();


router.post('/user', async (req, res) => {
    try {
      const user = req.body;


      await createUserInDB(user);
      res.status(200).json({ message: 'User '+ user.uid +' created successfully' });

    } catch (error : any) {
      // Return error
      res.status(401).json({ message: error.message });
    }
});


router.get('/users', async (req, res) => {
    try {
        const users = await getAllUsersFromDB();
        res.status(200).json({ users: users.val() });
    } catch (error : any) {
        res.status(401).json({ message: error.message });
    }
});

router.get('/user/:id', async (req, res) => {
    try {
        const user = await getUserFromDB(req.params.id);
        res.status(200).json({ user: user.val() });
    } catch (error : any) {
        res.status(401).json({ message: error.message });
    }
});


router.put('/user/:id', async (req, res) => {
    try {
        const user = req.body;
        await updateUserInDB(req.params.id, user);
        res.status(200).json({ message: 'User '+ user.uid +' updated successfully' });
    } catch (error : any) {
        res.status(401).json({ message: error.message });
    }
});


router.delete('/user/:id', async (req, res) => {
    try {
        await deleteUserFromDB(req.params.id);
        res.status(200).json({ message: 'User '+ req.params.id +' deleted successfully' });
    } catch (error : any) {
        res.status(401).json({ message: error.message });
    }
});

export const User: Router = router;
