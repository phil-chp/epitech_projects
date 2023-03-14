
import { Request, Response, Router } from 'express';
import { getNewRepos, getUpdatedRepos, createRepo, getNewCommits } from '../services/github';

const router: Router = Router();


router.post('/github/repo/create', async (req: any, res: any) => {
  try {
    // const repos = req.body;
    const { Action, User } = req.body;
    let repos = await createRepo(Action, User);
    console.log(repos)
    res.status(200).send({ repo: repos });
  } catch (error : any) {
    // Return error
    res.status(401).json({ message: error.message });
  }
});

router.post('/github/commits/new', async (req: any, res: any) => {
  try {
    // const repos = req.body;
    const { Action, User } = req.body;
    let repos = await getNewCommits(Action, User);
    console.log(repos)
    res.status(200).send({ repo: repos });
  } catch (error : any) {
    // Return error
    res.status(401).json({ message: error.message });
  }
});

router.post('/github/repos', async (req: any, res: any) => {
    try {
      // const repos = req.body;
      const { Action, User } = req.body;
      let repos = await getNewRepos(Action, User);
      console.log(repos)
      res.status(200).send({ repo: repos });
    } catch (error : any) {
      // Return error
      res.status(401).json({ message: error.message });
    }
});

 router.post('/github/update', async (req: any, res: any) => {
   try {
     // const repos = req.body;
     const { Action, User } = req.body;
     let repos = await getUpdatedRepos(Action, User);
     console.log(repos)
     res.status(200).send({ repo: repos });
   } catch (error : any) {
     // Return error
     res.status(401).json({ message: error.message });
   }
 });

export const GithubService: Router = router;
