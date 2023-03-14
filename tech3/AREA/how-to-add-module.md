[<< Go back](./README.md)

# How to add a module

## Services

### Create a new service

To create a new service, you need to create a new file in the `services` folder. This file will contain all the information about your service.

Start of by creating a initService method.

```ts
async initYourService(UserAuth : any) => {
    const token = UserAuth.token;
    const yourService = await <Your service init instance>({
      // ...
    });
    return yourService;
 }
```

This method will be called when the user will try to connect to your service. It will return an instance of your service.

### Add your service to the API

To add your service to the API, you need to add it to the `app.ts` file.

```ts
import { YourService } from './services/yourService';

// ...

app.use("/api", YourService)
```

### Add the service to the Realtime Database in your Firebase admin panel.

Go to the `Services` section, and add a new object:
```json
{
  "service-<serviceId>": {
    "name": "<serviceName>",
    "serviceId": "<serviceId>",
  }
}
```

## Actions

### Create a new action

Go to the service you want to add an action or reaction to. Then create a method for each action. For example:

```ts
async yourServiceAction() => {
    // Do something
    return // Return something
 }
```

### Link your action with the service

You need to add your action method inside the export to link it.

```ts
export { yourServiceAction, ... };
```

### Add the action to the Realtime Database in your Firebase admin panel.

Go to the `Services` section, and add a new object:
```json
{
  "action-<actionId>": {
    "name": "<actionName>",
    "id": "<actionId>",
    "description": "<actionDescription>",
    "service": "<serviceName>",
    "serviceId": "<serviceId>",
    "url": "<backend_url_to_your_action>",
    "<key>": "<Any extra information specific to your action>",
    ...
  }
}
```

## Reactions

### Create a new reaction

Go to the service you want to add an action or reaction to. Then create a method for each action. For example:

```ts
async yourServiceReaction() => {
    // Do something
    return // Return something
 }
```

### Link your reaction with the service

You need to add your reaction method inside the export to link it.

```ts
export { yourServiceReaction, ... };
```

### Add the reaction to the Realtime Database in your Firebase admin panel.

Go to the `Services` section, and add a new object:
```json
{
  "reaction-<reactionId>": {
    "name": "<reactionName>",
    "id": "<reactionId>",
    "description": "<reactionDescription>",
    "service": "<serviceName>",
    "serviceId": "<serviceId>",
    "url": "<backend_url_to_your_reaction>",
    "<key>": "<Any extra information specific to your reaction>",
    ...
  }
}
```

And that's it, you now have your new service and their actions and reactions available on both applications. If you still don't see them. Try restarting the back and, and if that still doesn't fix it rebuild the docker compose.

Restart backend:
```bash
docker-compose down
docker-compose up -d
docker-compose logs -f
```

Rebuild docker compose:
```bash
docker-compose down
docker-compose build
docker-compose up -d
docker-compose logs -f
```

[<< Go back](./README.md)
