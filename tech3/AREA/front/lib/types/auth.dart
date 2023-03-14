class Auth {
  String? username;
  String? password;

  Auth({
    this.username,
    this.password,
  });

  factory Auth.fromJson(Map<String, dynamic> json) {
    return Auth(
      username: json['username'],
      password: json['password'],
    );
  }

  Map<String, dynamic> toJson() => {
        'username': username,
        'password': password,
      };
}
