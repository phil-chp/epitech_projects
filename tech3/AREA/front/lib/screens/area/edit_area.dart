import 'package:flutter/material.dart';

import 'package:area/widgets/button.dart';
import 'package:area/widgets/block.dart';
import 'package:area/widgets/form_fields.dart';
import 'package:area/types/area.dart';
import 'package:area/services/validate.dart';
import 'package:area/services/store.dart';
import 'package:area/services/api.dart' as api;

class EditArea extends StatefulWidget {
  const EditArea({super.key, required this.store, this.index});

  final Store store;
  final int? index;

  @override
  State<EditArea> createState() => _EditAreaState();
}

class _EditAreaState extends State<EditArea> {
  final _formKey = GlobalKey<FormState>();
  late Area area;

  late List<AreaService> _services;

  @override
  void initState() {
    super.initState();

    _services = widget.store.services.getValue().where((service) {
      return service.linked == true;
    }).toList();
    setState(() {
      area = widget.index != null
          ? widget.store.areas.getValue()[widget.index!]
          : Area();
    });
  }

  @override
  Widget build(BuildContext context) {
    WidgetsBinding.instance.addPostFrameCallback((_) {
      if (_services.isEmpty) {
        ScaffoldMessenger.of(context).showSnackBar(const SnackBar(
            content: Text(
                "You have no services. Please subscribe to a service before trying to create/edit an AREA.")));
        Navigator.pop(context);
      }
    });

    return Scaffold(
      appBar: AppBar(
        title: const Text("Add new AREA",
            style: TextStyle(fontWeight: FontWeight.bold)),
      ),
      body: Container(
        padding: const EdgeInsets.all(24),
        child: _areaEditForm(),
      ),
      floatingActionButton: FloatingActionButton(
        onPressed: _confirm,
        backgroundColor: Colors.red[50],
        foregroundColor: Colors.red[900],
        shape: const CircleBorder(),
        child: const Icon(Icons.check),
      ),
    );
  }

  Widget _areaEditForm() {
    return Form(
        key: _formKey,
        child: Wrap(spacing: 16.0, runSpacing: 16.0, children: [
          AreaTextFormField(
            label: "Name",
            validator: Validation.isNotNull,
            onSaved: _setName,
            isRequired: true,
            initialValue: area.name,
          ),
          AreaTextFormField(
            label: "Description",
            onSaved: _setDescription,
            initialValue: area.description,
          ),
          Row(mainAxisAlignment: MainAxisAlignment.spaceEvenly, children: [
            AreaButtonPopin(
              type: AreaEventType.action,
              icon: Icons.add,
              services: _services,
              store: widget.store,
              onSave: _setEvent,
            ),
            AreaButtonPopin(
              type: AreaEventType.reaction,
              icon: Icons.add,
              services: _services,
              store: widget.store,
              onSave: _setEvent,
            )
          ]),
          const SizedBox(height: 64.0),
          AreaBlock(area: area),
        ]));
  }

  void _setName(String? value) {
    setState(() {
      area.name = value;
    });
  }

  void _setDescription(String? value) {
    setState(() {
      area.description = value ?? '';
    });
  }

  void _setEvent<T extends AreaEvent>(AreaEventType type, T? evt) {
    if (evt == null) return;
    // evt.id = 0;
    if (type == AreaEventType.action) {
      setState(() {
        area.action = AreaAction(
          id: evt.id,
          name: evt.name,
          service: evt.service!,
        );
      });
    } else {
      setState(() {
        area.reaction = AreaReaction(
          id: evt.id,
          name: evt.name,
          service: evt.service!,
        );
      });
    }
  }

  void _confirm() {
    if (_formKey.currentState!.validate()) {
      _formKey.currentState!.save();
      String userId = widget.store.userId.getValue();

      widget.index == null
          ? api.Data.addUserArea(userId, area)
          : api.Data.editUserArea(userId, area);

      ScaffoldMessenger.of(context).showSnackBar(
          const SnackBar(content: Text("Area successfully added")));
      Navigator.pop(context);
    }
  }
}
