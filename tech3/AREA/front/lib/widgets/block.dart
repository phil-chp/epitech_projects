import 'package:flutter/material.dart';

import 'package:area/types/area.dart';
import 'package:area/widgets/text.dart';

class AreaBlock extends StatelessWidget {
  const AreaBlock({super.key, required this.area});

  final Area area;

  @override
  Widget build(BuildContext context) {
    return Column(crossAxisAlignment: CrossAxisAlignment.start, children: [
      const Padding(
        padding: EdgeInsets.symmetric(vertical: 16.0),
        child: Divider(),
      ),
      area.action != null
          ? ListTile(
              title: const Text("Action",
                  style: TextStyle(fontSize: 20, fontWeight: FontWeight.bold)),
              subtitle: TextHeritage.fromAreaEvent(area.action!),
            )
          : const TextPadded("Choose an action..."),
      const Padding(
        padding: EdgeInsets.symmetric(vertical: 16.0),
        child: Divider(),
      ),
      area.reaction != null
          ? ListTile(
              title: const Text("Reaction",
                  style: TextStyle(fontSize: 20, fontWeight: FontWeight.bold)),
              subtitle: TextHeritage.fromAreaEvent(area.reaction!),
            )
          : const TextPadded("Choose a reaction..."),
      const Padding(
        padding: EdgeInsets.symmetric(vertical: 16.0),
        child: Divider(),
      ),
    ]);
  }
}
