library api;

import 'dart:io';
import 'dart:convert';

import 'package:http/http.dart' as http;

import 'package:area/config.dart';

import 'package:area/types/api_response.dart';
import 'package:area/types/api_error.dart';
import 'package:area/types/area.dart';
import 'package:area/types/trigger.dart';
import 'package:area/types/user.dart';

class Headers {
  static final Map<String, String> headers = {
    "Content-Type": "application/json",
    "Accept": "application/json",
  };
}

class Test {
  static Future<ApiResponse> ping() async {
    try {
      final response = await http
          .get(Uri.parse('$BACKEND_URL/api/ping'))
          .timeout(const Duration(seconds: 10), onTimeout: () {
        throw const SocketException("Timeout");
      });

      switch (response.statusCode) {
        case 200:
          return ApiResponse(data: json.decode(response.body));
        case 401:
          return ApiResponse(
              error: ApiError.fromJson({"error": "Unauthorized"}));
        default:
          return ApiResponse(
              error: ApiError.fromJson({"error": "Unknown error"}));
      }
    } on SocketException catch (e) {
      return ApiResponse(error: ApiError(error: "Server error. $e"));
    }
  }
}

class Auth {
  static handleFirebaseError(error) {
    final reg = RegExp('auth\/(.+)[)]');
    final parsed = reg.firstMatch(error)?.group(1);
    switch (parsed) {
      case 'user-not-found':
        return ApiError(error: 'No user found for that email.');
      case 'wrong-password':
        return ApiError(error: 'Wrong password provided for that user.');
      case 'invalid-email':
        return ApiResponse(error: ApiError(error: 'The email is invalid.'));
      case 'email-already-in-use':
        return ApiError(error: 'The account already exists for that email.');
      case 'weak-password':
        return ApiError(error: 'The password provided is too weak.');
      default:
        return ApiError.fromJson({"error": "Unauthorized"});
    }
  }

  static Future<ApiResponse> signIn(String email, String password) async {
    ApiResponse apiResponse = ApiResponse();

    final body = json.encode({
      "email": email,
      "password": password,
    });

    try {
      final response = await http.post(Uri.parse('$BACKEND_URL/api/login'),
          body: body, headers: Headers.headers);

      switch (response.statusCode) {
        case 200:
          final data = json.decode(response.body);
          apiResponse.data = User.fromJson(data);
          break;
        case 401:
          apiResponse.error =
              handleFirebaseError(json.decode(response.body)["message"]);
          break;
        default:
          apiResponse.error = ApiError.fromJson({"error": "Unknown error"});
          break;
      }
    } on SocketException {
      apiResponse.error = ApiError(error: "Server error. Please retry");
    }
    return apiResponse;
  }

  static Future<ApiResponse> signUp(String email, String password) async {
    ApiResponse apiResponse = ApiResponse();

    final body = json.encode({
      "email": email,
      "password": password,
    });

    try {
      final response = await http.post(Uri.parse('$BACKEND_URL/api/register'),
          body: body, headers: Headers.headers);

      switch (response.statusCode) {
        case 200:
          final data = json.decode(response.body);
          apiResponse.data = User.fromJson(data);
          break;
        case 401:
          apiResponse.error =
              handleFirebaseError(json.decode(response.body)["message"]);
          break;
        default:
          final String errorMessage =
              json.decode(response.body)["message"] ?? "Unknown error";
          apiResponse.error = ApiError.fromJson({"error": errorMessage});
          break;
      }
    } on SocketException {
      apiResponse.error = ApiError(error: "Server error. Please retry");
    }
    return apiResponse;
  }

