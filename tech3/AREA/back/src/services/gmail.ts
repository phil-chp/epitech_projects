var Gmail = require('node-gmail-api');


import { firebaseAdmin, updateAction } from './firebase-admin';
import { getServiceFromUserInDB } from '../services/user'

const ServiceName = "Gmail"
const ServiceId = "4"

function initGmail(UserAuth : any) {
   const gmail = new Gmail(
      UserAuth.token //oAUth token
   );
   return gmail
}

function getBody(payload : any) {
    const body = payload.parts.find((part : any) => part.mimeType === 'text/plain' && !part.filename);
    if (body) {
      return body.body.data ? Buffer.from(body.body.data, 'base64').toString() : '';
    } else if (payload.parts) {
      return payload.parts.map((part : any) => getBody(part)).join('\n');
    }
    return '';
  }

async function getXMails(gmail : any, x : number) {
    var mails = gmail.messages('label:inbox', {fields: ['id', 'internalDate', 'labelIds', 'Payload'], max: x});//format : full/minimal/raw/metadata
    var res : any[];
    mails.on('data', function (d : any) {
        console.log(d.minimal);
        res.push(d.minimal);
    })
    return res;
}

function getXThreads(gmail : any, x : number) {
    var mails = gmail.threads('label:inbox', {max: x});
    var res : any[];
    mails.on('data', function (d : any) {
        console.log(d);
        res.push(d);
    })
    return res;
}

async function getNewMails(Action : any, User : any) {
    let UserAuthVal = await getServiceFromUserInDB(User.uid, ServiceId)
    const UserAuth = UserAuthVal.val();
 
    const gmail = initGmail(UserAuth.auth);
    let lastCheck = Action.lastCheck.toISOString().split('T')[0];
    const today = new Date();
    Action.lastCheck = today.toISOString().split('T')[0];
    await updateAction(Action.id, Action);
    const query = `is:unread after:${lastCheck}`;
    let newMessages : any[] = [];
    gmail.users.messages.list({ userId: 'me', q: query }, (err : any, res : any) => {
    if (err) return console.log(`The API returned an error: ${err}`);
    const messages = res.data.messages;
    
    if (!messages || messages.length === 0) {
        console.log('No unread messages found.');
    } else {
        messages.forEach((message : any) => {
        gmail.users.messages.get({ userId: 'me', id: message.id }, (err : any, res : any) => {
            if (err) return console.log(`The API returned an error: ${err}`);
            const messageData = res.data;
            const headers = messageData.payload.headers;
            const subject = headers.find((header : any) => header.name === 'Subject').value;
            const snippet = messageData.snippet;
            newMessages.push({subject: subject, snippet: snippet});
        });
        });
    }
    });
    return newMessages;
}

async function checkForSpotifyOrder(Action : any, User : any) {
    let UserAuthVal = await getServiceFromUserInDB(User.uid, ServiceId)
    const UserAuth = UserAuthVal.val();
 
    const gmail = initGmail(UserAuth.auth);
    let lastCheck = Action.lastCheck.toISOString().split('T')[0];
    const today = new Date();
    Action.lastCheck = today.toISOString().split('T')[0];
    await updateAction(Action.id, Action);
    
    const query = `is:unread subject:"AREA-Spotify"`;

    let order : any[] = [];
    gmail.users.messages.list({ userId: 'me', q: query }, (err : any, res : any) => {
        if (err) return console.log(`The API returned an error: ${err}`);
        const messages = res.data.messages;
      
        if (!messages || messages.length === 0) {
          console.log('No new messages with "AREA-Spotify" in the subject found.');
        } else {
          console.log(`Found ${messages.length} new messages with "AREA-Spotify" in the subject:`);
          messages.forEach((message : any) => {
            gmail.users.messages.get({ userId: 'me', id: message.id }, (err : any, res : any) => {
              if (err) return console.log(`The API returned an error: ${err}`);
              const messageData = res.data;
              const headers = messageData.payload.headers;
              const subject = headers.find((header : any) => header.name === 'Subject').value;
              const snippet = messageData.snippet;
              const body = getBody(messageData.payload);
              order.push({subject: subject, snippet: snippet, body: body});
            });
          });
        }
      });
    if (order.length === 0) {
    return ({res : false, data: null});
    }
    return {res : true, data: order};
}

async function getNewThreads(Action : any, User : any) {
    let UserAuthVal = await getServiceFromUserInDB(User.uid, ServiceId)
    const UserAuth = UserAuthVal.val();
 
    const gmail = initGmail(UserAuth.auth);
    let lastCheck = Action.lastCheck;
    let newThreads = [];
    let len : number = 0;
 
    const today = new Date();
    Action.lastCheck = today.toISOString();
    await updateAction(Action.id, Action);
    
    let threads = await getXThreads(gmail, 99);
    var i = 0;
    while (i < threads.length && threads[i].updated_at > lastCheck) {
        len = newThreads.push(threads[i]);
        i++;
    }
    if (len === 0) {
       return {message: "No new mail detected.", data : null };
    }
    return {message: len + "new mail(s) detected.", data : newThreads}
}


export { getNewThreads, getNewMails, checkForSpotifyOrder };