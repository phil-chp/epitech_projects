
import { Request, Response, Router } from 'express';
// import { getAuth, signInWithEmailAndPassword } from 'firebase/auth';
import { CreateBoard, getBoardCards, getCard, getCardChanges, getAssignedCards } from '../services/trello';

const router: Router = Router();


router.post('/trello/board/create', async (req, res) => {
    try {
      const { Reaction, User, Data } = req.body;
      let board = await CreateBoard(Reaction, User, Data);
      console.log(board)
      res.status(200).send({ board: board });
    } catch (error : any) {
      // Return error
      res.status(401).json({ message: error.message });
    }
});


router.post('/trello/board/mods', async (req, res) => {
    try {
      const { Action, User } = req.body;
      let modifs = await getCardChanges(Action, User);
      console.log(modifs)
      res.status(200).send({ modifs: modifs });
    } catch (error : any) {
      // Return error
      res.status(401).json({ message: error.message });
    }
});


router.post('/trello/board/cards', async (req, res) => {
    try {
      const { Action, User } = req.body;
      let board = await getBoardCards(Action, User);
      console.log(board)
      res.status(200).send({ board: board });
    } catch (error : any) {
      // Return error
      res.status(401).json({ message: error.message });
    }
});

router.get('/trello/card', async (req, res) => {
  try {
    const { Action, User } = req.body;
    let card = await getCard(Action, User);
    console.log(card)
    res.status(200).send({ card: card });
  } catch (error : any) {
    // Return error
    res.status(401).json({ message: error.message });
  }
});

router.get('/trello/cards/assigned', async (req, res) => {
  try {
    const { Action, User } = req.body;
    let card = await getAssignedCards(Action, User);
    console.log(card)
    res.status(200).send({ card: card });
  } catch (error : any) {
    // Return error
    res.status(401).json({ message: error.message });
  }
});

export const TrelloService: Router = router;
