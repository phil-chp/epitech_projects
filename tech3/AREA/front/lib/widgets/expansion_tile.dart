import 'package:flutter/material.dart';

import 'package:streaming_shared_preferences/streaming_shared_preferences.dart';

import 'package:area/widgets/text.dart';
import 'package:area/widgets/button.dart';

class AREAExpansionTile extends StatelessWidget {
  const AREAExpansionTile({
    Key? key,
    required this.title,
    required this.description,
    required this.builder,
    this.onPressed,
    this.initiallyExpanded = false,
  }) : super(key: key);

  final String title;
  final String description;
  final PreferenceBuilder builder;
  final VoidCallback? onPressed;
  final bool initiallyExpanded;

  @override
  Widget build(BuildContext context) {
    return ExpansionTile(
      initiallyExpanded: initiallyExpanded,
      tilePadding: const EdgeInsets.all(0),
      childrenPadding: const EdgeInsets.symmetric(vertical: 16.0),
      shape: const Border(),
      title: Row(
          mainAxisAlignment: MainAxisAlignment.spaceBetween,
          crossAxisAlignment: CrossAxisAlignment.center,
          children: <Widget>[
            TextTitle(description),
            AreaButton(title, onPressed: onPressed),
          ]),
      children: [builder],
    );
  }
}
