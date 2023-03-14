import { initializeApp } from 'firebase/app';

const firebase = initializeApp({
    apiKey: "XXXXXXXXXXXX",
    authDomain: "localhost",
    databaseURL: "https://area-default-rtdb.europe-west1.firebasedatabase.app/",
    projectId: "area",
    storageBucket: "gs://area.appspot.com",
    messagingSenderId: ""
});


export { firebase };
