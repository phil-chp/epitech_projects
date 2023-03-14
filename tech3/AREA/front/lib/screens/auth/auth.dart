import 'package:flutter/material.dart';

import 'package:area/screens/auth/auth_form.dart';
import 'package:area/screens/auth/auth_oauth.dart';
import 'package:area/services/store.dart';
import 'package:area/widgets/text.dart';

class Auth extends StatefulWidget {
  const Auth({Key? key, this.isLogin = true, required this.store})
      : super(key: key);

  final bool isLogin;
  final Store store;

  @override
  _AuthState createState() => _AuthState();
}

class _AuthState extends State<Auth> {
  bool isLogin = true;

  @override
  void initState() {
    super.initState();
    isLogin = widget.isLogin;
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(),
      body: Container(
        padding: const EdgeInsets.all(24),
        child: SingleChildScrollView(
          child: Column(
            children: [
              TextTitle(isLogin ? "Login" : "Create account"),
              const SizedBox(height: 16.0),
              AuthForm(isLogin: isLogin, store: widget.store),
              const SizedBox(height: 32.0),
              AuthOAuth(store: widget.store),
              const SizedBox(height: 32.0),
              GestureDetector(
                onTap: () {
                  setState(() {
                    isLogin = !isLogin;
                  });
                },
                child: Text(
                  isLogin ? "Or create an account" : "Or login",
                  style: const TextStyle(
                    fontStyle: FontStyle.italic,
                    decoration: TextDecoration.underline,
                  ),
                ),
              ),
            ],
          ),
        ),
      ),
    );
  }
}
