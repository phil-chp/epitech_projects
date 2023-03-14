import { Request, Response, Router } from 'express';
const router: Router = Router();
import axios from 'axios';
import { BACKEND_URL } from '../config';

import serviceList  from '../config/service-config';


interface Server {
    current_time: number,
    Services: Object
}

interface About {
    client: Object,
    server: Object
}

interface Service {
    name: string,
    actions: AREA [],
    reactions: AREA []
}

interface AREA {
    name: string,
    description: string,
}

function getServerTime() {
    let date = new Date();
    return Math.round(date.getTime() / 1000);
}

async function getService(id : string) {
    let servObj = await axios.get(`${BACKEND_URL}/api/service/` + id)
    .then((response) => {
        return response.data.Service;
    })
    .catch((error) => {
        console.log("action error: " + error);
    });

    return servObj;

}


async function buildService() {
    let services = [];

    for (let key in serviceList) {

        let service : any = await getService(key);

        let ActionObj = []
        let ReactionObj = []

        for (let i in service.Actions) {
            let actionObj : AREA = {
                name: service.Actions[i].name,
                description: service.Actions[i].description
            }
            ActionObj.push(actionObj);

        }
        for (let i in service.Reactions) {
            let reactionObj : AREA = {
                name: service.Reactions[i].name,
                description: service.Reactions[i].description
            }
            ReactionObj.push(reactionObj);
        }


        let serviceObj : Service = {
            name: serviceList[key as unknown as keyof typeof serviceList].service,
            actions: ActionObj,
            reactions: ReactionObj
        }
        services.push(serviceObj);
    }
    return services;
}


router.get('/about.json', async (req: Request, res: Response) => {
    try {
        let services = await buildService();
        let about : About = {
            client: {
                host: "172.20.0.7"
            },
            server: {
                current_time: getServerTime(),
                services: services
            }
        };
        res.status(200).send(about);
    } catch (error) {
        // Return error
        res.status(401).send({ message: 'Error while getting about' });
    }
})

export const About: Router = router;
