import console = require('console');
import { Request, Response, Router } from 'express';
import { JsonObjectExpression, ListFormat } from 'typescript';
const router: Router = Router();

import { getActionsByService, getReactionsByService } from '../../services/firebase-admin';

import serviceList from '../../config/service-config';

router.get('/service/:id/actions', async (req, res) => {
    try {
        let Actions = await getActionsByService(req.params.id);
        res.status(200).send({ services: Actions });
    } catch (error) {
      res.status(401).send({ message: 'Error while getting Services Actions' });
    }
});

router.get('/service/:id/reactions', async (req, res) => {
    try {
        let Reactions = await getReactionsByService(req.params.id);
        res.status(200).send({ services: Reactions });
    } catch (error) {
        // Return error
      res.status(401).send({ message: 'Error while getting Services Reactions' });
    }
});

router.get('/service/:id', async (req, res) => {
    try {
        let actions = await getActionsByService(req.params.id);
        let reactions = await getReactionsByService(req.params.id);
        let Service = {
            Actions: actions,
            Reactions: reactions
        }
        res.status(200).send({ Service: Service });
    } catch (error) {
        // Return error
        res.status(401).send({ message: 'Error while getting Services' });
    }
});

router.get('/services', async (req, res) => {
    try {
        let services = [];
        for (let key in serviceList) {
            let service = {
                id: Number(key),
                name: serviceList[key as unknown as keyof typeof serviceList].service,
                icon: serviceList[key as unknown as keyof typeof serviceList].icon
            }
            services.push(service);
        }
        res.status(200).send({ Services: services });
    } catch (error) {
        // Return error
        res.status(401).send({ message: 'Error while getting Services' });
    }
});


export const Service: Router = router;
