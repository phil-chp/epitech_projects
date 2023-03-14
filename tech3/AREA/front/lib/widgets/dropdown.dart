import 'package:flutter/material.dart';

import 'package:area/types/area.dart';

class AreaDropdown extends StatefulWidget {
  AreaDropdown({
    super.key,
    this.items,
    this.value,
    required this.onChange,
    required this.label,
    this.disabledLabel,
  });

  final List<AreaEvent>? items;
  String? value;
  final Function onChange;
  final String label;
  String? disabledLabel = "";

  @override
  State<AreaDropdown> createState() => _AreaDropdownState();
}

class _AreaDropdownState extends State<AreaDropdown> {
  String? value;

  @override
  void initState() {
    super.initState();
    value = widget.value;
  }

  @override
  Widget build(BuildContext context) {
    return Container(
      width: double.infinity,
      child: DropdownButton<String>(
        value: value,
        hint: Text("Select a ${widget.label}"),
        disabledHint: Text(widget.disabledLabel ?? ""),
        isExpanded: true,
        iconSize: 32,
        elevation: 16,
        onChanged: (String? newValue) {
          setState(() {
            value = newValue;
          });
          widget.onChange(newValue);
        },
        items: widget.items?.map<DropdownMenuItem<String>>((AreaEvent value) {
          return DropdownMenuItem<String>(
            value: value.name,
            child: Text(value.name),
          );
        }).toList(),
      ),
    );
  }
}
