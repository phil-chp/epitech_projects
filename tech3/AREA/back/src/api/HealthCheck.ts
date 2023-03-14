import { Request, Response, Router } from 'express';
const router: Router = Router();

router.get('/ping', (req: Request, res: Response) => {
    res.header("Access-Control-Allow-Methods", "GET, POST");
    res.header("Access-Control-Allow-Headers", "Origin, X-Requested-With, Content-Type, Accept");
    res.status(200).json({ message: "Version 1.2.0" });
})

export const HealthCheckExpress: Router = router;
