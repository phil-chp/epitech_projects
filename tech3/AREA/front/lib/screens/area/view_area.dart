import 'package:flutter/material.dart';

// import 'package:streaming_shared_preferences/stsreaming_shared_preferences.dart';

import 'package:area/types/area.dart';
import 'package:area/types/trigger.dart';
import 'package:area/types/api_response.dart';
import 'package:area/widgets/text.dart';
import 'package:area/widgets/block.dart';
import 'package:area/services/store.dart';
import 'package:area/services/api.dart' as api;
import 'package:area/screens/area/edit_area.dart';

class ViewArea extends StatefulWidget {
  const ViewArea(
      {super.key,
      required this.index,
      required this.store,
      required this.area});

  final int index;
  final Store store;
  final Area area;

  @override
  State<ViewArea> createState() => _ViewAreaState();
}

class _ViewAreaState extends State<ViewArea> {
  late Future<Trigger> _trigger;

  @override
  void initState() {
    super.initState();

    _trigger = getTrigger(widget.store.userId.getValue(), widget.area.id);
  }

  Future<Trigger> getTrigger(userId, String? triggerId) async {
    if (triggerId == null) {
      return Future.value(Trigger(
          triggerId: "",
          idArea: "",
          idAction: 0,
          idReaction: 0,
          userId: "",
          status: 0));
    }
    final ApiResponse resp = await api.Data.getTriggerById(userId, triggerId);
    return Future.value(resp.data as Trigger);
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: const Text("Edit AREA",
            style: TextStyle(fontWeight: FontWeight.bold)),
      ),
      body: Container(
        padding: const EdgeInsets.all(24),
        child: widget.area.id == null
            ? const Text("No area selected")
            : FutureBuilder<Trigger>(
                future: _trigger,
                builder: (context, snapshot) {
                  if (snapshot.hasData) {
                    return Wrap(
                      runSpacing: 16.0,
                      spacing: 16.0,
                      crossAxisAlignment: WrapCrossAlignment.center,
                      children: [
                        Container(
                          width: 12,
                          height: 12,
                          decoration: BoxDecoration(
                            color: snapshot.data!.status != 2
                                ? Colors.green
                                : Colors.red,
                            shape: BoxShape.circle,
                          ),
                        ),
                        Column(
                            crossAxisAlignment: CrossAxisAlignment.start,
                            children: [
                              TextTitle(widget.area.name!),
                              TextSubtitle(widget.area.description!),
                            ]),
                        Row(children: [
                          const SizedBox(height: 16.0),
                          Text(
                              snapshot.data!.status != 2
                                  ? "Currently running..."
                                  : "Currently stopped.",
                              style: const TextStyle(
                                  fontStyle: FontStyle.italic,
                                  color: Colors.grey)),
                        ]),
                        AreaBlock(area: widget.area),
                        Column(
                            crossAxisAlignment: CrossAxisAlignment.start,
                            children: [
                              Text(
                                  snapshot.data!.lastTriggered == "Never"
                                      ? "Never executed before"
                                      : "Last executed on ${snapshot.data!.lastTriggered}",
                                  style: const TextStyle(
                                      fontStyle: FontStyle.italic)),
                              const SizedBox(height: 16.0),
                              snapshot.data!.lastTriggered != "Never"
                                  ? Text(
                                      "Executed ${snapshot.data!.nbTimesTriggered} times",
                                      style: const TextStyle(
                                          fontStyle: FontStyle.italic))
                                  : const SizedBox.shrink(),
                            ]),
                      ],
                    );
                  } else if (snapshot.hasError) {
                    return Text("${snapshot.error}");
                  }
                  return const CircularProgressIndicator();
                },
              ),
      ),
      floatingActionButton: FloatingActionButton(
        onPressed: () async {
          await Navigator.push(
              context,
              MaterialPageRoute(
                  builder: (context) =>
                      EditArea(store: widget.store, index: widget.index)));
        },
        backgroundColor: Colors.red[50],
        foregroundColor: Colors.red[900],
        shape: const CircleBorder(),
        child: const Icon(Icons.edit),
      ),
    );
  }
}
