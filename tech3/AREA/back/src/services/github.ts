var GitHub = require('github-api');
const { Octokit } = require('@octokit/rest');

import { firebaseAdmin, updateAction } from '../services/firebase-admin';
import { getServiceFromUserInDB } from '../services/user'

const ServiceName = "Github"
const ServiceId = "2"


function initGithub(UserAuth : any) {
   console.log(UserAuth);
   var github = new GitHub({
      token: UserAuth.token
   });
   return github
}
function initOctokit(UserAuth : any) {
   var octokit = new Octokit({
      token: UserAuth.token
   });
   return octokit
}

async function checkPush( octokit : any, repoOwner : String, repoName: String, baseBranch : String, headBranch : String) {
  try {
    const { data } = await octokit.repos.compareCommits({
      owner: repoOwner,
      repo: repoName,
      base: baseBranch,
      head: headBranch
    });
    if (data.commits.length > 0) {
      console.log(`A push has been made to ${headBranch} branch of ${repoOwner}/${repoName} repository.`);
      return {res : true, data: data.commits};
    } else {
      console.log(`No push has been made to ${headBranch} branch of ${repoOwner}/${repoName} repository.`);
      return {res : false, data: null};
    }
  } catch (error) {
    console.error(`Error occurred while checking push: ${error}`);
      return {res : false, data: null};
  }
}

async function ListRepo(github : any, username : string = null) {
   var me = await github.getUser(username); // no user specified defaults to the user for whom credentials were provided
   console.log(me);
   let repos = await me.listRepos();
   return repos;
}

async function ListOrgRepo(github : any, Orga : string) {
   var org = await github.getOrganization(Orga); // no user specified defaults to the user for whom credentials were provided
   let repos = await org.listRepos();
   return repos;
}



//--------------------------------Actions--------------------------------

async function getNewRepos(Action : any, User : any) {
   let UserAuthVal = await getServiceFromUserInDB(User.uid, ServiceId)
   const UserAuth = UserAuthVal.val();
   const github = initGithub(UserAuth.auth);
   let lastCheck = Action.lastCheck;
   let newRepos = [];
   let len : number = 0;

   const today = new Date();
   Action.lastCheck = today.toISOString();
   await updateAction(Action.id, Action);

   let repos = await ListRepo(github, UserAuth.auth.username);
   for (var i = 0; i < repos.data.length; ++i) {
      if (repos.data[i].created_at > lastCheck) {
         len = newRepos.push(repos.data[i]);
      }
   }
   if (len === 0) {
      return {message: "No new repository detected.", data : null };
   }
   return {message: len + " new repo(s) detected.", data : newRepos}
}

async function getUpdatedRepos(Action : any, User : any) {
   let UserAuthVal = await getServiceFromUserInDB(User.uid, ServiceId)
   const UserAuth = UserAuthVal.val();

   const github = initGithub(UserAuth.auth);
   let newRepos = [];
   let len : number = 0;

   let lastCheck = Action.lastCheck;
   const today = new Date();
   Action.lastCheck = today.toISOString();
   await updateAction(Action.id, Action);

   let repos = await ListRepo(github);
   for (var i = 0; i < repos.data.length; ++i) {
      if (repos.data[i].updated_at > lastCheck) {
         len = newRepos.push(repos.data[i]);
      }
   }
   if (len === 0) {
      return {message: "No updated repository detected.", data : null };
   }
   return {message: len + " updated repo(s) detected.", data : newRepos}
}

async function getNewCommits(Action : any, User : any) {
   let UserAuthVal = await getServiceFromUserInDB(User.uid, ServiceId)
   const UserAuth = UserAuthVal.val();
   const github = initGithub(UserAuth.auth);
   const octokit = initOctokit(UserAuth.auth);

   let lastCheck = Action.lastCheck;
   const today = new Date();
   Action.lastCheck = today.toISOString();
   await updateAction(Action.id, Action);

   const repos = await ListRepo(github)
   if (repos.data.length == 0) {
      return {res: false, data: null}
   }
   let newCommits : any[]= []
   for (var i = 0; i < repos.data.length; i++) {
      let owner = repos.data[i].fullname.plit("/")[0]
      let repo = repos.data[i].fullname.plit("/")[1]
      const commits = await octokit.repos.listCommits({
         owner,
         repo,
         since: lastCheck,
       });
      for (var j = 0; j < commits.data.length; j++) {
         newCommits.push(commits.data[j])
      }
   }
   if (newCommits.length  == 0) {
      return {res: false, data: null}
   }
   return {res: true, data: newCommits}

}

//--------------------------------Reactions--------------------------------
async function createRepo(Action : any, User : any) {
   let UserAuthVal = await getServiceFromUserInDB(User.uid, ServiceId)
   const UserAuth = UserAuthVal.val();
   const github = initGithub(UserAuth.auth);
   const octokit = initOctokit(UserAuth.auth);

   const randomNumber = Math.floor(Math.random() * 10000);

   const repoName = `Area_generated_repo-${randomNumber}`;
   const repoDescription = "This is a test repository created using the GitHub API in the AREA project";
   const repoVisibility = "private";

   octokit.repos.createForAuthenticatedUser({
      name: repoName,
      description: repoDescription,
      private: (repoVisibility === "private"),
    }).then((response : any) => {
      console.log(`Successfully created repository ${response.data.name}`);
    }).catch((error : any) => {
      console.error(`Error creating repository: ${error.message}`);
    });
}

export { getNewRepos, getUpdatedRepos, createRepo, getNewCommits };
