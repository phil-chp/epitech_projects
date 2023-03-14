
import { Request, Response, Router } from 'express';
import { getTodayEvent, getEvent, addEventToday } from '../services/calendar';

const router: Router = Router();

router.post('/calendar/event/today', async (req: any, res: any) => {
    try {
      const { Action, User } = req.body;
      let events = await getTodayEvent(Action, User);
      console.log(events)
      res.status(200).send({ event: events });
    } catch (error : any) {
      res.status(401).json({ message: error.message });
    }
});

router.post('/calendar/event', async (req: any, res: any) => {
  try {
   //  const eventId = "placeholder"
    const { Action, User } = req.body;
    let event = await getEvent(Action, User);
    console.log(event)
    res.status(200).send({ event: event });
  } catch (error : any) {
    res.status(401).json({ message: error.message });
  }
});

router.post('/calendar/create/today', async (req: any, res: any) => {
  try {
   //  const eventId = "placeholder"
    const { Action, User, data } = req.body;
    let event = await addEventToday(Action, User);
    console.log(event)
    res.status(200).send({ event: event });
  } catch (error : any) {
    res.status(401).json({ message: error.message });
  }
});

export const CalendarService: Router = router;
