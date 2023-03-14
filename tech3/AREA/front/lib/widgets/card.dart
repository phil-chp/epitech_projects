import 'package:flutter/material.dart';

import 'package:area/types/area.dart';

class AreaServiceCard extends StatelessWidget {
  const AreaServiceCard({
    super.key,
    required this.service,
    this.onPressed,
  });

  final AreaService service;
  final VoidCallback? onPressed;

  @override
  Widget build(BuildContext context) {
    return Card(
      margin: const EdgeInsets.only(bottom: 16),
      child: Padding(
        padding: const EdgeInsets.symmetric(vertical: 8, horizontal: 16),
        child: Row(
          children: [
            Image.network(
              service.icon ??
                  'https://tuddy.de/wp-content/uploads/2018/01/question-mark.png',
              height: 32,
              width: 32,
              fit: BoxFit.cover,
            ),
            const SizedBox(width: 16),
            Expanded(
                child: Text(service.name,
                    style: const TextStyle(
                        fontWeight: FontWeight.bold, fontSize: 21))),
            SizedBox(
              height: 40,
              width: 40,
              child: TextButton(
                style: TextButton.styleFrom(padding: const EdgeInsets.all(0)),
                onPressed: onPressed,
                child: const Icon(Icons.add, size: 32),
              ),
            ),
          ],
        ),
      ),
    );
  }
}
