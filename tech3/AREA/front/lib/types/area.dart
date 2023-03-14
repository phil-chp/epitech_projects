import 'dart:core';
import 'dart:convert';

import 'package:area/types/auth.dart';

enum AreaEventType { action, reaction, service }

class Area {
  String? id;
  String? name;
  String? description;
  AreaAction? action;
  AreaReaction? reaction;

  Area({
    this.id = "",
    this.name = "",
    this.description = "",
    this.action,
    this.reaction,
  });

  factory Area.fromJson(Map<String, dynamic> json) {
    return Area(
      id: json['id'] ?? json['areaId'],
      name: json['name'],
      description: json['description'],
      action: AreaAction.fromJson(json['action']),
      reaction: AreaReaction.fromJson(json['reaction']),
    );
  }

  static Map<String, dynamic> toMap(Area area) => {
        'id': area.id,
        'name': area.name,
        'description': area.description,
        'action': area.action,
        'reaction': area.reaction,
      };

  static String encode(List<Area> areas) => json.encode(
      areas.map<Map<String, dynamic>>((area) => Area.toMap(area)).toList());

  static List<Area> decode(String areas) =>
      (json.decode(areas) as List<dynamic>)
          .map<Area>((item) => Area.fromJson(item))
          .toList();

  Map<String, dynamic> toJson() => {
        'id': id,
        'name': name,
        'description': description,
        'action': action!.toJson(),
        'reaction': reaction!.toJson(),
      };
}

//* ------------------------------------------------------------------------ *//

abstract class AreaEvent {
  int id;
  String name;
  String? description;
  AreaEventType type;
  String? service;
  int? serviceId;
  String? icon;
  bool linked;
  Auth? auth;

  AreaEvent({
    required this.id,
    required this.name,
    this.description,
    required this.type,
    this.icon,
    this.auth,
    this.linked = false,
    this.service,
    this.serviceId,
  });

  factory AreaEvent.fromJson(Map<String, dynamic> json) =>
      throw UnimplementedError();

  static Map<String, dynamic> toMap(AreaEvent area) => {
        'id': area.id,
        'name': area.name,
        'description': area.description,
        'service': area.service,
        'serviceId': area.service,
        'icon': area.icon,
      };

  Map<String, dynamic> toJson() => {
        'id': id,
        'name': name,
        'description': description,
        'service': service,
        'serviceId': service,
      };
}

class AreaReaction extends AreaEvent {
  AreaReaction({
    int id = -1,
    String name = "",
    String? description,
    String service = "",
    int? serviceId,
    AreaEventType type = AreaEventType.reaction,
  }) : super(
            id: id,
            name: name,
            description: description,
            service: service,
            serviceId: serviceId,
            type: type);

  @override
  factory AreaReaction.fromJson(Map<String, dynamic> json) {
    late int? serviceId;

    try {
      serviceId = json['serviceId'] ?? json['service']['serviceId'];
    } catch (e) {
      serviceId = null;
    }
    return AreaReaction(
      id: json['id'] ?? json['reactionId'],
      name: json['name'],
      description: json['description'],
      service:
          json['service'] is String ? json['service'] : json['service']['name'],
      serviceId: serviceId,
      type: AreaEventType.reaction,
    );
  }

  @override
  Map<String, dynamic> toJson() => {
        'id': id,
        'name': name,
        'description': description,
        'service': service,
        'serviceId': serviceId,
      };
}

class AreaAction extends AreaEvent {
  AreaAction({
    int id = -1,
    String name = "",
    String? description,
    String service = "",
    int? serviceId,
    AreaEventType type = AreaEventType.action,
  }) : super(
            id: id,
            name: name,
            description: description,
            service: service,
            serviceId: serviceId,
            type: type);

  @override
  factory AreaAction.fromJson(Map<String, dynamic> json) {
    late int? serviceId;

    try {
      serviceId = json['serviceId'] ?? json['service']['serviceId'];
    } catch (e) {
      serviceId = null;
    }

    return AreaAction(
      id: json['id'] ?? json['actionId'],
      name: json['name'],
      description: json['description'],
      service:
          json['service'] is String ? json['service'] : json['service']['name'],
      serviceId: serviceId,
      type: AreaEventType.action,
    );
  }

  @override
  Map<String, dynamic> toJson() => {
        'id': id,
        'name': name,
        'description': name,
        'service': service,
        'serviceId': serviceId,
      };
}

class AreaService extends AreaEvent {
  AreaService({
    int id = -1,
    String name = "",
    String? icon,
    bool linked = false,
    Auth? auth,
    AreaEventType type = AreaEventType.service,
  }) : super(id: id, name: name, linked: linked, icon: icon, type: type);

  @override
  factory AreaService.fromJson(Map<String, dynamic> json) {
    return AreaService(
      id: json['id'] ?? json['serviceId'],
      name: json['name'],
      icon: json['icon'],
      linked: json['linked'] ?? false,
      type: AreaEventType.service,
    );
  }

  @override
  Map<String, dynamic> toJson() => {
        'serviceId': id,
        'name': name,
        'icon': icon,
        'linked': linked,
        'auth': auth?.toJson(),
      };
}
