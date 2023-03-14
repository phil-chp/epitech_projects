var YouTube = require('youtube-node');
import { youtube } from 'googleapis/build/src/apis/youtube';
import { getServiceFromUserInDB } from '../services/user'
var youTube = new YouTube();


var ServiceId = "7"

function initYoutube(UserAuth : any) {
    youTube.setKey(UserAuth.auth.APIKey);
}

function getVideoInfo(videoId : string) {
    youTube.getById(videoId, function(error: any, result: any) {
        if (error) {
            console.log(error);
        } else {
            console.log(JSON.stringify(result, null, 2));
        }
    });
}

function getVideoComments(videoId : string) {
    youTube.getCommentsForVideo(videoId, function(error: any, result: any) {
        if (error) {
            console.log(error);
        } else {
            console.log(JSON.stringify(result, null, 2));
        }
    });
}

function getMostPopularVideos(channelId : string) {
    youTube.getMostPopularVideosForChannel(channelId, 5, function(error: any, result: any) {
        if (error) {
            console.log(error);
        } else {
            console.log(JSON.stringify(result, null, 2));
        }
    });
}

function getChannelInfo(channelId : string) {
    youTube.getChannelById(channelId, function(error: any, result: any) {
        if (error) {
            console.log(error);
        } else {
            console.log(JSON.stringify(result, null, 2));
        }
    });
}

function getChannelVideos(channelId : string) {
    youTube.getPlaylistsByChannelId(channelId, 5, function(error: any, result: any) {
        if (error) {
            console.log(error);
        } else {
            console.log(JSON.stringify(result, null, 2));
        }
    });
}



function uploadVideo(videoPath : string, title : string, description : string) { // reaction
    youTube.upload(
        videoPath,
        {title: title, description: description},
        function(error: any, result: any) {
            if (error) {
            console.log(error);
            } else {
            console.log(JSON.stringify(result, null, 2));
            }
        }
    );
}


async function getMyLastVideoLikes(Action : any, user : any) {
    let UserAuthVal = await getServiceFromUserInDB(user.uid, ServiceId)
    const UserAuth = UserAuthVal.val();
    const url = `https://www.googleapis.com/youtube/v3/search?part=snippet&channelId=${UserAuth.auth.username}&order=date&maxResults=1&access_token=${UserAuth.auth.token}`;
    // console.log(url);
    const response = await fetch(url);
    const data = await response.json();
    console.log("toto=", data);
    
    const latestVideo = data.items[0];
    const videoId = latestVideo.id.videoId;
    const title = latestVideo.snippet.title;
    const description = latestVideo.snippet.description;
    const thumbnail = latestVideo.snippet.thumbnails.default.url;
    
    console.log(`Latest video: ${title} - ${description}`);
    console.log(`Thumbnail: ${thumbnail}`);
    console.log(`Link: https://www.youtube.com/watch?v=${videoId}`);
    // get the number of likes
    const url2 = `https://www.googleapis.com/youtube/v3/videos?part=statistics&id=${videoId}&access_token=${UserAuth.auth.token}`;
    const response2 = await fetch(url2);
    const data2 = await response2.json();
    console.log("toto2=", data2.items[0].statistics);
    const likes = data2.items[0].statistics.likeCount;
    console.log(`Likes: ${likes}`);
    if (likes > 0)
        return likes;
        
}

async function getMyLastVideoComments(Action : any, user : any) {
    let UserAuthVal = await getServiceFromUserInDB(user.uid, ServiceId)
    const UserAuth = UserAuthVal.val();
    const url = `https://www.googleapis.com/youtube/v3/search?part=snippet&channelId=${UserAuth.auth.username}&order=date&maxResults=1&access_token=${UserAuth.auth.token}`;
    // console.log(url);
    const response = await fetch(url);
    const data = await response.json();
    // console.log("toto=", data);
    
    const latestVideo = data.items[0];
    const videoId = latestVideo.id.videoId;
    const title = latestVideo.snippet.title;
    const description = latestVideo.snippet.description;
    const thumbnail = latestVideo.snippet.thumbnails.default.url;

    console.log(`Latest video: ${title} - ${description}`);
    console.log(`Thumbnail: ${thumbnail}`);
    console.log(`Link: https://www.youtube.com/watch?v=${videoId}`);
    // get the number of Comments
    const url2 = `https://www.googleapis.com/youtube/v3/videos?part=statistics&id=${videoId}&access_token=${UserAuth.auth.token}`;
    const response2 = await fetch(url2);
    const data2 = await response2.json();
    console.log("toto2=", data2.items[0].statistics);
    const comments = data2.items[0].statistics.commentCount;
    console.log(`Comments: ${comments}`);
    if (comments > 0) 
        return comments;
}


export {
    getChannelInfo,
    getChannelVideos,
    getMostPopularVideos,
    getVideoComments,
    getVideoInfo,
    initYoutube,
    uploadVideo,
    getMyLastVideoLikes,
    getMyLastVideoComments
}