var SpotifyWebApi = require('spotify-web-api-node')

import { firebaseAdmin, updateAction } from '../services/firebase-admin';
import { getServiceFromUserInDB } from '../services/user'

const ServiceName = "Spotify"
const ServiceId = "5"


function initSpotify(UserAuth : any) {
   console.log(UserAuth);
   var spotify = new SpotifyWebApi();
   spotify.setAccessToken(UserAuth.token)
   return spotify
}

async function getMyInfos(Action : any, user : any) {
    let UserAuthVal = await getServiceFromUserInDB(user.uid, ServiceId)
    const UserAuth = UserAuthVal.val();
    const spotify = initSpotify(UserAuth.auth);

    spotify.getMe()
    .then(function(data :any) {
        console.log('Some information about the authenticated user', data.body);
    }, function(err : any) {
        console.log('Something went wrong!', err);
    });
}

async function getUserInfos(Action : any, user : any) {
    let UserAuthVal = await getServiceFromUserInDB(user.uid, ServiceId)
    const UserAuth = UserAuthVal.val();
    const spotify = initSpotify(UserAuth.auth);

    spotify.getUser(Action.username)
    .then(function(data :any) {
        console.log('Some information about this user', data.body);
    }, function(err : any) {
        console.log('Something went wrong!', err);
    });
}

async function getArtistAlbums(spotify : any, artistId : any) {
    // let UserAuthVal = await getServiceFromUserInDB(user.uid, ServiceId)
    // const UserAuth = UserAuthVal.val();
    // const spotify = initSpotify(UserAuth.auth);
    let res;
    await spotify.getArtistAlbums(artistId)
    .then(function(data : any) {
        // 'This user is following 1051 artists!'
        res = data.body;
    }, function(err : any) {
        console.log('Something went wrong!', err);
    });
    return res
}

async function getFollowedArtists(spotify : any) {
    // let UserAuthVal = await getServiceFromUserInDB(user.uid, ServiceId)
    // const UserAuth = UserAuthVal.val();
    // const spotify = initSpotify(UserAuth.auth);
    let res;

    await spotify.getFollowedArtists({ limit : 10 })
      .then(function(data : any) {
          // 'This user is following 1051 artists!'
         res = data.body.artists;
      }, function(err : any) {
        console.log('Something went wrong!', err);
      });
      return res
}

async function getRandomTrack(spotify : any) {
    // generate a random number between 0 and 10000
    const randomNumber = Math.floor(Math.random() * 10000);

    let songId;

    // search for a random song using the generated number as the query
    spotify.searchTracks(`track:${randomNumber}`, { limit: 1 })
      .then(function(data : any) {
        songId = data.body.tracks.items[0].id;
        console.log('Random song ID:', songId);
      }, function(err : any) {
        console.log('Error searching for song:', err);
      });
    return songId;
}

async function getPlaybackState(spotify : any) {
    spotify.getMyCurrentPlaybackState()
    .then(function(data : any) {
        if (data.body && data.body.is_playing) {
            return (data.body && data.body.is_playing)
        }
    }, function(err : any) {
        console.log('Something went wrong!', err);
        return false;
    });
    return false

}

async function setVolume(spotify : any, volume : number) {
    spotify.setVolume(volume)
      .then(function () {
        console.log('Setting volume to 90.');
        }, function(err : any) {
        console.log('Something went wrong!', err);
      });

}
// async function getCategories(Action: any, user : any) {
//     let UserAuthVal = await getServiceFromUserInDB(user.uid, ServiceId)
//     const UserAuth = UserAuthVal.val();
//     const spotify = initSpotify(UserAuth.auth);

//     spotify.getCategories({
//         limit : 5,
//         offset: 0,
//         country: 'FR',
//         locale: 'sv_SE'
//     })
//     .then(function(data : any) {
//       console.log(data.body);
//     }, function(err : any) {
//       console.log("Something went wrong!", err);
//     });
// }


//-------------------------------------Actions------------------------------
async function checkNewAlbums(Action : any, user : any) {

    let UserAuthVal = await getServiceFromUserInDB(user.uid, ServiceId)
    const UserAuth = UserAuthVal.val();
    const spotify = initSpotify(UserAuth.auth);


    const today = new Date();
    today.toISOString().split('T')
    let lastCheck = Action.lastCheck;
    Action.lastCheck = today;
    await updateAction(Action.id, Action);

    const artists : any = await getFollowedArtists(spotify)
    let newAlbums : any[] = []

    for (let i = 0; i < artists.items.length && i < 10; ++i) {
        let albums : any = await getArtistAlbums(spotify, artists.items[i].id);
        let j = 0;
        const artist = artists.items[i];
        while (j < albums.items.length && albums.items[j].album_type == 'album' && albums.items[j].release_date > Action.lastCheck) {
            const name = albums.items[j].name;
            const id = albums.items[j].id;
            newAlbums.push({name, id, artist})
            j++;
        }
    }

    if (newAlbums.length == 0) {
        return {message: "No new albums detected.", data : null };
    }
    return ({message: newAlbums.length + " new albums detected.", data: newAlbums});
}

