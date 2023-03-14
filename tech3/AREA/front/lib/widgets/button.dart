import 'package:flutter/material.dart';

import 'package:streaming_shared_preferences/streaming_shared_preferences.dart';

import 'package:area/types/area.dart';
import 'package:area/widgets/popin.dart';
import 'package:area/services/store.dart';

class AreaButton extends StatelessWidget {
  const AreaButton(this.label, {super.key, this.onPressed, this.icon});

  final VoidCallback? onPressed;
  final String? label;
  final IconData? icon;

  @override
  Widget build(BuildContext context) {
    return ElevatedButton.icon(
      onPressed: onPressed ?? () {},
      icon: Icon(icon ?? Icons.add),
      label: Text(label ?? ""),
    );
  }
}

class AreaButtonPopin extends StatefulWidget {
  const AreaButtonPopin(
      {super.key,
      required this.type,
      this.icon,
      required this.services,
      required this.store,
      required this.onSave});

  final AreaEventType type;
  final IconData? icon;
  final List<AreaService> services;
  final Store store;
  final Function onSave;

  @override
  State<AreaButtonPopin> createState() => _AreaButtonPopinState();
}

class _AreaButtonPopinState extends State<AreaButtonPopin> {
  @override
  Widget build(BuildContext context) {
    return widget.type == AreaEventType.action
        ? PreferenceBuilder<List<AreaAction>>(
            preference: widget.store.actions,
            builder: (BuildContext _, List<AreaAction> listEvents) {
              return Center(
                  child: ElevatedButton.icon(
                onPressed: _onPressed(listEvents),
                icon: Icon(widget.icon ?? Icons.add),
                label: const Text("Action"),
              ));
            },
          )
        : PreferenceBuilder<List<AreaReaction>>(
            preference: widget.store.reactions,
            builder: (BuildContext _, List<AreaReaction> listEvents) {
              return Center(
                  child: ElevatedButton.icon(
                onPressed: _onPressed(listEvents),
                icon: Icon(widget.icon ?? Icons.add),
                label: const Text("Reaction"),
              ));
            },
          );
  }

  VoidCallback _onPressed(List<AreaEvent> listEvents) {
    return () {
      showDialog(
        context: context,
        builder: (BuildContext context) {
          return AreaPopin(
            services: widget.services,
            type: widget.type,
            store: widget.store,
            onSave: widget.onSave,
            listEvents: listEvents,
          );
        },
      );
    };
  }
}
