<div align="right"><i>By Adrian Lorenzi, Quentin Rouvier, Ugo Lena, Philippe Cheype - Epitech Nice - 2023</i></div>
<h1>AREA</h1>

<tr><img align="right" src="./front/android/app/src/main/ic_launcher-playstore.png" alt="AREA" height="200"></tr>
</tr>

Welcome to the AREA project!

<div align="justify">
AREA stands for <b>A</b>ction & <b>REA</b>ction. You will find <b>Services</b> that you can subscribe to like Github, Trello, ... Those services come with actions that trigger reactions. For example:

Gitub action: "New issue created" -> Gmail reaction: "Send an email to someone"

You will be able to access the web application via [http://<HOST_IP>:8081/](http://<HOST_IP>:8081/). You can then choose to download the APK and access the mobile application.
</div>

## Technical documentations

<details>
  <summary>About.json</summary>
  </br>
  This file contains all the information about the API's Services and their related Actions and Reactions.

  ```
https://<HOST_IP>:8080/about.json
  ```
</details>

<details>
  <summary>Swagger</summary>
  </br>
  This is a web interface that allows you to test the API's endpoints.

  ```
https://<HOST_IP>:8080/api-docs
  ```
</details>

<details>
  <summary>How to add a module</summary>
  </br>
  This documentation explains how to create your own custom services, actions and reactions

  [How to add a module](./how-to-add-module.md)
</details>
