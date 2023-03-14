import 'package:area/types/area.dart';

class Validation {
  static String? isNotNull(String? value) {
    return (value != null && value.isEmpty) ? 'Field cannot be empty' : null;
  }

  static String? isEmail(String? value) {
    if (value == null || value.isEmpty) {
      return 'Field cannot be empty';
    }
    if (!RegExp(r'^.+@[a-zA-Z]+\.{1}[a-zA-Z]+(\.{0,1}[a-zA-Z]+)\s*$')
        .hasMatch(value)) {
      return 'Please enter a valid email';
    }
    return null;
  }

  static String? isAction<T extends AreaEvent>(T? action) {
    return (action != null && action.id == -1) ? "Action is required" : null;
  }

  static String? isReaction<T extends AreaEvent>(T? reaction) {
    return (reaction != null && reaction.id == -1)
        ? "Reaction is required"
        : null;
  }
}
