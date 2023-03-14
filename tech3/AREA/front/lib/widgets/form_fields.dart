import 'package:flutter/material.dart';

class AreaTextFormField extends StatelessWidget {
  const AreaTextFormField({
    super.key,
    required this.label,
    this.validator,
    this.onSaved,
    this.isRequired = false,
    this.obscureText = false,
    this.initialValue,
  });

  final String label;
  final String? Function(String?)? validator;
  final void Function(String?)? onSaved;
  final bool isRequired;
  final bool obscureText;
  final String? initialValue;

  @override
  Widget build(BuildContext context) {
    return TextFormField(
      maxLines: 1,
      decoration: InputDecoration(
        border: const OutlineInputBorder(),
        isDense: true,
        label: isRequired
            ? Row(
                mainAxisSize: MainAxisSize.min,
                children: [
                  Text(label),
                  const Text(" *", style: TextStyle(color: Colors.red)),
                ],
              )
            : Text(label),
      ),
      obscureText: obscureText,
      validator: validator,
      onSaved: onSaved,
      initialValue: initialValue,
    );
  }
}
