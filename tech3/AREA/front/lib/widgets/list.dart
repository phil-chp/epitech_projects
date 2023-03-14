import 'package:flutter/material.dart';

import 'package:streaming_shared_preferences/streaming_shared_preferences.dart';

import 'package:area/types/area.dart';
import 'package:area/types/api_response.dart';
import 'package:area/screens/area/view_area.dart';
import 'package:area/services/store.dart';
import 'package:area/services/api.dart' as api;

class AreaList extends StatefulWidget {
  const AreaList({super.key, required this.store});

  final Store store;

  @override
  State<AreaList> createState() => _AreaListState();
}

class _AreaListState extends State<AreaList> {
  @override
  Widget build(BuildContext context) {
    return PreferenceBuilder<List<Area>>(
        preference: widget.store.areas,
        builder: (BuildContext _, List<Area> areaList) {
          return ListView.builder(
            shrinkWrap: true,
            primary: false,
            itemCount: areaList.length,
            itemBuilder: (context, index) {
              return Column(
                children: [
                  GestureDetector(
                    behavior: HitTestBehavior.opaque,
                    onTap: () => Navigator.push(
                        context,
                        MaterialPageRoute(
                            builder: (context) => ViewArea(
                                index: index,
                                store: widget.store,
                                area: areaList[index]))).then(
                      (_) async {
                        ApiResponse resp = await api.Data.getAllAreaFromUser(
                            widget.store.userId.getValue());
                        List<Area> areas = resp.data != null
                            ? List<Area>.from(resp.data! as List)
                            : [];
                        widget.store.areas.setValue(areas);
                        setState(() {});
                      },
                    ),
                    child: ListTile(
                      title: Text(areaList[index].name!),
                      subtitle: Text(areaList[index].description!),
                      trailing: IconButton(
                        icon: const Icon(Icons.delete),
                        onPressed: () {
                          api.Data.deleteUserArea(
                              widget.store.userId.getValue(),
                              areaList[index].id!);
                          widget.store.areas.setValue(
                              widget.store.areas.getValue()
                                ..removeWhere((element) =>
                                    element.name == areaList[index].name));
                        },
                      ),
                    ),
                  ),
                  const Divider(),
                ],
              );
            },
          );
        });
  }
}

class ServiceList extends StatefulWidget {
  const ServiceList({super.key, required this.store, required this.services});

  final Store store;
  final List<AreaService> services;

  @override
  State<ServiceList> createState() => _ServiceListState();
}

class _ServiceListState extends State<ServiceList> {
  @override
  Widget build(BuildContext context) {
    return ListView.builder(
      shrinkWrap: true,
      primary: false,
      itemCount: widget.services.length,
      itemBuilder: (context, index) {
        return Column(
          children: [
            ListTile(
              leading: Image.network(
                widget.services[index].icon ??
                    'https://tuddy.de/wp-content/uploads/2018/01/question-mark.png',
                height: 32,
                width: 32,
                fit: BoxFit.contain,
                alignment: Alignment.centerLeft,
              ),
              title: Text(widget.services[index].name),
              // isThreeLine: true,
              trailing: IconButton(
                  icon: const Icon(Icons.delete),
                  onPressed: unsubscribePopin(index)),
            ),
            const Divider(),
          ],
        );
      },
    );
  }

  Function() unsubscribePopin(index) {
    return () {
      showDialog(
          context: context,
          builder: (BuildContext context) {
            return AlertDialog(
              title: Text(widget.services[index].name),
              content: const Text("Are you sure you want to unsubscribe?"),
              actions: [
                TextButton(
                  child: const Text("Cancel"),
                  onPressed: () {
                    Navigator.of(context).pop();
                  },
                ),
                TextButton(
                  child: const Text("Unsubscribe"),
                  onPressed: () {
                    api.Data.unsubscribeService(widget.store.userId.getValue(),
                        widget.services[index].id);
                    List<AreaService> services =
                        widget.store.services.getValue();
                    services
                        .firstWhere((service) =>
                            service.name == widget.services[index].name)
                        .linked = false;
                    // services[index].linked = false;
                    widget.store.services.setValue(services);
                    Navigator.of(context).pop();
                  },
                ),
              ],
            );
          });
    };
  }
}
