// import internal = require('stream');
// import * as TrelloNodeAPI from 'trello-node-api'
const TrelloNodeAPI = require('trello-node-api');
const moment = require('moment');
import { updateAction } from '../services/firebase-admin';
import { getServiceFromUserInDB } from '../services/user'


/* in DB:
    ----------------- setup
    APIKey : string
    OauthToken : string
    ----------------- runtime
    BoardID : string
    lastCheck : date (saves at register)
*/
const ServiceName = "Trello"
const ServiceId = "1"

function initTrello(UserAuth : any) {
    const trello = new TrelloNodeAPI()
    trello.setApiKey(UserAuth.APIKey)
    trello.setOauthToken(UserAuth.OauthToken)
    return trello
}

async function getCardsActions(trello : any, modifs : string[], len : number, lastCheck : string) {

    let actions = [];
    let action;

    for (var i = 0; i < len; ++i) {
        action = await trello.card.searchActions(modifs[i]);
        for (var j = 0; j < action.length; ++j) {
            // if (!viewAll && action.) //TODO: view que les actions qui me concernent
            if (action[j].date < lastCheck) {
                break;
            }
            actions.push(action[j]);
        }
    }
    console.log(actions)
    return actions
}

async function getCardChanges(Action : any, User : any) {
    let UserAuthVal = await getServiceFromUserInDB(User.uid, ServiceId)
    const UserAuth = UserAuthVal.val();
    const trello = initTrello(UserAuth.auth);

    let board : string = Action.BoardID
    let lastCheck = Action.lastCheck
    let cards;
    let len : number = 0;
    let modifs : string[] = [];

    const today = new Date();
    Action.lastCheck = today.toISOString();
    await updateAction(Action.id, Action);

    try {
        // boards = await trello.action.searchActions();
        cards = await trello.board.searchCards(board);
    } catch (error) {
        if (error) {
            console.log('error ', error)
        }
    }

    for (var i = 0; i < cards.length; ++i) {
        if (cards[i].dateLastActivity < lastCheck) {
            len = modifs.push(cards[i].id);
        }
    }

    if (len === 0) {
        return {message: 'No updates on your cards', data: null};
    }

    let actions = await getCardsActions(trello, modifs, len, lastCheck)
    if (actions.length === 0) {
        return {message: 'No updates on your cards', data: null};
    }

    return ({message: actions.length + ' modifications on your board, please check it out', data: actions});
}

/* in DB:
    ----------------- create
    name : string
    description : string
    idOrganization : string
    idBoardSource : string
    background : string (Color)
*/

async function CreateBoard(Reaction : any, User : any, Data : any) {
    let UserAuthVal = await getServiceFromUserInDB(User.uid, ServiceId)
    const UserAuth = UserAuthVal.val();
    const trello = initTrello(UserAuth.auth);
    let data = {
        name: 'TEST1',
        // name: Data.name,
        defaultLabels: false,
        defaultLists: false,
        desc: 'simple board created for testing',
        // desc: Data.description,
        idOrganization: Reaction.idOrganization,
        idBoardSource: Reaction.idBoardSource,
        keepFromSource: 'none',
        powerups: 'all',
        prefs_permissionLevel: 'private',
        prefs_voting: 'disabled',
        prefs_comment: 'members',
        prefs_invitations: 'members',
        prefs_selfJoin: true,
        prefs_cardCovers: true,
        // prefs_background: 'blue',
        prefs_background: Reaction.background,
        prefs_cardAging: 'regular'
    };
    let response;
    try {
        response = await trello.board.create(data);
    } catch (error) {
        if (error) {
            console.log('error ', error);
        }
        return {message: 'error, could not create board, got error: [' + error.message + ']', data : null};
    }
    return{message : "created board ["/*' TODO: + Data.name*/ + "].", data : response};
}

async function getAllCardsName(trello : any, data : any) {
    let i = 0;
    let cardID : string;
    let response;
    for (; data[i] !== null; ++i) {
        console.log(data[i].name)
        cardID = data[i].id;
        return await trello.card.searchActions(cardID) //TODO: get all cards name
    }
}

async function getBoardCards(Action : any, User : any) {
    let UserAuthVal = await getServiceFromUserInDB(User.uid, ServiceId)
    const UserAuth = UserAuthVal.val();

    const trello = initTrello(UserAuth.auth);

    let response;
    try {
        response = await trello.board.searchCards('');
        console.log(response)
    } catch (error) {
        if (error) {
            console.log('error ', error)
        }
    };
    // return await getAllCardsName(trello, response);
    return response;

}

async function getCard(Action : any, User : any) {
    let UserAuthVal = await getServiceFromUserInDB(User.uid, ServiceId)
    const UserAuth = UserAuthVal.val();
    const trello = initTrello(UserAuth.auth);

    let response;
    try {
        response = await trello.card.search('');
    } catch (error) {
        if (error) {
            console.log('error ', error)
        }
    }
    return response

}

async function getAssignedCards(Action : any, user : any) {
    let UserAuthVal = await getServiceFromUserInDB(user.uid, ServiceId)
    const UserAuth = UserAuthVal.val();
    const trello = initTrello(UserAuth.auth);

   let lastCheck = Action.lastCheck;
   const today = new Date();
   Action.lastCheck = today.toISOString();
   await updateAction(Action.id, Action);

   let newCards : any[] = []
    trello.getCardsForMember('me', {
        fields: 'name,idList,desc,due',
        actions: 'commentCard',
        members: true,
        member_fields: 'username',
        since: moment(lastCheck).toISOString()
      }, (err : any, cards : any) => {
        if (err) {
          console.error(err);
          return;
        }

        // Log the cards to the console
        newCards.push(cards);
      });
    if (newCards.length === 0) {
        return {res : false, message: 'No updates on your cards', data: null};
    }
    return ({res : true, message: newCards.length + ' modifications on your board, please check it out', data: newCards});
}
export { CreateBoard, getBoardCards, getCard, getCardChanges, getAssignedCards };
