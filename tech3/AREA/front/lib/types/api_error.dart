class ApiError {
  String? error;

  ApiError({this.error});

  ApiError.fromJson(Map<String, dynamic> json) {
    error = json['error'];
  }

  String? getError() {
    return error;
  }

  Map<String, dynamic> toJson() {
    final Map<String, dynamic> data = <String, dynamic>{};
    data['error'] = error;
    return data;
  }
}
