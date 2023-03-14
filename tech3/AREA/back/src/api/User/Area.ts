import { Request, Response, Router } from 'express';
import { addAreaToUserInDB, getAllAreasFromUserInDB, getAreaFromUserInDB, updateAreaFromUserInDB, deleteAreaFromUserInDB } from '../../services/user';
import axios from 'axios';
import { BACKEND_URL } from '../../config';

const router: Router = Router();


router.post('/user/:id/area', async (req, res) => {
    try {
      const area = req.body;


        let areaId = await addAreaToUserInDB(req.params.id, area);
        let Trigger = {
            idAction: area.action.actionId,
            idArea: areaId,
            idReaction: area.reaction.reactionId,
            User: {
                uid: req.params.id
            }
        }
        axios.post(BACKEND_URL
            + '/api/user/' + req.params.id + '/trigger', Trigger)
        res.status(200).json({ message: 'Trigger created' });

    } catch (error : any) {
      // Return error
      res.status(401).json({ message: error.message });
    }
});

router.get('/user/:id/areas', async (req, res) => {
    try {
        const areas = await getAllAreasFromUserInDB(req.params.id);
        res.status(200).json({ areas: areas.val() });
    } catch (error : any) {
        res.status(401).json({ message: error.message });
    }
});

router.get('/user/:id/area/:areaId', async (req, res) => {
    try {
        const area = await getAreaFromUserInDB(req.params.id, req.params.areaId);
        res.status(200).json({ area: area.val() });
    } catch (error : any) {
        res.status(401).json({ message: error.message });
    }
});

router.put('/user/:id/area/:areaId', async (req, res) => {
    try {
        const area = req.body;
        await updateAreaFromUserInDB(req.params.id, req.params.areaId, area);
        let Trigger = {
            idAction: area.action.actionId,
            idArea: req.params.areaId,
            idReaction: area.reaction.reactionId,
            User: {
                uid: req.params.id
            }
        }

        axios.put(BACKEND_URL
         + '/api/user/' + req.params.id + '/trigger/' + req.params.areaId, Trigger)
        res.status(200).json({ message: 'Area '+ area.name +' updated successfully' });
    } catch (error : any) {
        res.status(401).json({ message: error.message });
    }
});

router.delete('/user/:id/area/:areaId', async (req, res) => {
    try {
        await deleteAreaFromUserInDB(req.params.id, req.params.areaId);

        axios.delete(BACKEND_URL
         + '/api/user/' + req.params.id + '/trigger/' + req.params.areaId)
        res.status(200).json({ message: 'Area '+ req.params.areaId +' deleted successfully' });

    } catch (error : any) {
        res.status(401).json({ message: error.message });
    }
});



export const UserArea: Router = router;
