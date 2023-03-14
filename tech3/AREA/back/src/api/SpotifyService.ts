
import { Request, Response, Router } from 'express';
import { startPlaying, stopPlaying, addAlbumToLibrary, addSingleToLibrary, checkNewSingle, checkNewAlbums, skipNext, skipPrev  } from '../services/spotify';

const router: Router = Router();

//-------------------------------------Actions------------------------------

router.post('/spotify/albums/new', async (req: any, res: any) => {
    try {
      // const repos = req.body;
      const { Action, User } = req.body;
      let albums = await checkNewAlbums(Action, User);
      res.status(200).send({ info: albums });
    } catch (error : any) {
      // Return error
      res.status(401).json({ message: error.message });
    }
});

router.post('/spotify/singles/new', async (req: any, res: any) => {
    try {
      // const repos = req.body;
      const { Action, User } = req.body;
      let singles = await checkNewSingle(Action, User);
      res.status(200).send({ info: singles });
    } catch (error : any) {
      // Return error
      res.status(401).json({ message: error.message });
    }
});

//-----------------------------------Reactions------------------------------

router.post('/spotify/singles/add', async (req: any, res: any) => {
  try {
    // const repos = req.body;
    const { Action, User } = req.body;
    let singles = await addSingleToLibrary(Action, User);
    res.status(200).send({ info: singles });
  } catch (error : any) {
    // Return error
    res.status(401).json({ message: error.message });
  }
});

router.post('/spotify/albums/add', async (req: any, res: any) => {
  try {
    // const repos = req.body;
    const { Action, User } = req.body;
    let singles = await addAlbumToLibrary(Action, User);
    res.status(200).send({ info: singles });
  } catch (error : any) {
    // Return error
    res.status(401).json({ message: error.message });
  }
});

router.post('/spotify/start', async (req: any, res: any) => {
  try {
    // const repos = req.body;
    const { Action, User } = req.body;
    let singles = await startPlaying(Action, User);
    res.status(200).send({ info: singles });
  } catch (error : any) {
    // Return error
    res.status(401).json({ message: error.message });
  }
});

router.post('/spotify/stop', async (req: any, res: any) => {
  try {
    // const repos = req.body;
    const { Action, User } = req.body;
    let singles = await stopPlaying(Action, User);
    res.status(200).send({ info: singles });
  } catch (error : any) {
    // Return error
    res.status(401).json({ message: error.message });
  }
});

router.post('/spotify/next', async (req: any, res: any) => {
  try {
    // const repos = req.body;
    const { Action, User } = req.body;
    let singles = await skipNext(Action, User);
    res.status(200).send({ info: singles });
  } catch (error : any) {
    // Return error
    res.status(401).json({ message: error.message });
  }
});

router.post('/spotify/prev', async (req: any, res: any) => {
  try {
    // const repos = req.body;
    const { Action, User } = req.body;
    let singles = await skipPrev(Action, User);
    res.status(200).send({ info: singles });
  } catch (error : any) {
    // Return error
    res.status(401).json({ message: error.message });
  }
});

export const SpotifyService: Router = router;