  static Future<ApiResponse> verifyToken(String token) async {
    ApiResponse apiResponse = ApiResponse();

    final body = json.encode({
      "token": token,
    });

    try {
      final response = await http.post(
          Uri.parse('$BACKEND_URL/api/verify_token'),
          body: body,
          headers: Headers.headers);

      switch (response.statusCode) {
        case 200:
          final data = json.decode(response.body);
          User user = User.fromJson(data);
          apiResponse.data = user;
          break;
        case 401:
          apiResponse.error = ApiError.fromJson({"error": "Unauthorized"});
          break;
        default:
          apiResponse.error = ApiError.fromJson({"error": "Unknown error"});
          break;
      }
    } on SocketException {
      apiResponse.error = ApiError(error: "Server error. Please retry");
    }
    return apiResponse;
  }
}

class Data {
  // static Future<ApiResponse> getActions() async {
  //   ApiResponse apiResponse = ApiResponse();

  //   try {
  //     final response = await http.get(Uri.parse('$BACKEND_URL/api/actions'),
  //         headers: Headers.headers);

  //     switch (response.statusCode) {
  //       case 200:
  //         final data = json.decode(response.body)["Actions"];
  //         apiResponse.data = data.map((e) => AreaAction.fromJson(e)).toList();
  //         break;
  //       case 401:
  //         apiResponse.error = ApiError.fromJson({"error": "Unauthorized"});
  //         break;
  //       default:
  //         apiResponse.error = ApiError.fromJson({"error": "Unknown error"});
  //         break;
  //     }
  //   } on SocketException {
  //     apiResponse.error = ApiError(error: "Server error. Please retry");
  //   }
  //   return apiResponse;
  // }

  // static Future<ApiResponse> getReactions() async {
  //   ApiResponse apiResponse = ApiResponse();

  //   try {
  //     final response = await http.get(Uri.parse('$BACKEND_URL/api/reactions'),
  //         headers: Headers.headers);

  //     switch (response.statusCode) {
  //       case 200:
  //         final data = json.decode(response.body)["Reactions"];
  //         apiResponse.data = data.map((e) => AreaReaction.fromJson(e)).toList();
  //         break;
  //       case 401:
  //         apiResponse.error = ApiError.fromJson({"error": "Unauthorized"});
  //         break;
  //       default:
  //         apiResponse.error = ApiError.fromJson({"error": "Unknown error"});
  //         break;
  //     }
  //   } on SocketException {
  //     apiResponse.error = ApiError(error: "Server error. Please retry");
  //   }
  //   return apiResponse;
  // }

  static Future<ApiResponse> getServices() async {
    ApiResponse apiResponse = ApiResponse();

    try {
      final response = await http.get(Uri.parse('$BACKEND_URL/api/services'),
          headers: Headers.headers);

      switch (response.statusCode) {
        case 200:
          final data = json.decode(response.body)["Services"];
          apiResponse.data = data.map((e) => AreaService.fromJson(e)).toList();
          break;
        case 401:
          apiResponse.error = ApiError.fromJson({"error": "Unauthorized"});
          break;
        default:
          apiResponse.error = ApiError.fromJson({"error": "Unknown error"});
          break;
      }
    } on SocketException {
      apiResponse.error = ApiError(error: "Server error. Please retry");
    }
    return apiResponse;
  }

  static Future<ApiResponse> getUserServices(String userId) async {
    ApiResponse apiResponse = ApiResponse();

    try {
      final response = await http.get(
          Uri.parse('$BACKEND_URL/api/user/$userId/services'),
          headers: Headers.headers);

      switch (response.statusCode) {
        case 200:
          final data =
              json.decode(response.body)["service"] as Map<String, dynamic>?;
          apiResponse.data = data != null
              ? data.entries.map((e) => AreaService.fromJson(e.value)).toList()
              : [];
          break;
        case 401:
          apiResponse.error = ApiError.fromJson({"error": "Unauthorized"});
          break;
        default:
          apiResponse.error = ApiError.fromJson({"error": "Unknown error"});
          break;
      }
    } on SocketException {
      apiResponse.error = ApiError(error: "Server error. Please retry");
    }
    return apiResponse;
  }

