const express = require('express');
const cors = require('cors');
import * as bodyParser from 'body-parser';

import { HealthCheckExpress } from './api/HealthCheck';
import { UserRegisterExpress } from './api/Auth/RegisterUser';
import { UserLoginExpress } from './api/Auth/LoginUser';
import { UserLogoutExpress } from './api/Auth/LogoutUser';
import { RefreshToken } from './api/Auth/RefreshTokenUser';
import { VerifyToken } from './api/Auth/VerifyTokenUser';
import { Action } from './api/Firebase/Actions';
import { Reaction } from './api/Firebase/Reactions';
import { Service } from './api/Firebase/Service';
import { About } from './api/About';
import { User } from './api/User/User';
import { UserArea } from './api/User/Area';
import { UserService } from './api/User/Service';
import { GithubService } from './api/GithubService';
import { TrelloService } from './api/TrelloService';
import { GmailService } from './api/GmailService';
import { SpotifyService } from './api/SpotifyService';
import { CalendarService } from './api/CalendarService';
import { UserTrigger } from './api/User/Trigger';
import { GithubOAuth } from './api/Auth/GithubOauth';
import { SpotifyOAuth } from './api/Auth/SpotifyOauth';
import { TrelloOAuth } from './api/Auth/TrelloOauth';
import { GmailOAuth } from './api/Auth/GmailOauth';
import { CalendarOAuth } from './api/Auth/CalendarOauth';
import {YoutubeOAuth} from "./api/Auth/YoutubeOauth";
import { YoutubeService } from './api/YoutubeService';





// public init(app: express.Application){}
const app = express();
const swaggerUi = require('swagger-ui-express');
const swaggerDocument = require('./config/swagger-output.json');

const corsOption = {
    origin: '*',
};

app.use(bodyParser.json());
app.use('/api-docs', swaggerUi.serve, swaggerUi.setup(swaggerDocument));

app.use("/api", HealthCheckExpress)

// Auth //
app.use("/api", UserRegisterExpress)
app.use("/api", UserLoginExpress)
app.use("/api", UserLogoutExpress)
app.use("/api", RefreshToken)
app.use("/api", VerifyToken)
app.use("/api", GithubOAuth)
app.use("/api", SpotifyOAuth)
app.use("/api", TrelloOAuth)
app.use("/api", GmailOAuth)
app.use("/api", CalendarOAuth)
app.use("/api", YoutubeOAuth)

//  Services //
app.use("/api", GithubService)
app.use("/api", TrelloService)
app.use("/api", SpotifyService)
app.use("/api", CalendarService)
app.use("/api", YoutubeService)
app.use("/api", Action)
app.use("/api", Reaction)
app.use("/api", Service)

//  User //
app.use("/api", User)
app.use("/api", UserArea)
app.use("/api", UserService)
app.use("/api", UserTrigger)

app.use("/", About)


app.use(cors(corsOption));
app.use(cors())

app.listen(8080, () => {
    console.log('Server started on port 8080');
});
