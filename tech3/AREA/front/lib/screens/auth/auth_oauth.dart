import 'package:flutter/material.dart';

import 'package:google_sign_in/google_sign_in.dart';
import 'package:firebase_auth/firebase_auth.dart';

import 'package:area/services/store.dart';

class AuthOAuth extends StatefulWidget {
  const AuthOAuth({Key? key, required this.store}) : super(key: key);

  final Store store;

  @override
  _AuthOAuthState createState() => _AuthOAuthState();
}

class _AuthOAuthState extends State<AuthOAuth> {
  final FirebaseAuth auth = FirebaseAuth.instance;

  Future<void> signup(BuildContext context) async {
    const clientId = "XXXXXXXXXXXX.apps.googleusercontent.com";
    final GoogleSignIn googleSignIn = GoogleSignIn(clientId: clientId);
    final GoogleSignInAccount? googleSignInAccount =
        await googleSignIn.signIn();
    if (googleSignInAccount != null) {
      final GoogleSignInAuthentication googleSignInAuthentication =
          await googleSignInAccount.authentication;
      print(googleSignInAuthentication.idToken);
      print(googleSignInAuthentication.accessToken);
      final AuthCredential authCredential = GoogleAuthProvider.credential(
        idToken: googleSignInAuthentication.idToken,
        accessToken: googleSignInAuthentication.accessToken,
      );

      UserCredential result = await auth.signInWithCredential(authCredential);
      final String authToken = await result.user!.getIdToken();
      final String? refreshToken = result.user!.refreshToken;
      User? user = result.user;

      if (user != null) {
        widget.store.userId.setValue(user.uid);
        widget.store.authToken.setValue(authToken);
        widget.store.refreshToken.setValue(refreshToken ?? "");
      }
    }
  }

  @override
  Widget build(BuildContext context) {
    return Container(
      height: 48.0,
      width: 48.0,
      child: TextButton(
        onPressed: () {
          signup(context);
        },
        child: Image.asset(
          'assets/google.png',
          fit: BoxFit.cover,
        ),
      ),
    );
  }
}
