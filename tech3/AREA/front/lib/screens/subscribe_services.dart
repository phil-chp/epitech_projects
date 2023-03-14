import 'package:flutter/material.dart';

import 'package:streaming_shared_preferences/streaming_shared_preferences.dart';

import 'package:area/widgets/card.dart';
import 'package:area/services/store.dart';
import 'package:area/config.dart';
import 'package:area/services/api.dart' as api;
import 'package:area/types/area.dart';
import 'package:area/types/api_response.dart';
import 'package:url_launcher/url_launcher.dart';

class SubscribeServices extends StatefulWidget {
  const SubscribeServices({Key? key, required this.store}) : super(key: key);

  final Store store;

  @override
  State<SubscribeServices> createState() => _SubscribeServicesState();
}

class _SubscribeServicesState extends State<SubscribeServices> {
  Future<void> subscribeService(BuildContext context, String name) async {
    final uid = widget.store.userId.getValue();
    final Uri url = Uri.parse('$BACKEND_URL/api/auth/$name?uid=$uid');
    launchUrl(url);
    Navigator.pop(context);
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: const Text("Subscribe to services",
            style: TextStyle(fontWeight: FontWeight.bold)),
      ),
      body: Container(
        padding: const EdgeInsets.all(24),
        child: PreferenceBuilder<List<AreaService>>(
          preference: widget.store.services,
          builder: (_, List<AreaService> services) {
            final List<AreaService> notUserServices =
                services.where((service) => !service.linked).toList();

            if (services.isNotEmpty && notUserServices.isNotEmpty) {
              return ListView.builder(
                itemCount: notUserServices.length,
                itemBuilder: (__, int index) {
                  return AreaServiceCard(
                    service: notUserServices[index],
                    onPressed:
                        subscribeFormPopin(notUserServices[index], index),
                  );
                },
              );
            } else {
              WidgetsBinding.instance.addPostFrameCallback((_) {
                ScaffoldMessenger.of(context).showSnackBar(const SnackBar(
                    content: Text(
                        "You have subscribed to all availabed Services, there are none left.")));
                Navigator.pop(context);
              });
              return const Text("We couldn't find any services for you.");
            }
          },
        ),
      ),
    );
  }

  VoidCallback subscribeFormPopin(AreaService service, int index) {
    final AreaService data = AreaService(id: service.id, name: service.name);

    return () => showDialog(
        context: context,
        builder: (context) => AlertDialog(
              title: Text("Subscribe to ${service.name}"),
              actions: [
                TextButton(
                  child: const Text("Cancel"),
                  onPressed: () => Navigator.pop(context),
                ),
                TextButton(
                  child: const Text("Subscribe"),
                  onPressed: () async {
                    subscribeService(context, service.name);

                    ApiResponse response = await api.Data.subscribeService(
                        data, widget.store.userId.getValue());
                    if (response.data != null) {
                      List<AreaService> services =
                          List.from(widget.store.services.getValue());
                      services
                          .firstWhere((service) => service.name == data.name)
                          .linked = true;
                      List<AreaService> refreshServices = [...services];
                      widget.store.services.setValue(refreshServices);
                    }
                    if (context.mounted) Navigator.pop(context);
                  },
                ),
              ],
            ));
  }
}
