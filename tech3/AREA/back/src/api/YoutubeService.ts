import { Request, Response, Router } from 'express';
// import { getAuth, signInWithEmailAndPassword } from 'firebase/auth';
import { getMyLastVideoLikes, getMyLastVideoComments } from '../services/youtube';

const router: Router = Router();


router.post('/youtube/likes', async (req, res) => {
    try {
      const { Action, User } = req.body;
      let likes = await getMyLastVideoLikes(Action, User);
      console.log(likes)
      var message = null
      if (likes != 0)
        message = likes
      res.status(200).send({ message: message, data: message });
    } catch (error : any) {
      // Return error
      res.status(401).json({ message: error.message, data: null });
    }
});

router.post('/youtube/comments', async (req, res) => {
    try {
      const { Action, User } = req.body;
      let comments = await getMyLastVideoComments(Action, User);
      var message = null
      if (comments != 0)
        message = comments
      console.log(comments)
      res.status(200).send({ message: message, data: message });
    } catch (error : any) {
      // Return error
      res.status(401).json({ message: error.message, data: null });
    }
});

export const YoutubeService: Router = router;