  static Future<ApiResponse> subscribeService(
      AreaService service, String userId) async {
    ApiResponse apiResponse = ApiResponse();
    final body = json.encode({
      "serviceId": service.id,
      "name": service.name,
      "auth": service.auth,
    });

    try {
      final response = await http.post(
          Uri.parse('$BACKEND_URL/api/user/$userId/service'),
          body: body,
          headers: Headers.headers);

      switch (response.statusCode) {
        case 200:
          apiResponse.data = json.decode(response.body)["message"];
          break;
        case 401:
          apiResponse.error = ApiError.fromJson({"error": "Unauthorized"});
          break;
        default:
          apiResponse.error = ApiError.fromJson({"error": "Unknown error"});
          break;
      }
    } on SocketException {
      apiResponse.error = ApiError(error: "Server error. Please retry");
    }
    return apiResponse;
  }

  static Future<ApiResponse> unsubscribeService(
      String userId, int serviceId) async {
    ApiResponse apiResponse = ApiResponse();

    try {
      final response = await http.delete(
          Uri.parse('$BACKEND_URL/api/user/$userId/service/$serviceId'),
          headers: Headers.headers);

      switch (response.statusCode) {
        case 200:
          apiResponse.data = json.decode(response.body)["message"];
          break;
        case 401:
          apiResponse.error = ApiError.fromJson({"error": "Unauthorized"});
          break;
        default:
          apiResponse.error = ApiError.fromJson({"error": "Unknown error"});
          break;
      }
    } on SocketException {
      apiResponse.error = ApiError(error: "Server error. Please retry");
    }
    return apiResponse;
  }

  static Future<ApiResponse> getEventsFromService(
      int serviceId, AreaEventType type) async {
    ApiResponse apiResponse = ApiResponse();
    String event = type == AreaEventType.action ? "actions" : "reactions";

    try {
      final response = await http.get(
          Uri.parse('$BACKEND_URL/api/service/$serviceId/$event'),
          headers: Headers.headers);

      switch (response.statusCode) {
        case 200:
          final data =
              json.decode(response.body)["services"] as Map<String, dynamic>?;
          apiResponse.data = data != null
              ? data.entries
                  .map((e) => type == AreaEventType.action
                      ? AreaAction.fromJson(e.value)
                      : AreaReaction.fromJson(e.value))
                  .toList()
              : [];
          break;
        case 401:
          apiResponse.error = ApiError.fromJson({"error": "Unauthorized"});
          break;
        default:
          apiResponse.error = ApiError.fromJson({"error": "Unknown error"});
          break;
      }
    } on SocketException {
      apiResponse.error = ApiError(error: "Server error. Please retry");
    }
    return apiResponse;
  }

  static Future<ApiResponse> addUserArea(String userId, Area data) async {
    ApiResponse apiResponse = ApiResponse();

    final body = json.encode({
      "name": data.name,
      "description": data.description,
      "action": {
        "service": {
          "name": data.action!.service,
          "serviceId": data.action!.serviceId,
        },
        "actionId": data.action!.id,
        "name": data.action!.name,
        "description": data.action!.description,
      },
      "reaction": {
        "service": {
          "name": data.reaction!.service,
          "serviceId": data.reaction!.serviceId,
        },
        "reactionId": data.reaction!.id,
        "name": data.reaction!.name,
        "description": data.reaction!.description,
      },
    });

    try {
      final response = await http.post(
          Uri.parse('$BACKEND_URL/api/user/$userId/area'),
          body: body,
          headers: Headers.headers);

      switch (response.statusCode) {
        case 200:
          apiResponse.data = json.decode(response.body)["message"];
          break;
        case 401:
          apiResponse.error = ApiError.fromJson({"error": "Unauthorized"});
          break;
        default:
          apiResponse.error = ApiError.fromJson({"error": "Unknown error"});
          break;
      }
    } on SocketException {
      apiResponse.error = ApiError(error: "Server error. Please retry");
    }
    return apiResponse;
  }

