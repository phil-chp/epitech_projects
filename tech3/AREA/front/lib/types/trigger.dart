class Trigger {
  String triggerId;
  String idArea;
  int idAction;
  int idReaction;
  String userId;
  int status;
  String? lastTriggered;
  int? nbTimesTriggered;
  int? delayExecution;
  DateTime? createdAt;

  Trigger({
    required this.triggerId,
    required this.idArea,
    required this.idAction,
    required this.idReaction,
    required this.userId,
    required this.status,
    this.lastTriggered,
    this.nbTimesTriggered,
    this.delayExecution,
    this.createdAt,
  });

  factory Trigger.fromJson(Map<String, dynamic> json) {
    return Trigger(
      triggerId: json['triggerId'],
      idArea: json['idArea'],
      idAction: json['idAction'],
      idReaction: json['idReaction'],
      status: json['status'],
      lastTriggered: json['lastTriggered'],
      nbTimesTriggered: json['nbTimesTriggered'],
      delayExecution: json['delayExecution'],
      createdAt:
          json['createdAt'] != null ? DateTime.parse(json['createdAt']) : null,
      userId: json['userId'] ?? json['user']['uid'],
    );
  }

  Map<String, dynamic> toJson() => {
        'triggerId': triggerId,
        'idArea': idArea,
        'idAction': idAction,
        'idReaction': idReaction,
        'status': status,
        'lastTriggered': lastTriggered,
        'nbTimesTriggered': nbTimesTriggered,
        'delayExecution': delayExecution,
        'createdAt': createdAt.toString(),
        'userId': userId,
      };
}
