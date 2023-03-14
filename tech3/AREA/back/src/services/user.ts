import { firebaseAdmin } from './firebase-admin';

//                                                  Users                                              //

function createUserInDB(user: any) {
    firebaseAdmin.database().ref('Users/user-' + user.uid).set(user);
}

function deleteUserFromDB(userId: String) {
    firebaseAdmin.database().ref('Users/user-' + userId).remove();
}

function getUserFromDB(userId: string) {
    return firebaseAdmin.database().ref('Users/user-' + userId).once('value');
}

function updateUserInDB(id: string, user: any) {
    firebaseAdmin.database().ref('Users/user-' + id).update(user);
}

function getAllUsersFromDB() {
    return firebaseAdmin.database().ref('Users').once('value');
}

//                                                  Areas                                              //                           

function addAreaToUserInDB(userId: string, area: any) {
    const ref = firebaseAdmin.database().ref('Users/user-' + userId + '/Areas').push();
    ref.set({
        ...area,
        'areaId': ref.key
    });
    return ref.key;
}

function deleteAreaFromUserInDB(userId: string, areaId: string) {
    firebaseAdmin.database().ref('Users/user-' + userId + '/Areas/' + areaId).remove();
}

function updateAreaFromUserInDB(userId: string, areaId: string, area: any) {
    firebaseAdmin.database().ref('Users/user-' + userId + '/Areas/' + areaId).update(area);
}

function getAreaFromUserInDB(userId: string, areaId: string) {
    return firebaseAdmin.database().ref('Users/user-' + userId + '/Areas/' + areaId).once('value');
}

function getAllAreasFromUserInDB(userId: string) {
    return firebaseAdmin.database().ref('Users/user-' + userId + '/Areas').once('value');
}

//                                                  Service                                              //

function getAllServiceFomUserInDB(userId: string) {
    return firebaseAdmin.database().ref('Users/user-' + userId + '/Service').once('value');
}

function getServiceFromUserInDB(userId: string, serviceId: string) {
    return firebaseAdmin.database().ref('Users/user-' + userId + '/Service/service-' + serviceId).once('value');
}

function addServiceToUserInDB(userId: string, service: any) {
    firebaseAdmin.database().ref('Users/user-' + userId + '/Service/service-' + service.serviceId).set(service);
}

function deleteServiceFromUserInDB(userId: string, serviceId: string) {
    firebaseAdmin.database().ref('Users/user-' + userId + '/Service/service-' + serviceId).remove();
}

function updateServiceFromUserInDB(userId: string, serviceId: string, service: any) {
    firebaseAdmin.database().ref('Users/user-' + userId + '/Service/service-' + serviceId).update(service);
}


//                                                  Trigger                                              //


function addTriggerToUserInDB(userId: string, trigger: any, id: string) {
    const ref = firebaseAdmin.database().ref('Users/user-' + userId + '/Triggers/'+ id).set(trigger);
    // ref.set({
    //     ...trigger,
    //     'triggerId': id
    // });
    // return ref.key;
}

function deleteTriggerFromUserInDB(userId: string, triggerId: string) {
    firebaseAdmin.database().ref('Users/user-' + userId + '/Triggers/' + triggerId).remove();
}

function updateTriggerFromUserInDB(userId: string, triggerId: string, trigger: any) {
    firebaseAdmin.database().ref('Users/user-' + userId + '/Triggers/' + triggerId).update(trigger);
}

function getTriggerFromUserInDB(userId: string, triggerId: string) {
    return firebaseAdmin.database().ref('Users/user-' + userId + '/Triggers/' + triggerId).once('value');
}

function getAllTriggersFromUserInDB(userId: string) {
    return firebaseAdmin.database().ref('Users/user-' + userId + '/Triggers').once('value');
}

export {
    createUserInDB,
    deleteUserFromDB,
    updateUserInDB,
    getUserFromDB,
    getAllUsersFromDB,
    addAreaToUserInDB,
    deleteAreaFromUserInDB,
    updateAreaFromUserInDB,
    getAreaFromUserInDB,
    getAllAreasFromUserInDB,
    getAllServiceFomUserInDB,
    getServiceFromUserInDB,
    addServiceToUserInDB,
    deleteServiceFromUserInDB,
    updateServiceFromUserInDB,
    addTriggerToUserInDB,
    deleteTriggerFromUserInDB,
    updateTriggerFromUserInDB,
    getTriggerFromUserInDB,
    getAllTriggersFromUserInDB
};