  static Future<ApiResponse> editUserArea(String userId, Area data) async {
    ApiResponse apiResponse = ApiResponse();
    String areaId = data.id.toString();

    final body = json.encode({
      "name": data.name,
      "description": data.description,
      "action": {
        "service": {
          "name": data.action!.service,
          "serviceId": data.action!.serviceId,
        },
        "id": data.action!.id,
        "name": data.action!.name,
        "description": data.action!.description,
      },
      "reaction": {
        "service": {
          "name": data.reaction!.service,
          "serviceId": data.reaction!.serviceId,
        },
        "id": data.reaction!.id,
        "name": data.reaction!.name,
        "description": data.reaction!.description,
      },
    });

    try {
      final response = await http.put(
          Uri.parse('$BACKEND_URL/api/user/$userId/area/$areaId'),
          body: body,
          headers: Headers.headers);

      switch (response.statusCode) {
        case 200:
          apiResponse.data = json.decode(response.body)["message"];
          break;
        case 401:
          apiResponse.error = ApiError.fromJson({"error": "Unauthorized"});
          break;
        default:
          apiResponse.error = ApiError.fromJson({"error": "Unknown error"});
          break;
      }
    } on SocketException {
      apiResponse.error = ApiError(error: "Server error. Please retry");
    }
    return apiResponse;
  }

  static Future<ApiResponse> deleteUserArea(
      String userId, String areaId) async {
    ApiResponse apiResponse = ApiResponse();

    try {
      final response = await http.delete(
          Uri.parse('$BACKEND_URL/api/user/$userId/area/$areaId'),
          headers: Headers.headers);

      switch (response.statusCode) {
        case 200:
          apiResponse.data = json.decode(response.body)["message"];
          break;
        case 401:
          apiResponse.error = ApiError.fromJson({"error": "Unauthorized"});
          break;
        default:
          apiResponse.error = ApiError.fromJson({"error": "Unknown error"});
          break;
      }
    } on SocketException {
      apiResponse.error = ApiError(error: "Server error. Please retry");
    }
    return apiResponse;
  }

  static Future<ApiResponse> getAllAreaFromUser(String userId) async {
    ApiResponse apiResponse = ApiResponse();

    try {
      final response = await http.get(
          Uri.parse('$BACKEND_URL/api/user/$userId/areas'),
          headers: Headers.headers);

      switch (response.statusCode) {
        case 200:
          final data =
              json.decode(response.body)["areas"] as Map<String, dynamic>?;
          apiResponse.data = data != null
              ? data.entries.map((e) => Area.fromJson(e.value)).toList()
              : [];
          break;
        case 401:
          apiResponse.error = ApiError.fromJson({"error": "Unauthorized"});
          break;
        default:
          apiResponse.error = ApiError.fromJson({"error": "Unknown error"});
          break;
      }
    } on SocketException {
      apiResponse.error = ApiError(error: "Server error. Please retry");
    }
    return apiResponse;
  }

  static Future<ApiResponse> getTriggerById(
      String userId, String triggerId) async {
    ApiResponse apiResponse = ApiResponse();

    try {
      final response = await http.get(
          Uri.parse('$BACKEND_URL/api/user/$userId/trigger/$triggerId'),
          headers: Headers.headers);

      switch (response.statusCode) {
        case 200:
          final data = json.decode(response.body)["trigger"];
          apiResponse.data = Trigger.fromJson(data);
          break;
        case 401:
          apiResponse.error = ApiError.fromJson({"error": "Unauthorized"});
          break;
        default:
          apiResponse.error = ApiError.fromJson({"error": "Unknown error"});
          break;
      }
    } on SocketException {
      apiResponse.error = ApiError(error: "Server error. Please retry");
    }
    return apiResponse;
  }
}
