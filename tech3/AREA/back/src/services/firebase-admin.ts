import console = require('console');
import * as firebase from 'firebase-admin';
const serviceAccount = require('../config/area-admin.json');

const firebaseAdmin = firebase.initializeApp({
  credential: firebase.credential.cert(serviceAccount),
  databaseURL: 'https://area-default-rtdb.europe-west1.firebasedatabase.app/'
});

function getAction(idAction: string) {
  return firebaseAdmin.database().ref('/Action/Action-' + idAction).once('value').then(function (snapshot) {
      return snapshot.val();
  });
}

function getReaction(idReaction: string) {
  return firebaseAdmin.database().ref('/Reaction/Reaction-' + idReaction).once('value').then(function (snapshot) {
      return snapshot.val();
  });
}

// function getAuthUser(serviceId : string, userId: string) {

//   return firebaseAdmin.database().ref('/Users/user-' + userId + '/Auth/service-' + serviceId).once('value').then(function (snapshot) {
//       return snapshot.val();
//   });
// }

function getActions() {
  return firebaseAdmin.database().ref('/Action').once('value').then(function (snapshot) {
      return snapshot.val();
  });
}

function getActionsByService(serviceId: string) {
  let Actions : {[key: string]: any} = {};
  let Act = firebaseAdmin.database().ref('/Action').once('value').then(function (snapshot) {
      snapshot.forEach(function(childSnapshot) {
        if (childSnapshot.val().serviceId === parseInt(serviceId)) {
          Actions[`action-${childSnapshot.val().id}`] = childSnapshot.val();
        }
      });
      return Actions;
    });
  return Act;
}

function getReactionsByService(serviceId: string) {
  let Reactions : {[key: string]: any} = {};
  let React = firebaseAdmin.database().ref('/Reaction').once('value').then(function (snapshot) {
      snapshot.forEach(function(childSnapshot) {
        if (childSnapshot.val().serviceId === parseInt(serviceId)) {
          Reactions[`action-${childSnapshot.val().id}`] = childSnapshot.val();
        }
      });
      return Reactions;
    });
  return React;
}

function getReactions() {
  return firebaseAdmin.database().ref('/Reaction').once('value').then(function (snapshot) {
      return snapshot.val();
  });
}

//                                      Update                                         //

function updateAction(idAction: string, data: any) {
  firebaseAdmin.database().ref('/Action/Action-' + idAction).update(data);
}

function updateReaction(idReaction: string, data: any) {
  firebaseAdmin.database().ref('/Reaction/Reaction-' + idReaction).update(data);
}

export { firebaseAdmin, getAction, getReaction, updateAction, getActions, getReactions, updateReaction, getActionsByService, getReactionsByService };
