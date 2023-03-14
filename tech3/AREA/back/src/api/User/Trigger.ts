import { Request, Response, Router } from 'express';
import { createScriptTrigger } from '../../services/trigger';

import { addTriggerToUserInDB,
    deleteTriggerFromUserInDB,
    updateTriggerFromUserInDB,
    getTriggerFromUserInDB,
    getAllTriggersFromUserInDB} from '../../services/user';

import { firebaseAdmin, getAction, getReaction } from '../../services/firebase-admin';

const router: Router = Router();

const delayTrigger = 1;

router.post('/user/:id/trigger', async (req, res) => {
    try {
        const { User, idAction, idReaction, idArea } = req.body;
        let Action = await getAction(idAction);
        let Reaction = await getReaction(idReaction);

        let trigger = {
            idAction: idAction,
            idReaction: idReaction,
            idArea: idArea,
            user: User,
            nbTimesTriggered: 0,
            lastTriggered: "Never",
            status: 1,
            createdAt: new Date().toISOString(),
            triggerId: idArea,
            delayExecution: delayTrigger
        };
        await addTriggerToUserInDB(req.params.id, trigger, idArea);

        await createScriptTrigger(Action, Reaction, User, idArea);
        res.status(200).json({ message: "Trigger created" });
        // res.status(200).json(action);
    } catch (error : any) {
        // Return error
        res.status(401).json({ message: error.message });
    }
});

router.get('/user/:id/triggers', async (req, res) => {
    try {
        const triggers = await getAllTriggersFromUserInDB(req.params.id);
        res.status(200).json({ triggers: triggers.val() });
    } catch (error : any) {
        res.status(401).json({ message: error.message });
    }
});

router.get('/user/:id/trigger/:triggerId', async (req, res) => {
    try {
        const trigger = await getTriggerFromUserInDB(req.params.id, req.params.triggerId);
        res.status(200).json({ trigger: trigger.val() });
    } catch (error : any) {
        res.status(401).json({ message: error.message });
    }
});

router.put('/user/:id/trigger/:triggerId', async (req, res) => {
    try {
        const trigger = req.body;
        await updateTriggerFromUserInDB(req.params.id, req.params.triggerId, trigger);
        res.status(200).json({ message: 'Trigger '+ trigger.triggerId +' updated successfully' });
    } catch (error : any) {
        res.status(401).json({ message: error.message });
    }
});

router.delete('/user/:id/trigger/:triggerId', async (req, res) => {
    try {
        await deleteTriggerFromUserInDB(req.params.id, req.params.triggerId);
        res.status(200).json({ message: 'Trigger '+ req.params.triggerId +' deleted successfully' });
    } catch (error : any) {
        res.status(401).json({ message: error.message });
    }
});

//                                                  Utils                                               //

router.get('/user/:id/trigger/:triggerId/status', async (req, res) => {
    try {
        const trigger = await getTriggerFromUserInDB(req.params.id, req.params.triggerId);
        res.status(200).json({ status: trigger.val().status });
    } catch (error : any) {
        res.status(401).json({ message: error.message });
    }
});

router.put('/user/:id/trigger/:triggerId/status', async (req, res) => {
    try {
        const {status} = req.body;
        const trigger = await getTriggerFromUserInDB(req.params.id, req.params.triggerId);
        const newTrigger = trigger.val();
        newTrigger.status = status;
        await updateTriggerFromUserInDB(req.params.id, req.params.triggerId, newTrigger);
        res.status(200).json({ message: 'Trigger '+ newTrigger.triggerId +' updated successfully' });
    } catch (error : any) {
        res.status(401).json({ message: error.message });
    }
});

router.post('/user/:id/trigger/:triggerId/execute', async (req, res) => {
    try {
        const trigger = await getTriggerFromUserInDB(req.params.id, req.params.triggerId);
        const newTrigger = trigger.val();
        newTrigger.status = 1;
        newTrigger.nbTimesTriggered += 1;
        newTrigger.lastTriggered = new Date().toISOString();
        await updateTriggerFromUserInDB(req.params.id, req.params.triggerId, newTrigger);
        res.status(200).json({ message: 'Trigger '+ newTrigger.triggerId +' executed successfully' });
    } catch (error : any) {
        res.status(401).json({ message: error.message });
    }
});


export const UserTrigger: Router = router;
