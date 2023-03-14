import axios from 'axios';
const cron = require('node-cron');
import { BACKEND_URL } from '../config';

function createScriptTrigger(Action: any, Reaction: any, User: any, triggerId : String) {
    console.log("created trigger!!!!");
    let task = cron.schedule('*/1 * * * *', async () => { // run every minute
        let ActionBody = { User, Action };
        console.log(ActionBody);
        await axios.get(BACKEND_URL
         + "/api/user/" + User.uid + "/trigger/" + triggerId + "/status")
            .then((response) => {
                if (response.data.status === 2) { // 0 = waiting, 1 = running, 2 = cancelled
                    console.log("task cancelled");
                    task.stop();
                }
            })
            .catch((error) => {
                console.log("error status: " + error);
                return;
            });

        console.log(`Trigger API call: ${BACKEND_URL}${Action.url}`);
        await axios.post(`${BACKEND_URL}${Action.url}`, ActionBody)
            .then(async (response) => {
                console.log("action response: " + response.data.message);

                if (response.data.data !== undefined) {
                    await axios.post(BACKEND_URL
                        + "/api/user/" + User.uid + "/trigger/" + triggerId + "/execute")
                    var url = `${BACKEND_URL}${Reaction.url}`;
                    console.log(`Reaction API call: ${url}`);
                    console.log("reaction body: " + response.data.data);
                    let ReactionBody = { User, Reaction, data: response.data.data };
                    await axios.post(`${url}`, ReactionBody)
                        .then((response) => {
                            console.log("reaction response: " + response.data);
                        })
                        .catch((error) => {
                            console.log("reaction error: " + error);
                        });
                }
                else {
                    console.log("no reaction");
                }
            })
            .catch((error) => {
                console.log("action error: " + error);
            });

        console.log('running a task every minute');
    });
    return task;
}



export { createScriptTrigger };
