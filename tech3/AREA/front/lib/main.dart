import 'package:flutter/material.dart';
import 'package:flutter/foundation.dart';

import 'package:streaming_shared_preferences/streaming_shared_preferences.dart';
import 'package:firebase_core/firebase_core.dart';

import 'package:area/screens/auth/auth.dart';
import 'package:area/screens/landing.dart';
import 'package:area/types/api_response.dart';
import 'package:area/types/area.dart';
import 'package:area/services/api.dart' as api;
import 'package:area/services/store.dart';

ValueNotifier<bool> serverActive = ValueNotifier(true);

void main() async {
  WidgetsFlutterBinding.ensureInitialized();

  if (defaultTargetPlatform == TargetPlatform.iOS ||
      defaultTargetPlatform == TargetPlatform.android) {
    await Firebase.initializeApp(
        options: const FirebaseOptions(
            apiKey: "XXXXXXXXXXXX",
            appId: "com.exemple.front",
            messagingSenderId: "",
            projectId: "area"),
        name: "AREA");
  } else {
    await Firebase.initializeApp(
        options: const FirebaseOptions(
            apiKey: "XXXXXXXXXXXX",
            appId: "com.exemple.front",
            messagingSenderId: "",
            projectId: "area"));
  }

  final preferences = await StreamingSharedPreferences.instance;
  final store = Store(preferences);

  checkServerStatus();
  runApp(MyApp(store: store));
}

checkServerStatus() async {
  final ApiResponse res = await api.Test.ping();
  if (res.error != null) {
    serverActive.value = false;
  }
}

class MyApp extends StatefulWidget {
  const MyApp({super.key, required this.store});

  final Store store;

  @override
  State<MyApp> createState() => _MyAppState();
}

class _MyAppState extends State<MyApp> {
  @override
  void initState() {
    super.initState();
    storeData(widget.store.userId.getValue());
  }

  storeData(String userId) async {
    // ApiResponse resp = (await api.Data.getActions());
    // final List<AreaAction> actions =
    //     resp.error == null ? List<AreaAction>.from(resp.data! as List) : [];
    // widget.store.actions.setValue(actions);

    // resp = (await api.Data.getReactions());
    // final List<AreaReaction> reactions =
    //     resp.error == null ? List<AreaReaction>.from(resp.data! as List) : [];
    // widget.store.reactions.setValue(reactions);

    ApiResponse resp = (await api.Data.getAllAreaFromUser(userId));
    final List<Area> areas =
        resp.data != null ? List<Area>.from(resp.data! as List) : [];
    widget.store.areas.setValue(areas);

    resp = (await api.Data.getServices());
    final List<AreaService> services =
        resp.data != null ? List<AreaService>.from(resp.data! as List) : [];

    resp = (await api.Data.getUserServices(userId));
    final List<AreaService> userServices =
        resp.data != null ? List<AreaService>.from(resp.data! as List) : [];

    for (AreaService service in services) {
      for (AreaService userService in userServices) {
        if (service.id == userService.id) {
          service.linked = true;
        }
      }
    }

    widget.store.services.setValue(services);
  }

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
        title: 'AREA',
        debugShowCheckedModeBanner: false,
        theme: ThemeData(
          useMaterial3: true,
          splashColor: Colors.transparent,
          colorScheme: ColorScheme.fromSeed(
              seedColor: const Color.fromARGB(255, 200, 24, 14)),
          highlightColor: Colors.transparent,
        ),
        // darkTheme: ThemeData(
        //   useMaterial3: true,
        //   brightness: Brightness.dark,
        //   splashColor: Colors.transparent,
        //   colorScheme: ColorScheme.fromSeed(seedColor: Colors.red).copyWith(
        //       secondary: Colors.redAccent, brightness: Brightness.dark),
        //   highlightColor: Colors.transparent,
        // ),
        // themeMode: ThemeMode.dark,
        home: Scaffold(
            appBar: AppBar(actions: [
              PreferenceBuilder<String>(
                  preference: widget.store.authToken,
                  builder: (BuildContext context, String authToken) {
                    return IconButton(
                        icon: const Icon(Icons.logout),
                        onPressed: authToken != ""
                            ? () {
                                widget.store.authToken.setValue("");
                                widget.store.refreshToken.setValue("");
                              }
                            : null);
                  }),
            ], shadowColor: Colors.black, elevation: 0),
            backgroundColor: Colors.white,
            body: SafeArea(
              bottom: true,
              left: true,
              top: true,
              right: true,
              maintainBottomViewPadding: true,
              minimum: EdgeInsets.zero,
              child: ValueListenableBuilder(
                  valueListenable: serverActive,
                  builder: (context, value, child) {
                    if (value) {
                      return Root(store: widget.store);
                    } else {
                      return const Center(
                          child: Text(
                              "500 Internal Server Error, try again later or contact support."));
                    }
                  }),
            )));
  }
}

class Root extends StatelessWidget {
  const Root({super.key, required this.store});

  final Store store;

  @override
  Widget build(BuildContext context) {
    return PreferenceBuilder<String>(
      preference: store.authToken,
      builder: (BuildContext _, String authToken) {
        if (authToken == "") {
          return Auth(store: store);
        } else {
          return Landing(store: store);
        }
      },
    );
  }
}