async function checkNewSingle(Action : any, user : any) {

    let UserAuthVal = await getServiceFromUserInDB(user.uid, ServiceId)
    const UserAuth = UserAuthVal.val();
    const spotify = initSpotify(UserAuth.auth);

    const today = new Date();
    today.toISOString().split('T')
    let lastCheck = Action.lastCheck;
    Action.lastCheck = today;
    await updateAction(Action.id, Action);

    const artists : any = await getFollowedArtists(spotify)
    let newSingles : any[] = []

    for (let i = 0; i < artists.items.length && i < 10; ++i) {
        let singles : any = await getArtistAlbums(spotify, artists.items[i].id);

        let j = 0;
        const artist = artists.items[i];
        while (j < singles.items.length && singles.items[j].album_type == 'album') {
            j++;
        }
        while (j < singles.items.length && singles.items[j].album_type == 'single' && singles.items[j].release_date > Action.lastCheck) {
            const name = singles.items[j].name;
            const id = singles.items[j].id;
            newSingles.push({name, id, artist})
            j++;
        }
    }
    if (newSingles.length == 0) {
        return {message: "No new single detected.", data : null };
    }
    return ({message: newSingles.length + " new singles detected.", data: newSingles});
}


//-----------------------------------Reactions------------------------------
async function addSingleToLibrary(Reaction : any, user : any) {
    let UserAuthVal = await getServiceFromUserInDB(user.uid, ServiceId)
    const UserAuth = UserAuthVal.val();
    const spotify = initSpotify(UserAuth.auth);

    console.log("adding ?")
    spotify.addToMySavedTracks([Reaction.track]).then(function(data : any) {
        console.log("added", data)
        return ({message: "Added track!", data: data});
    }, function(err : any) {
        console.log("error")
        return {message: "Error adding single.", err: err };
    });
}

async function addRandomSingleToLibrary(Reaction : any, user : any) {
    let UserAuthVal = await getServiceFromUserInDB(user.uid, ServiceId)
    const UserAuth = UserAuthVal.val();
    const spotify = initSpotify(UserAuth.auth);

    console.log("adding ?")
    const songId = await getRandomTrack(spotify);
    spotify.addToMySavedTracks([songId]).then(function(data : any) {
        console.log("added", data)
        return ({message: "Added track!", data: data});
    }, function(err : any) {
        console.log("error")
        return {message: "Error adding single.", err: err };
    });
}

async function addAlbumToLibrary(Reaction : any, user : any) {
    let UserAuthVal = await getServiceFromUserInDB(user.uid, ServiceId)
    const UserAuth = UserAuthVal.val();
    const spotify = initSpotify(UserAuth.auth);
    console.log("adding ?")
    spotify.addToMySavedAlbums([Reaction.album]).then(function(data : any) {
    console.log("added")
    return ({message: "Added album!", data: data});
    }, function(err : any) {
    console.log("error")
    return {message: "Error adding album.", err: err };
    });
}

async function stopPlaying(Reaction : any, user : any) {
    let UserAuthVal = await getServiceFromUserInDB(user.uid, ServiceId)
    const UserAuth = UserAuthVal.val();
    const spotify = initSpotify(UserAuth.auth);

    const playing = await getPlaybackState(spotify);
    // if (playing == false) {
    //     return ({message: "player isn't active", data: "good"});
    // }
    spotify.pause()
    .then(function() {
        setVolume(spotify, 10);
        return ({message: "Stopped Playing!", data: "get to work"});
    }, function(err : any) {
        //if the user making the request is non-premium, a 403 FORBIDDEN response code will be returned
        return ({message: "user must have spotify premium to use this reaction", data: "403 FORBIDEN"});
    });
}

async function startPlaying(Reaction : any, user : any) {
    let UserAuthVal = await getServiceFromUserInDB(user.uid, ServiceId)
    const UserAuth = UserAuthVal.val();
    const spotify = initSpotify(UserAuth.auth);

    const playing = await getPlaybackState(spotify);
    if (playing) {
        setVolume(spotify, 90);
        return ({message: "player is already active", data: "keep vibing"});
    }
    spotify.play()
    .then(function() {
        setVolume(spotify, 90);
        return ({message: "Started Playing!", data: "yoohoo"});
    }, function(err : any) {
        //if the user making the request is non-premium, a 403 FORBIDDEN response code will be returned
        return ({message: "user must have spotify premium to use this reaction", data: "403 FORBIDEN"});
    });
}

async function skipNext(Reaction : any, user : any) {
    let UserAuthVal = await getServiceFromUserInDB(user.uid, ServiceId)
    const UserAuth = UserAuthVal.val();
    const spotify = initSpotify(UserAuth.auth);

    spotify.skipToNext()
    .then(function() {
        setVolume(spotify, 90);
        return ({message: "Started Playing!", data: "yoohoo"});
    }, function(err : any) {
        //if the user making the request is non-premium, a 403 FORBIDDEN response code will be returned
        return ({message: "user must have spotify premium to use this reaction", data: "403 FORBIDEN"});
    });
}

async function skipPrev(Reaction : any, user : any) {
    let UserAuthVal = await getServiceFromUserInDB(user.uid, ServiceId)
    const UserAuth = UserAuthVal.val();
    const spotify = initSpotify(UserAuth.auth);

    spotify.skipToPrevious()
    .then(function() {
        setVolume(spotify, 90);
        return ({message: "Started Playing!", data: "yoohoo"});
    }, function(err : any) {
        //if the user making the request is non-premium, a 403 FORBIDDEN response code will be returned
        return ({message: "user must have spotify premium to use this reaction", data: "403 FORBIDEN"});
    });
}

export { startPlaying, stopPlaying, addAlbumToLibrary, addSingleToLibrary, addRandomSingleToLibrary, checkNewSingle, checkNewAlbums, skipNext, skipPrev };
