import 'package:streaming_shared_preferences/streaming_shared_preferences.dart';

import 'package:area/types/area.dart';

class Store {
  //* ------- Welcome to the store, grab a drink and enjoy the ride! ------- *//

  final Preference<String> authToken;
  final Preference<String> refreshToken;
  final Preference<String> userId;

  final Preference<List<AreaAction>> actions;
  final Preference<List<AreaReaction>> reactions;
  final Preference<List<AreaService>> services;

  final Preference<List<Area>> areas;
  // final Preference<List<AreaService>> userServices;

  //* ---------------------------------------------------------------------- *//

  Store(StreamingSharedPreferences preferences)
      : authToken = preferences.getString('authToken', defaultValue: ""),
        refreshToken = preferences.getString('refreshToken', defaultValue: ""),
        userId = preferences.getString('userId', defaultValue: ""),
        actions = preferences.getCustomValue<List<AreaAction>>('actions',
            defaultValue: [],
            adapter: JsonAdapter(
              deserializer: (value) => (value as List<dynamic>)
                  .map((e) => AreaAction.fromJson(e))
                  .toList(),
              serializer: (value) => value.map((e) => e.toJson()).toList(),
            )),
        reactions = preferences.getCustomValue<List<AreaReaction>>('reactions',
            defaultValue: [],
            adapter: JsonAdapter(
              deserializer: (value) => (value as List<dynamic>)
                  .map((e) => AreaReaction.fromJson(e))
                  .toList(),
              serializer: (value) => value.map((e) => e.toJson()).toList(),
            )),
        services = preferences.getCustomValue<List<AreaService>>('services',
            defaultValue: [],
            adapter: JsonAdapter(
              deserializer: (value) => (value as List<dynamic>)
                  .map((e) => AreaService.fromJson(e))
                  .toList(),
              serializer: (value) => value.map((e) => e.toJson()).toList(),
            )),
        areas = preferences.getCustomValue<List<Area>>('areas',
            defaultValue: [],
            adapter: JsonAdapter(
              deserializer: (value) => (value as List<dynamic>)
                  .map((e) => Area.fromJson(e))
                  .toList(),
              serializer: (value) => value.map((e) => e.toJson()).toList(),
            ));
}
