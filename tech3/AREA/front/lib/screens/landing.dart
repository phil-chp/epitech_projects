import 'package:flutter/material.dart';

import 'package:streaming_shared_preferences/streaming_shared_preferences.dart';

import 'package:area/types/area.dart';
import 'package:area/types/api_response.dart';
import 'package:area/services/store.dart';
import 'package:area/services/api.dart' as api;
import 'package:area/widgets/list.dart';
import 'package:area/widgets/expansion_tile.dart';
import 'package:area/screens/area/edit_area.dart';
import 'package:area/screens/subscribe_services.dart';

class Landing extends StatefulWidget {
  const Landing({super.key, required this.store});

  final Store store;

  @override
  State<Landing> createState() => _LandingState();
}

class _LandingState extends State<Landing> {
  @override
  Widget build(BuildContext context) {
    return Container(
      padding: const EdgeInsets.all(24),
      child: SingleChildScrollView(
        child: Column(
          crossAxisAlignment: CrossAxisAlignment.start,
          children: [
            _yourAREAs(),
            const SizedBox(height: 16.0),
            _yourServices(),
          ],
        ),
      ),
    );
  }

  AREAExpansionTile _yourAREAs() {
    return AREAExpansionTile(
      title: "AREA",
      description: "Your AREA's",
      builder: PreferenceBuilder<List<Area>>(
        preference: widget.store.areas,
        builder: (BuildContext _, List<Area> areaList) {
          if (areaList.isNotEmpty) {
            return AreaList(store: widget.store);
          } else {
            return const Text("You have no AREA's yet.");
          }
        },
      ),
      onPressed: () async {
        await Navigator.push(
            context,
            MaterialPageRoute(
                builder: (context) => EditArea(store: widget.store))).then(
          (_) async {
            ApiResponse resp = await api.Data.getAllAreaFromUser(
                widget.store.userId.getValue());
            List<Area> areas =
                resp.data != null ? List<Area>.from(resp.data! as List) : [];
            widget.store.areas.setValue(areas);
            setState(() {});
          },
        );
      },
      initiallyExpanded: true,
    );
  }

  AREAExpansionTile _yourServices() {
    return AREAExpansionTile(
      title: "Service",
      description: "Your Services",
      builder: PreferenceBuilder<List<AreaService>>(
        preference: widget.store.services,
        builder: (BuildContext _, List<AreaService> services) {
          final List<AreaService> userServices = services.isNotEmpty
              ? services
                  .where((service) => service.linked)
                  .toList(growable: false)
              : [];
          if (userServices.isNotEmpty) {
            return ServiceList(store: widget.store, services: userServices);
          } else {
            return const Text("You have not subscribed to any service.");
          }
        },
      ),
      onPressed: () async {
        await Navigator.push(
            context,
            MaterialPageRoute(
                builder: (context) => SubscribeServices(store: widget.store)));
      },
      initiallyExpanded: true,
    );
  }
}
