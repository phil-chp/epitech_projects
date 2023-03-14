/*
** EPITECH PROJECT, 2022
** Indie-Studio (Workspace)
** File description:
** KeyboardKeys
*/

#ifndef KEYBOARDKEYS_HPP_
    #define KEYBOARDKEYS_HPP_
    #include <map>
    #include <string>

namespace rl {
    enum KeyboardKeys {
        KEY_NULL            = 0,        // Key: NULL, used for no key pressed
        // Alphanumeric keys
        KEY_APOSTROPHE      = 39,       // Key: '
        KEY_COMMA           = 44,       // Key: ,
        KEY_MINUS           = 45,       // Key: -
        KEY_PERIOD          = 46,       // Key: .
        KEY_SLASH           = 47,       // Key: /
        KEY_ZERO            = 48,       // Key: 0
        KEY_ONE             = 49,       // Key: 1
        KEY_TWO             = 50,       // Key: 2
        KEY_THREE           = 51,       // Key: 3
        KEY_FOUR            = 52,       // Key: 4
        KEY_FIVE            = 53,       // Key: 5
        KEY_SIX             = 54,       // Key: 6
        KEY_SEVEN           = 55,       // Key: 7
        KEY_EIGHT           = 56,       // Key: 8
        KEY_NINE            = 57,       // Key: 9
        KEY_M               = 59,       // Key: ;
        KEY_EQUAL           = 61,       // Key: =
        KEY_Q               = 65,       // Key: A | a
        KEY_B               = 66,       // Key: B | b
        KEY_C               = 67,       // Key: C | c
        KEY_D               = 68,       // Key: D | d
        KEY_E               = 69,       // Key: E | e
        KEY_F               = 70,       // Key: F | f
        KEY_G               = 71,       // Key: G | g
        KEY_H               = 72,       // Key: H | h
        KEY_I               = 73,       // Key: I | i
        KEY_J               = 74,       // Key: J | j
        KEY_K               = 75,       // Key: K | k
        KEY_L               = 76,       // Key: L | l
        KEY_SEMICOLON       = 77,       // Key: M | m
        KEY_N               = 78,       // Key: N | n
        KEY_O               = 79,       // Key: O | o
        KEY_P               = 80,       // Key: P | p
        KEY_A               = 81,       // Key: Q | q
        KEY_R               = 82,       // Key: R | r
        KEY_S               = 83,       // Key: S | s
        KEY_T               = 84,       // Key: T | t
        KEY_U               = 85,       // Key: U | u
        KEY_V               = 86,       // Key: V | v
        KEY_Z               = 87,       // Key: W | w
        KEY_X               = 88,       // Key: X | x
        KEY_Y               = 89,       // Key: Y | y
        KEY_W               = 90,       // Key: Z | z
        KEY_LEFT_BRACKET    = 91,       // Key: [
        KEY_BACKSLASH       = 92,       // Key: '\'
        KEY_RIGHT_BRACKET   = 93,       // Key: ]
        KEY_GRAVE           = 96,       // Key: `
        // Function keys
        KEY_SPACE           = 32,       // Key: Space
        KEY_ESCAPE          = 256,      // Key: Esc
        KEY_ENTER           = 257,      // Key: Enter
        KEY_TAB             = 258,      // Key: Tab
        KEY_BACKSPACE       = 259,      // Key: Backspace
        KEY_INSERT          = 260,      // Key: Ins
        KEY_DELETE          = 261,      // Key: Del
        KEY_RIGHT           = 262,      // Key: Cursor right
        KEY_LEFT            = 263,      // Key: Cursor left
        KEY_DOWN            = 264,      // Key: Cursor down
        KEY_UP              = 265,      // Key: Cursor up
        KEY_PAGE_UP         = 266,      // Key: Page up
        KEY_PAGE_DOWN       = 267,      // Key: Page down
        KEY_HOME            = 268,      // Key: Home
        KEY_END             = 269,      // Key: End
        KEY_CAPS_LOCK       = 280,      // Key: Caps lock
        KEY_SCROLL_LOCK     = 281,      // Key: Scroll down
        KEY_NUM_LOCK        = 282,      // Key: Num lock
        KEY_PRINT_SCREEN    = 283,      // Key: Print screen
        KEY_PAUSE           = 284,      // Key: Pause
        KEY_F1              = 290,      // Key: F1
        KEY_F2              = 291,      // Key: F2
        KEY_F3              = 292,      // Key: F3
        KEY_F4              = 293,      // Key: F4
        KEY_F5              = 294,      // Key: F5
        KEY_F6              = 295,      // Key: F6
        KEY_F7              = 296,      // Key: F7
        KEY_F8              = 297,      // Key: F8
        KEY_F9              = 298,      // Key: F9
        KEY_F10             = 299,      // Key: F10
        KEY_F11             = 300,      // Key: F11
        KEY_F12             = 301,      // Key: F12
        KEY_LEFT_SHIFT      = 340,      // Key: Shift left
        KEY_LEFT_CONTROL    = 341,      // Key: Control left
        KEY_LEFT_ALT        = 342,      // Key: Alt left
        KEY_LEFT_SUPER      = 343,      // Key: Super left
        KEY_RIGHT_SHIFT     = 344,      // Key: Shift right
        KEY_RIGHT_CONTROL   = 345,      // Key: Control right
        KEY_RIGHT_ALT       = 346,      // Key: Alt right
        KEY_RIGHT_SUPER     = 347,      // Key: Super right
        KEY_KB_MENU         = 348,      // Key: KB menu
        // Keypad keys
        KEY_KP_0            = 320,      // Key: Keypad 0
        KEY_KP_1            = 321,      // Key: Keypad 1
        KEY_KP_2            = 322,      // Key: Keypad 2
        KEY_KP_3            = 323,      // Key: Keypad 3
        KEY_KP_4            = 324,      // Key: Keypad 4
        KEY_KP_5            = 325,      // Key: Keypad 5
        KEY_KP_6            = 326,      // Key: Keypad 6
        KEY_KP_7            = 327,      // Key: Keypad 7
        KEY_KP_8            = 328,      // Key: Keypad 8
        KEY_KP_9            = 329,      // Key: Keypad 9
        KEY_KP_DECIMAL      = 330,      // Key: Keypad .
        KEY_KP_DIVIDE       = 331,      // Key: Keypad /
        KEY_KP_MULTIPLY     = 332,      // Key: Keypad *
        KEY_KP_SUBTRACT     = 333,      // Key: Keypad -
        KEY_KP_ADD          = 334,      // Key: Keypad +
        KEY_KP_ENTER        = 335,      // Key: Keypad Enter
        KEY_KP_EQUAL        = 336,      // Key: Keypad =
        // Android key buttons
        KEY_BACK            = 4,        // Key: Android back button
        KEY_MENU            = 82,       // Key: Android menu button
        KEY_VOLUME_UP       = 24,       // Key: Android volume up button
        KEY_VOLUME_DOWN     = 25        // Key: Android volume down button
    };

