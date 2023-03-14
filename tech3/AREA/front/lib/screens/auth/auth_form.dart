import 'package:flutter/material.dart';

import 'package:area/widgets/form_fields.dart';
import 'package:area/services/validate.dart';
import 'package:area/services/store.dart';
import 'package:area/services/api.dart' as api;
import 'package:area/types/api_response.dart';
import 'package:area/types/user.dart';

class AuthForm extends StatefulWidget {
  const AuthForm({Key? key, this.isLogin = true, required this.store})
      : super(key: key);

  final bool isLogin;
  final Store store;

  @override
  _AuthFormState createState() => _AuthFormState();
}

class _AuthFormState extends State<AuthForm> {
  final _formKey = GlobalKey<FormState>();
  String? _success;

  String _email = "";
  String _password = "";

  ApiResponse _response = ApiResponse();

  void _validateForm() async {
    setState(() {
      _response = ApiResponse();
      _success = null;
    });
    if (_formKey.currentState!.validate()) {
      _formKey.currentState!.save();
      final ApiResponse response = widget.isLogin
          ? await api.Auth.signIn(_email.trim(), _password.trim())
          : await api.Auth.signUp(_email.trim(), _password.trim());
      setState(() {
        _response = response;
      });
      if (response.data != null) {
        if (widget.isLogin == true) {
          widget.store.authToken.setValue((response.data as User).authToken!);
          widget.store.refreshToken
              .setValue((response.data as User).refreshToken!);
          widget.store.userId.setValue((response.data as User).userId!);
        } else {
          setState(() {
            _success =
                "Account created successfully!\nPlease login to continue.";
          });
        }
      }
    }
  }

  @override
  Widget build(BuildContext context) {
    return Form(
      autovalidateMode: AutovalidateMode.always,
      key: _formKey,
      child: Column(children: <Widget>[
        AreaTextFormField(
          label: "Email",
          key: const Key('_email'),
          onSaved: (String? value) {
            _email = value ?? '';
          },
          validator: Validation.isEmail,
          isRequired: true,
        ),
        const SizedBox(height: 16.0),
        AreaTextFormField(
          label: "Password",
          key: const Key('_password'),
          obscureText: true,
          onSaved: (String? value) {
            _password = value ?? '';
          },
          validator: Validation.isNotNull,
          isRequired: true,
        ),
        const SizedBox(height: 16.0),
        _response.getError() != null
            ? Text(_response.getError()!,
                textAlign: TextAlign.center,
                style: const TextStyle(
                    color: Colors.red, fontWeight: FontWeight.bold))
            : const SizedBox.shrink(),
        _success != null
            ? Text(_success!,
                textAlign: TextAlign.center,
                style: const TextStyle(
                    color: Colors.green, fontWeight: FontWeight.bold))
            : const SizedBox.shrink(),
        const SizedBox(height: 16.0),
        ElevatedButton(
          onPressed: _validateForm,
          child: Text(widget.isLogin ? 'Sign in' : 'Sign up'),
        ),
      ]),
    );
  }
}
