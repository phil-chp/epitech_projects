import 'package:flutter/material.dart';

import 'package:streaming_shared_preferences/streaming_shared_preferences.dart';

import 'package:area/types/area.dart';
import 'package:area/types/api_response.dart';
import 'package:area/widgets/dropdown.dart';
import 'package:area/widgets/button.dart';
import 'package:area/services/store.dart';
import 'package:area/services/api.dart' as api;

class AreaPopin extends StatefulWidget {
  const AreaPopin({
    super.key,
    required this.onSave,
    required this.services,
    required this.type,
    required this.store,
    required this.listEvents,
  });

  final Function onSave;
  final List<AreaService> services;
  final AreaEventType type;
  final Store store;
  final List<AreaEvent> listEvents;

  @override
  State<AreaPopin> createState() => _AreaPopinState();
}

class _AreaPopinState extends State<AreaPopin> {
  late List<AreaEvent> events;
  late AreaEvent event;
  String? eventValue;

  @override
  void initState() {
    super.initState();
    events = widget.listEvents;
    event = widget.type == AreaEventType.action ? AreaAction() : AreaReaction();
  }

  @override
  Widget build(BuildContext context) {
    return Center(child: _buildPopinContent(context));
  }

  @override
  void dispose() {
    super.dispose();
    widget.store.actions.setValue([]);
    widget.store.reactions.setValue([]);
  }

  Widget _buildPopinContent(BuildContext context) {
    return Column(mainAxisSize: MainAxisSize.min, children: [
      AlertDialog(
          title: Text(widget.type == AreaEventType.action
              ? "Add Action"
              : "Add Reaction"),
          content: Column(children: [
            AreaDropdown(
                label: "service",
                items: widget.services,
                onChange: (value) async {
                  final id =
                      widget.services.firstWhere((el) => el.name == value).id;
                  ApiResponse resp =
                      await api.Data.getEventsFromService(id, widget.type);

                  if (resp.data == null && mounted) {
                    ScaffoldMessenger.of(context).showSnackBar(const SnackBar(
                        content: Text("Error while fetching events")));
                    return;
                  }

                  if (widget.type == AreaEventType.action) {
                    List<AreaAction> actions = [];
                    for (var event in resp.data as List<AreaEvent>) {
                      actions.add(event as AreaAction);
                    }
                    widget.store.actions.setValue(actions);
                  } else if (widget.type == AreaEventType.reaction) {
                    List<AreaReaction> reactions = [];
                    for (var event in resp.data as List<AreaEvent>) {
                      reactions.add(event as AreaReaction);
                    }
                    widget.store.reactions.setValue(reactions);
                  }
                  setState(() {
                    event.service = value;
                    events = resp.data as List<AreaEvent>;
                    eventValue = null;
                  });
                }),
            const SizedBox(height: 16),
            StatefulBuilder(
              builder: (context, state) => AreaDropdown(
                  label: "action",
                  // disabledLabel: "Choose a service first",
                  items: events,
                  value: eventValue,
                  onChange: (value) {
                    event.name = value;
                    event.id = events.firstWhere((el) => el.name == value).id;
                  }),
            ),
            const SizedBox(height: 16),
            AreaButton("Confirm", onPressed: () {
              widget.onSave(widget.type, event);
              Navigator.pop(context);
            })
          ]))
    ]);
  }
}
