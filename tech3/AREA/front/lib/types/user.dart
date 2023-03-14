class User {
  String? userId;
  String? email;
  String? lastLogin;
  String? authToken;
  String? refreshToken;

  User({
    required this.userId,
    required this.email,
    required this.lastLogin,
    this.authToken = "",
    this.refreshToken = "",
  });

  User.fromJson(Map<String, dynamic> json) {
    userId = json['user']['uid'];
    email = json['user']['email'];
    if (json['user']['lastLoginAt'] != null) {
      lastLogin = json['user']['lastLoginAt'];
    } else {
      lastLogin = "";
    }
    authToken = json['user']['stsTokenManager']?['accessToken'] ?? "";
    refreshToken = json['user']['stsTokenManager']?['refreshToken'] ?? "";
  }

  Map<String, dynamic> toJson() {
    final Map<String, dynamic> data = <String, dynamic>{};

    data['user']['uid'] = userId;
    data['user']['email'] = email;
    data['user']['lastLoginAt'] = lastLogin;
    data['user']['authToken'] = authToken;
    data['user']['refreshToken'] = refreshToken;
    return data;
  }
}
