import 'api_error.dart';

class ApiResponse {
  late Object? data;
  late ApiError? error;

  String? getError() {
    return error?.getError();
  }

  ApiResponse({this.data, this.error});

  @override
  String toString() {
    return 'ApiResponse{data: $data, error: $error.getError()}';
  }
}
