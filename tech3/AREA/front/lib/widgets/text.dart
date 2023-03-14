import 'package:flutter/material.dart';

import 'package:area/types/area.dart';

class TextTitle extends StatelessWidget {
  const TextTitle(this.data, {super.key});

  final String data;

  @override
  Widget build(BuildContext context) {
    return Text(data,
        style: const TextStyle(
          fontWeight: FontWeight.bold,
          fontSize: 24,
        ));
  }
}

class TextSubtitle extends StatelessWidget {
  const TextSubtitle(this.data, {super.key});

  final String data;

  @override
  Widget build(BuildContext context) {
    return Text(data,
        style: const TextStyle(
          color: Colors.grey,
          fontSize: 16,
        ));
  }
}

class TextHeritage extends StatelessWidget {
  const TextHeritage({super.key, required this.parent, required this.child});
  TextHeritage.fromAreaEvent(AreaEvent event, {super.key})
      : parent = event.service!,
        child = event.name;

  final String parent;
  final String child;

  @override
  Widget build(BuildContext context) {
    return Row(children: [
      Text(parent, style: const TextStyle(fontSize: 16)),
      const SizedBox(width: 6),
      const Icon(Icons.arrow_right_alt, size: 26),
      const SizedBox(width: 10),
      Text(child, style: const TextStyle(fontSize: 16)),
    ]);
  }
}

class TextPadded extends StatelessWidget {
  const TextPadded(this.data, {super.key});

  final String data;

  @override
  Widget build(BuildContext context) {
    return Padding(padding: const EdgeInsets.all(16.0), child: Text(data));
  }
}
