import { Request, Response, Router } from 'express';
const router: Router = Router();

import { getAction, getActions } from '../../services/firebase-admin';

router.get('/actions', async (req, res) => {
    try {
      let Actions = await getActions();
      let ActionArray = [];
      for (let key in Actions) {
        ActionArray.push(Actions[key]);
      }

      res.status(200).send({ Actions: ActionArray });
    } catch (error) {
        // Return error
      res.status(401).send({ message: 'Error while getting actions' });
    }
});

router.get('/action/:id', async (req, res) => {
    try {
      let Action = await getAction(req.params.id);
      res.status(200).send({ Action: Action });
    } catch (error) {
        // Return error
      res.status(401).send({ message: 'Error while getting action' });
    }
});

export const Action: Router = router;
