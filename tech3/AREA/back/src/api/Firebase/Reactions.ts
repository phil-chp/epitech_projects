import { Request, Response, Router } from 'express';
const router: Router = Router();

import { getReaction, getReactions } from '../../services/firebase-admin';

router.get('/reactions', async (req, res) => {
    try {
      let Reactions = await getReactions();
      let ReactionArray = [];
      for (let key in Reactions) {
        ReactionArray.push(Reactions[key]);
      }
      res.status(200).send({ Reactions: ReactionArray });
    } catch (error) {
        // Return error
      res.status(401).send({ message: 'Error while getting Reactions' });
    }
});

router.get('/reaction/:id', async (req, res) => {
    try {
      let Reaction = await getReaction(req.params.id);
      res.status(200).send({ Reaction: Reaction });
    } catch (error) {
        // Return error
      res.status(401).send({ message: 'Error while getting Reaction' });
    }
});

export const Reaction: Router = router;