    static std::map<KeyboardKeys, std::string> KeyboardKeysString = {
            std::make_pair(KEY_A, "A"),
            std::make_pair(KEY_B, "B"),
            std::make_pair(KEY_C, "C"),
            std::make_pair(KEY_D, "D"),
            std::make_pair(KEY_E, "E"),
            std::make_pair(KEY_F, "F"),
            std::make_pair(KEY_G, "G"),
            std::make_pair(KEY_H, "H"),
            std::make_pair(KEY_I, "I"),
            std::make_pair(KEY_J, "J"),
            std::make_pair(KEY_K, "K"),
            std::make_pair(KEY_L, "L"),
            std::make_pair(KEY_M, "M"),
            std::make_pair(KEY_N, "N"),
            std::make_pair(KEY_O, "O"),
            std::make_pair(KEY_P, "P"),
            std::make_pair(KEY_Q, "Q"),
            std::make_pair(KEY_R, "R"),
            std::make_pair(KEY_S, "S"),
            std::make_pair(KEY_T, "T"),
            std::make_pair(KEY_U, "U"),
            std::make_pair(KEY_V, "V"),
            std::make_pair(KEY_W, "W"),
            std::make_pair(KEY_X, "X"),
            std::make_pair(KEY_Y, "Y"),
            std::make_pair(KEY_Z, "Z"),
            std::make_pair(KEY_UP, "UP"),
            std::make_pair(KEY_DOWN, "DOWN"),
            std::make_pair(KEY_LEFT, "LEFT"),
            std::make_pair(KEY_RIGHT, "RIGHT"),
            std::make_pair(KEY_ENTER, "ENTER"),
            std::make_pair(KEY_ESCAPE, "ESCAPE"),
            std::make_pair(KEY_SPACE, "SPACE"),
            std::make_pair(KEY_BACKSPACE, "BACKSPACE"),
            std::make_pair(KEY_TAB, "TAB"),
            std::make_pair(KEY_APOSTROPHE, "'"),
            std::make_pair(KEY_COMMA, ","),
            std::make_pair(KEY_MINUS, "-"),
            std::make_pair(KEY_PERIOD, "."),
            std::make_pair(KEY_SLASH, "/"),
            std::make_pair(KEY_ZERO, "0"),
            std::make_pair(KEY_ONE, "1"),
            std::make_pair(KEY_TWO, "2"),
            std::make_pair(KEY_THREE, "3"),
            std::make_pair(KEY_FOUR, "4"),
            std::make_pair(KEY_FIVE, "5"),
            std::make_pair(KEY_SIX, "6"),
            std::make_pair(KEY_SEVEN, "7"),
            std::make_pair(KEY_EIGHT, "8"),
            std::make_pair(KEY_NINE, "9"),
            std::make_pair(KEY_SEMICOLON, ";"),
            std::make_pair(KEY_EQUAL, "="),
            std::make_pair(KEY_LEFT_BRACKET, "["),
            std::make_pair(KEY_BACKSLASH, "\\"),
            std::make_pair(KEY_RIGHT_BRACKET, "]"),
            std::make_pair(KEY_GRAVE, "`" ),
            std::make_pair(KEY_SPACE, "SPACE"),
            std::make_pair(KEY_ESCAPE, "ESCAPE"),
            std::make_pair(KEY_ENTER, "ENTER"),
            std::make_pair(KEY_TAB, "TAB"),
            std::make_pair(KEY_BACKSPACE, "BACKSPACE"),
            std::make_pair(KEY_INSERT, "INSERT"),
            std::make_pair(KEY_DELETE, "DELETE"),
            std::make_pair(KEY_RIGHT, "RIGHT"),
            std::make_pair(KEY_LEFT, "LEFT"),
            std::make_pair(KEY_DOWN, "DOWN"),
            std::make_pair(KEY_UP, "UP"),
            std::make_pair(KEY_PAGE_UP, "PAGE_UP"),
            std::make_pair(KEY_PAGE_DOWN, "PAGE_DOWN"),
            std::make_pair(KEY_HOME, "HOME"),
            std::make_pair(KEY_END, "END"),
            std::make_pair(KEY_CAPS_LOCK, "CAPS_LOCK"),
            std::make_pair(KEY_SCROLL_LOCK, "SCROLL_LOCK"),
            std::make_pair(KEY_NUM_LOCK, "NUM_LOCK"),
            std::make_pair(KEY_PRINT_SCREEN, "PRINT_SCREEN"),
            std::make_pair(KEY_PAUSE, "PAUSE"),
            std::make_pair(KEY_F1, "F1"),
            std::make_pair(KEY_F2, "F2"),
            std::make_pair(KEY_F3, "F3"),
            std::make_pair(KEY_F4, "F4"),
            std::make_pair(KEY_F5, "F5"),
            std::make_pair(KEY_F6, "F6"),
            std::make_pair(KEY_F7, "F7"),
            std::make_pair(KEY_F8, "F8"),
            std::make_pair(KEY_F9, "F9"),
            std::make_pair(KEY_F10, "F10"),
            std::make_pair(KEY_F11, "F11"),
            std::make_pair(KEY_F12, "F12"),
            std::make_pair(KEY_LEFT_SHIFT, "LEFT_SHIFT"),
            std::make_pair(KEY_LEFT_CONTROL, "LEFT_CONTROL"),
            std::make_pair(KEY_LEFT_ALT, "LEFT_ALT"),
            std::make_pair(KEY_LEFT_SUPER, "LEFT_SUPER"),
            std::make_pair(KEY_RIGHT_SHIFT, "RIGHT_SHIFT"),
            std::make_pair(KEY_RIGHT_CONTROL, "RIGHT_CONTROL"),
            std::make_pair(KEY_RIGHT_ALT, "RIGHT_ALT"),
            std::make_pair(KEY_RIGHT_SUPER, "RIGHT_SUPER"),
            std::make_pair(KEY_KB_MENU, "KB_MENU"),
            std::make_pair(KEY_KP_0, "KP_0"),
            std::make_pair(KEY_KP_1, "KP_1"),
            std::make_pair(KEY_KP_2, "KP_2"),
            std::make_pair(KEY_KP_3, "KP_3"),
            std::make_pair(KEY_KP_4, "KP_4"),
            std::make_pair(KEY_KP_5, "KP_5"),
            std::make_pair(KEY_KP_6, "KP_6"),
            std::make_pair(KEY_KP_7, "KP_7"),
            std::make_pair(KEY_KP_8, "KP_8"),
            std::make_pair(KEY_KP_9, "KP_9"),
            std::make_pair(KEY_KP_DECIMAL, "KP_DECIMAL"),
            std::make_pair(KEY_KP_DIVIDE, "KP_DIVIDE"),
            std::make_pair(KEY_KP_MULTIPLY, "KP_MULTIPLY"),
            std::make_pair(KEY_KP_SUBTRACT, "KP_SUBTRACT"),
            std::make_pair(KEY_KP_ADD, "KP_ADD"),
            std::make_pair(KEY_KP_ENTER, "KP_ENTER"),
            std::make_pair(KEY_KP_EQUAL, "KP_EQUAL"),
            std::make_pair(KEY_BACK, "BACK"),
            std::make_pair(KEY_MENU, "MENU"),
            std::make_pair(KEY_VOLUME_UP, "VOLUME_UP"),
            std::make_pair(KEY_VOLUME_DOWN, "VOLUME_DOWN"),
    };
    static std::map<KeyboardKeys, KeyboardKeys > qwerAzerty = {
            {KEY_Q, KEY_A},
            {KEY_W, KEY_Z},
            {KEY_E, KEY_E},
            {KEY_R, KEY_R},
            {KEY_T, KEY_T},
            {KEY_Y, KEY_Y},
            {KEY_U, KEY_U},
            {KEY_I, KEY_I},
            {KEY_O, KEY_O},
            {KEY_P, KEY_P},
            {KEY_A, KEY_Q},
            {KEY_S, KEY_S},
            {KEY_D, KEY_D},
            {KEY_F, KEY_F},
            {KEY_G, KEY_G},
            {KEY_H, KEY_H},
            {KEY_J, KEY_J},
            {KEY_K, KEY_K},
            {KEY_L, KEY_L},
            {KEY_Z, KEY_W},
            {KEY_X, KEY_X},
            {KEY_C, KEY_C},
            {KEY_V, KEY_V},
            {KEY_B, KEY_B},
            {KEY_N, KEY_N},
            {KEY_SEMICOLON, KEY_M},
            {KEY_UP, KEY_UP},
            {KEY_DOWN, KEY_DOWN},
            {KEY_LEFT, KEY_LEFT},
            {KEY_RIGHT, KEY_RIGHT},
            {KEY_ENTER, KEY_ENTER},
            {KEY_ESCAPE, KEY_ESCAPE},
            {KEY_SPACE, KEY_SPACE},
            {KEY_BACKSPACE, KEY_BACKSPACE},
            {KEY_TAB, KEY_TAB},
            {KEY_APOSTROPHE, KEY_APOSTROPHE},
            {KEY_COMMA, KEY_COMMA},
            {KEY_MINUS, KEY_MINUS},
            {KEY_PERIOD, KEY_PERIOD},
            {KEY_SLASH, KEY_SLASH},
            {KEY_ZERO, KEY_ZERO},
            {KEY_ONE, KEY_ONE},
            {KEY_TWO, KEY_TWO},
            {KEY_THREE, KEY_THREE},
            {KEY_FOUR, KEY_FOUR},
            {KEY_FIVE, KEY_FIVE},
            {KEY_SIX, KEY_SIX},
            {KEY_SEVEN, KEY_SEVEN},
            {KEY_EIGHT, KEY_EIGHT},
            {KEY_NINE, KEY_NINE},
            {KEY_SEMICOLON, KEY_SEMICOLON},
            {KEY_EQUAL, KEY_EQUAL},
            {KEY_LEFT_BRACKET, KEY_LEFT_BRACKET},
            {KEY_BACKSLASH, KEY_BACKSLASH},
            {KEY_RIGHT_BRACKET, KEY_RIGHT_BRACKET},
            {KEY_GRAVE, KEY_GRAVE },
            {KEY_SPACE, KEY_SPACE},
            { KEY_ESCAPE, KEY_ESCAPE },
            { KEY_ENTER, KEY_ENTER },
            { KEY_TAB, KEY_TAB },
            { KEY_BACKSPACE, KEY_BACKSPACE },
            { KEY_INSERT, KEY_INSERT },
            { KEY_DELETE, KEY_DELETE },
            { KEY_RIGHT, KEY_RIGHT },
            { KEY_LEFT, KEY_LEFT },
            { KEY_DOWN, KEY_DOWN },
            { KEY_UP, KEY_UP },
            { KEY_PAGE_UP, KEY_PAGE_UP },
            { KEY_PAGE_DOWN, KEY_PAGE_DOWN },
            { KEY_HOME, KEY_HOME },
            { KEY_END, KEY_END },
            { KEY_CAPS_LOCK, KEY_CAPS_LOCK },
            { KEY_SCROLL_LOCK, KEY_SCROLL_LOCK },
            { KEY_NUM_LOCK, KEY_NUM_LOCK },
            { KEY_PRINT_SCREEN, KEY_PRINT_SCREEN },
            { KEY_PAUSE, KEY_PAUSE },
            { KEY_F1, KEY_F1 },
            { KEY_F2, KEY_F2 },
            { KEY_F3, KEY_F3 },
            { KEY_F4, KEY_F4 },
            { KEY_F5, KEY_F5 },
            { KEY_F6, KEY_F6 },
            { KEY_F7, KEY_F7 },
            { KEY_F8, KEY_F8 },
            { KEY_F9, KEY_F9 },
            { KEY_F10, KEY_F10 },
            { KEY_F11, KEY_F11 },
            { KEY_F12, KEY_F12 },
            { KEY_LEFT_SHIFT, KEY_LEFT_SHIFT },
            { KEY_LEFT_CONTROL, KEY_LEFT_CONTROL },
            { KEY_LEFT_ALT, KEY_LEFT_ALT },
            { KEY_LEFT_SUPER, KEY_LEFT_SUPER },
            { KEY_RIGHT_SHIFT, KEY_RIGHT_SHIFT },
            { KEY_RIGHT_CONTROL, KEY_RIGHT_CONTROL },
            { KEY_RIGHT_ALT, KEY_RIGHT_ALT },
            { KEY_RIGHT_SUPER, KEY_RIGHT_SUPER },
            { KEY_KB_MENU, KEY_KB_MENU },
            // Keypad keys
            { KEY_KP_0, KEY_KP_0 },
            { KEY_KP_1, KEY_KP_1 },
            { KEY_KP_2, KEY_KP_2 },
            { KEY_KP_3, KEY_KP_3 },
            { KEY_KP_4, KEY_KP_4 },
            { KEY_KP_5, KEY_KP_5 },
            { KEY_KP_6, KEY_KP_6 },
            { KEY_KP_7, KEY_KP_7 },
            { KEY_KP_8, KEY_KP_8 },
            { KEY_KP_9, KEY_KP_9 },
            { KEY_KP_DECIMAL, KEY_KP_DECIMAL },
            { KEY_KP_DIVIDE, KEY_KP_DIVIDE },
            { KEY_KP_MULTIPLY, KEY_KP_MULTIPLY },
            { KEY_KP_SUBTRACT, KEY_KP_SUBTRACT },
            { KEY_KP_ADD, KEY_KP_ADD },
            { KEY_KP_ENTER, KEY_KP_ENTER },
            { KEY_KP_EQUAL, KEY_KP_EQUAL },
            // Android key buttons
            { KEY_BACK, KEY_BACK },
            { KEY_MENU, KEY_MENU },
            { KEY_VOLUME_UP, KEY_VOLUME_UP },
            { KEY_VOLUME_DOWN, KEY_VOLUME_DOWN },
    };
}

#endif /* !KEYBOARDKEYS_HPP_ */
