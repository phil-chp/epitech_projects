
import { Request, Response, Router } from 'express';
// import { getAuth, signInWithEmailAndPassword } from 'firebase/auth';
import { getNewThreads, getNewMails, checkForSpotifyOrder } from '../services/gmail';

const router: Router = Router();


router.post('/gmail/spotify/order', async (req: any, res: any) => {
  try {
    const { Action, User } = req.body;
    let mails = await checkForSpotifyOrder(Action, User);
    console.log(mails)
    res.status(200).send({ mail: mails });
  } catch (error : any) {
    res.status(401).json({ message: error.message });
  }
});

router.post('/gmail/mails/new', async (req: any, res: any) => {
  try {
    const { Action, User } = req.body;
    let mails = await getNewMails(Action, User);
    console.log(mails)
    res.status(200).send({ mail: mails });
  } catch (error : any) {
    res.status(401).json({ message: error.message });
  }
});

 router.post('/gmail/threads/new', async (req: any, res: any) => {
   try {
     const { Action, User } = req.body;
     let thread = await getNewThreads(Action, User);
     console.log(thread)
     res.status(200).send({ thread: thread });
   } catch (error : any) {
     res.status(401).json({ message: error.message });
   }
 });

export const GmailService: Router = router;
