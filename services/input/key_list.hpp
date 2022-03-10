#pragma once

// The codes are copied from SDL. Stripped of their prefix and put into a namespace to prevent pollution

namespace Scancode {
	enum Scancode {
		UNKNOWN = 0,

		/**
		 *  \name Usage page 0x07
		 *
		 *  These values are from usage page 0x07 (USB keyboard page).
		 */
		/* @{ */

		A = 4,
		B = 5,
		C = 6,
		D = 7,
		E = 8,
		F = 9,
		G = 10,
		H = 11,
		I = 12,
		J = 13,
		K = 14,
		L = 15,
		M = 16,
		N = 17,
		O = 18,
		P = 19,
		Q = 20,
		R = 21,
		S = 22,
		T = 23,
		U = 24,
		V = 25,
		W = 26,
		X = 27,
		Y = 28,
		Z = 29,

		NUM_1 = 30,
		NUM_2 = 31,
		NUM_3 = 32,
		NUM_4 = 33,
		NUM_5 = 34,
		NUM_6 = 35,
		NUM_7 = 36,
		NUM_8 = 37,
		NUM_9 = 38,
		NUM_0 = 39,

		RETURN = 40,
		ESCAPE = 41,
		BACKSPACE = 42,
		TAB = 43,
		SPACE = 44,

		MINUS = 45,
		EQUALS = 46,
		LEFTBRACKET = 47,
		RIGHTBRACKET = 48,
		BACKSLASH = 49, /**< Located at the lower left of the return
                                  *   key on ISO keyboards and at the right end
                                  *   of the QWERTY row on ANSI keyboards.
                                  *   Produces REVERSE SOLIDUS (backslash) and
                                  *   VERTICAL LINE in a US layout, REVERSE
                                  *   SOLIDUS and VERTICAL LINE in a UK Mac
                                  *   layout, NUMBER SIGN and TILDE in a UK
                                  *   Windows layout, DOLLAR SIGN and POUND SIGN
                                  *   in a Swiss German layout, NUMBER SIGN and
                                  *   APOSTROPHE in a German layout, GRAVE
                                  *   ACCENT and POUND SIGN in a French Mac
                                  *   layout, and ASTERISK and MICRO SIGN in a
                                  *   French Windows layout.
                                  */
		NONUSHASH = 50, /**< ISO USB keyboards actually use this code
                                  *   instead of 49 for the same key, but all
                                  *   OSes I've seen treat the two codes
                                  *   identically. So, as an implementor, unless
                                  *   your keyboard generates both of those
                                  *   codes and your OS treats them differently,
                                  *   you should generate BACKSLASH
                                  *   instead of this code. As a user, you
                                  *   should not rely on this code because SDL
                                  *   will never generate it with most (all?)
                                  *   keyboards.
                                  */
		SEMICOLON = 51,
		APOSTROPHE = 52,
		GRAVE = 53, /**< Located in the top left corner (on both ANSI
                              *   and ISO keyboards). Produces GRAVE ACCENT and
                              *   TILDE in a US Windows layout and in US and UK
                              *   Mac layouts on ANSI keyboards, GRAVE ACCENT
                              *   and NOT SIGN in a UK Windows layout, SECTION
                              *   SIGN and PLUS-MINUS SIGN in US and UK Mac
                              *   layouts on ISO keyboards, SECTION SIGN and
                              *   DEGREE SIGN in a Swiss German layout (Mac:
                              *   only on ISO keyboards), CIRCUMFLEX ACCENT and
                              *   DEGREE SIGN in a German layout (Mac: only on
                              *   ISO keyboards), SUPERSCRIPT TWO and TILDE in a
                              *   French Windows layout, COMMERCIAL AT and
                              *   NUMBER SIGN in a French Mac layout on ISO
                              *   keyboards, and LESS-THAN SIGN and GREATER-THAN
                              *   SIGN in a Swiss German, German, or French Mac
                              *   layout on ANSI keyboards.
                              */
		COMMA = 54,
		PERIOD = 55,
		SLASH = 56,

		CAPSLOCK = 57,

		F1 = 58,
		F2 = 59,
		F3 = 60,
		F4 = 61,
		F5 = 62,
		F6 = 63,
		F7 = 64,
		F8 = 65,
		F9 = 66,
		F10 = 67,
		F11 = 68,
		F12 = 69,

		PRINTSCREEN = 70,
		SCROLLLOCK = 71,
		PAUSE = 72,
		INSERT = 73, /**< insert on PC, help on some Mac keyboards (but
                                   does send code 73, not 117) */
		HOME = 74,
		PAGEUP = 75,
		DELETE = 76,
		END = 77,
		PAGEDOWN = 78,
		RIGHT = 79,
		LEFT = 80,
		DOWN = 81,
		UP = 82,

		NUMLOCKCLEAR = 83, /**< num lock on PC, clear on Mac keyboards
                                     */
		KP_DIVIDE = 84,
		KP_MULTIPLY = 85,
		KP_MINUS = 86,
		KP_PLUS = 87,
		KP_ENTER = 88,
		KP_1 = 89,
		KP_2 = 90,
		KP_3 = 91,
		KP_4 = 92,
		KP_5 = 93,
		KP_6 = 94,
		KP_7 = 95,
		KP_8 = 96,
		KP_9 = 97,
		KP_0 = 98,
		KP_PERIOD = 99,

		NONUSBACKSLASH = 100, /**< This is the additional key that ISO
                                        *   keyboards have over ANSI ones,
                                        *   located between left shift and Y.
                                        *   Produces GRAVE ACCENT and TILDE in a
                                        *   US or UK Mac layout, REVERSE SOLIDUS
                                        *   (backslash) and VERTICAL LINE in a
                                        *   US or UK Windows layout, and
                                        *   LESS-THAN SIGN and GREATER-THAN SIGN
                                        *   in a Swiss German, German, or French
                                        *   layout. */
		APPLICATION = 101, /**< windows contextual menu, compose */
		POWER = 102, /**< The USB document says this is a status flag,
                               *   not a physical key - but some Mac keyboards
                               *   do have a power key. */
		KP_EQUALS = 103,
		F13 = 104,
		F14 = 105,
		F15 = 106,
		F16 = 107,
		F17 = 108,
		F18 = 109,
		F19 = 110,
		F20 = 111,
		F21 = 112,
		F22 = 113,
		F23 = 114,
		F24 = 115,
		EXECUTE = 116,
		HELP = 117,
		MENU = 118,
		SELECT = 119,
		STOP = 120,
		AGAIN = 121,   /**< redo */
		UNDO = 122,
		CUT = 123,
		COPY = 124,
		PASTE = 125,
		FIND = 126,
		MUTE = 127,
		VOLUMEUP = 128,
		VOLUMEDOWN = 129,
/* not sure whether there's a reason to enable these */
/*     LOCKINGCAPSLOCK = 130,  */
/*     LOCKINGNUMLOCK = 131, */
/*     LOCKINGSCROLLLOCK = 132, */
		KP_COMMA = 133,
		KP_EQUALSAS400 = 134,

		INTERNATIONAL1 = 135, /**< used on Asian keyboards, see
                                            footnotes in USB doc */
		INTERNATIONAL2 = 136,
		INTERNATIONAL3 = 137, /**< Yen */
		INTERNATIONAL4 = 138,
		INTERNATIONAL5 = 139,
		INTERNATIONAL6 = 140,
		INTERNATIONAL7 = 141,
		INTERNATIONAL8 = 142,
		INTERNATIONAL9 = 143,
		LANG1 = 144, /**< Hangul/English toggle */
		LANG2 = 145, /**< Hanja conversion */
		LANG3 = 146, /**< Katakana */
		LANG4 = 147, /**< Hiragana */
		LANG5 = 148, /**< Zenkaku/Hankaku */
		LANG6 = 149, /**< reserved */
		LANG7 = 150, /**< reserved */
		LANG8 = 151, /**< reserved */
		LANG9 = 152, /**< reserved */

		ALTERASE = 153, /**< Erase-Eaze */
		SYSREQ = 154,
		CANCEL = 155,
		CLEAR = 156,
		PRIOR = 157,
		RETURN2 = 158,
		SEPARATOR = 159,
		OUT = 160,
		OPER = 161,
		CLEARAGAIN = 162,
		CRSEL = 163,
		EXSEL = 164,

		KP_00 = 176,
		KP_000 = 177,
		THOUSANDSSEPARATOR = 178,
		DECIMALSEPARATOR = 179,
		CURRENCYUNIT = 180,
		CURRENCYSUBUNIT = 181,
		KP_LEFTPAREN = 182,
		KP_RIGHTPAREN = 183,
		KP_LEFTBRACE = 184,
		KP_RIGHTBRACE = 185,
		KP_TAB = 186,
		KP_BACKSPACE = 187,
		KP_A = 188,
		KP_B = 189,
		KP_C = 190,
		KP_D = 191,
		KP_E = 192,
		KP_F = 193,
		KP_XOR = 194,
		KP_POWER = 195,
		KP_PERCENT = 196,
		KP_LESS = 197,
		KP_GREATER = 198,
		KP_AMPERSAND = 199,
		KP_DBLAMPERSAND = 200,
		KP_VERTICALBAR = 201,
		KP_DBLVERTICALBAR = 202,
		KP_COLON = 203,
		KP_HASH = 204,
		KP_SPACE = 205,
		KP_AT = 206,
		KP_EXCLAM = 207,
		KP_MEMSTORE = 208,
		KP_MEMRECALL = 209,
		KP_MEMCLEAR = 210,
		KP_MEMADD = 211,
		KP_MEMSUBTRACT = 212,
		KP_MEMMULTIPLY = 213,
		KP_MEMDIVIDE = 214,
		KP_PLUSMINUS = 215,
		KP_CLEAR = 216,
		KP_CLEARENTRY = 217,
		KP_BINARY = 218,
		KP_OCTAL = 219,
		KP_DECIMAL = 220,
		KP_HEXADECIMAL = 221,

		LCTRL = 224,
		LSHIFT = 225,
		LALT = 226, /**< alt, option */
		LGUI = 227, /**< windows, command (apple), meta */
		RCTRL = 228,
		RSHIFT = 229,
		RALT = 230, /**< alt gr, option */
		RGUI = 231, /**< windows, command (apple), meta */

		MODE = 257,    /**< I'm not sure if this is really not covered
                                 *   by any of the above, but since there's a
                                 *   special MODE for it I'm adding it here
                                 */

		/* @} *//* Usage page 0x07 */

		/**
		 *  \name Usage page 0x0C
		 *
		 *  These values are mapped from usage page 0x0C (USB consumer page).
		 */
		/* @{ */

		AUDIONEXT = 258,
		AUDIOPREV = 259,
		AUDIOSTOP = 260,
		AUDIOPLAY = 261,
		AUDIOMUTE = 262,
		MEDIASELECT = 263,
		WWW = 264,
		MAIL = 265,
		CALCULATOR = 266,
		COMPUTER = 267,
		AC_SEARCH = 268,
		AC_HOME = 269,
		AC_BACK = 270,
		AC_FORWARD = 271,
		AC_STOP = 272,
		AC_REFRESH = 273,
		AC_BOOKMARKS = 274,

		/* @} *//* Usage page 0x0C */

		/**
		 *  \name Walther keys
		 *
		 *  These are values that Christian Walther added (for mac keyboard?).
		 */
		/* @{ */

		BRIGHTNESSDOWN = 275,
		BRIGHTNESSUP = 276,
		DISPLAYSWITCH = 277, /**< display mirroring/dual display
                                           switch, video mode switch */
		KBDILLUMTOGGLE = 278,
		KBDILLUMDOWN = 279,
		KBDILLUMUP = 280,
		EJECT = 281,
		SLEEP = 282,

		APP1 = 283,
		APP2 = 284,

		/* @} *//* Walther keys */

		/**
		 *  \name Usage page 0x0C (additional media keys)
		 *
		 *  These values are mapped from usage page 0x0C (USB consumer page).
		 */
		/* @{ */

		AUDIOREWIND = 285,
		AUDIOFASTFORWARD = 286,

		/* @} *//* Usage page 0x0C (additional media keys) */

		/* Add any other keys here. */

		SDL_NUM_SCANCODES = 512 /**< not a key, just marks the number of scancodes
                                 for array bounds */
	};
}

#define SCANCODE_MASK (1<<30)
#define SCANCODE_TO_KEYCODE(X)  (X | SCANCODE_MASK)

namespace Keycode {
	enum Keycode {
		UNKNOWN = 0,

		RETURN = '\r',
		ESCAPE = '\x1B',
		BACKSPACE = '\b',
		TAB = '\t',
		SPACE = ' ',
		EXCLAIM = '!',
		QUOTEDBL = '"',
		HASH = '#',
		PERCENT = '%',
		DOLLAR = '$',
		AMPERSAND = '&',
		QUOTE = '\'',
		LEFTPAREN = '(',
		RIGHTPAREN = ')',
		ASTERISK = '*',
		PLUS = '+',
		COMMA = ',',
		MINUS = '-',
		PERIOD = '.',
		SLASH = '/',
		NUM_0 = '0',
		NUM_1 = '1',
		NUM_2 = '2',
		NUM_3 = '3',
		NUM_4 = '4',
		NUM_5 = '5',
		NUM_6 = '6',
		NUM_7 = '7',
		NUM_8 = '8',
		NUM_9 = '9',
		COLON = ':',
		SEMICOLON = ';',
		LESS = '<',
		EQUALS = '=',
		GREATER = '>',
		QUESTION = '?',
		AT = '@',

		/*
		   Skip uppercase letters
		 */

		LEFTBRACKET = '[',
		BACKSLASH = '\\',
		RIGHTBRACKET = ']',
		CARET = '^',
		UNDERSCORE = '_',
		BACKQUOTE = '`',
		A = 'a',
		B = 'b',
		C = 'c',
		D = 'd',
		E = 'e',
		F = 'f',
		G = 'g',
		H = 'h',
		I = 'i',
		J = 'j',
		K = 'k',
		L = 'l',
		M = 'm',
		N = 'n',
		O = 'o',
		P = 'p',
		Q = 'q',
		R = 'r',
		S = 's',
		T = 't',
		U = 'u',
		V = 'v',
		W = 'w',
		X = 'x',
		Y = 'y',
		Z = 'z',

		CAPSLOCK = SCANCODE_TO_KEYCODE(Scancode::CAPSLOCK),

		F1 = SCANCODE_TO_KEYCODE(Scancode::F1),
		F2 = SCANCODE_TO_KEYCODE(Scancode::F2),
		F3 = SCANCODE_TO_KEYCODE(Scancode::F3),
		F4 = SCANCODE_TO_KEYCODE(Scancode::F4),
		F5 = SCANCODE_TO_KEYCODE(Scancode::F5),
		F6 = SCANCODE_TO_KEYCODE(Scancode::F6),
		F7 = SCANCODE_TO_KEYCODE(Scancode::F7),
		F8 = SCANCODE_TO_KEYCODE(Scancode::F8),
		F9 = SCANCODE_TO_KEYCODE(Scancode::F9),
		F10 = SCANCODE_TO_KEYCODE(Scancode::F10),
		F11 = SCANCODE_TO_KEYCODE(Scancode::F11),
		F12 = SCANCODE_TO_KEYCODE(Scancode::F12),

		PRINTSCREEN = SCANCODE_TO_KEYCODE(Scancode::PRINTSCREEN),
		SCROLLLOCK = SCANCODE_TO_KEYCODE(Scancode::SCROLLLOCK),
		PAUSE = SCANCODE_TO_KEYCODE(Scancode::PAUSE),
		INSERT = SCANCODE_TO_KEYCODE(Scancode::INSERT),
		HOME = SCANCODE_TO_KEYCODE(Scancode::HOME),
		PAGEUP = SCANCODE_TO_KEYCODE(Scancode::PAGEUP),
		DELETE = '\x7F',
		END = SCANCODE_TO_KEYCODE(Scancode::END),
		PAGEDOWN = SCANCODE_TO_KEYCODE(Scancode::PAGEDOWN),
		RIGHT = SCANCODE_TO_KEYCODE(Scancode::RIGHT),
		LEFT = SCANCODE_TO_KEYCODE(Scancode::LEFT),
		DOWN = SCANCODE_TO_KEYCODE(Scancode::DOWN),
		UP = SCANCODE_TO_KEYCODE(Scancode::UP),

		NUMLOCKCLEAR = SCANCODE_TO_KEYCODE(Scancode::NUMLOCKCLEAR),
		KP_DIVIDE = SCANCODE_TO_KEYCODE(Scancode::KP_DIVIDE),
		KP_MULTIPLY = SCANCODE_TO_KEYCODE(Scancode::KP_MULTIPLY),
		KP_MINUS = SCANCODE_TO_KEYCODE(Scancode::KP_MINUS),
		KP_PLUS = SCANCODE_TO_KEYCODE(Scancode::KP_PLUS),
		KP_ENTER = SCANCODE_TO_KEYCODE(Scancode::KP_ENTER),
		KP_1 = SCANCODE_TO_KEYCODE(Scancode::KP_1),
		KP_2 = SCANCODE_TO_KEYCODE(Scancode::KP_2),
		KP_3 = SCANCODE_TO_KEYCODE(Scancode::KP_3),
		KP_4 = SCANCODE_TO_KEYCODE(Scancode::KP_4),
		KP_5 = SCANCODE_TO_KEYCODE(Scancode::KP_5),
		KP_6 = SCANCODE_TO_KEYCODE(Scancode::KP_6),
		KP_7 = SCANCODE_TO_KEYCODE(Scancode::KP_7),
		KP_8 = SCANCODE_TO_KEYCODE(Scancode::KP_8),
		KP_9 = SCANCODE_TO_KEYCODE(Scancode::KP_9),
		KP_0 = SCANCODE_TO_KEYCODE(Scancode::KP_0),
		KP_PERIOD = SCANCODE_TO_KEYCODE(Scancode::KP_PERIOD),

		APPLICATION = SCANCODE_TO_KEYCODE(Scancode::APPLICATION),
		POWER = SCANCODE_TO_KEYCODE(Scancode::POWER),
		KP_EQUALS = SCANCODE_TO_KEYCODE(Scancode::KP_EQUALS),
		F13 = SCANCODE_TO_KEYCODE(Scancode::F13),
		F14 = SCANCODE_TO_KEYCODE(Scancode::F14),
		F15 = SCANCODE_TO_KEYCODE(Scancode::F15),
		F16 = SCANCODE_TO_KEYCODE(Scancode::F16),
		F17 = SCANCODE_TO_KEYCODE(Scancode::F17),
		F18 = SCANCODE_TO_KEYCODE(Scancode::F18),
		F19 = SCANCODE_TO_KEYCODE(Scancode::F19),
		F20 = SCANCODE_TO_KEYCODE(Scancode::F20),
		F21 = SCANCODE_TO_KEYCODE(Scancode::F21),
		F22 = SCANCODE_TO_KEYCODE(Scancode::F22),
		F23 = SCANCODE_TO_KEYCODE(Scancode::F23),
		F24 = SCANCODE_TO_KEYCODE(Scancode::F24),
		EXECUTE = SCANCODE_TO_KEYCODE(Scancode::EXECUTE),
		HELP = SCANCODE_TO_KEYCODE(Scancode::HELP),
		MENU = SCANCODE_TO_KEYCODE(Scancode::MENU),
		SELECT = SCANCODE_TO_KEYCODE(Scancode::SELECT),
		STOP = SCANCODE_TO_KEYCODE(Scancode::STOP),
		AGAIN = SCANCODE_TO_KEYCODE(Scancode::AGAIN),
		UNDO = SCANCODE_TO_KEYCODE(Scancode::UNDO),
		CUT = SCANCODE_TO_KEYCODE(Scancode::CUT),
		COPY = SCANCODE_TO_KEYCODE(Scancode::COPY),
		PASTE = SCANCODE_TO_KEYCODE(Scancode::PASTE),
		FIND = SCANCODE_TO_KEYCODE(Scancode::FIND),
		MUTE = SCANCODE_TO_KEYCODE(Scancode::MUTE),
		VOLUMEUP = SCANCODE_TO_KEYCODE(Scancode::VOLUMEUP),
		VOLUMEDOWN = SCANCODE_TO_KEYCODE(Scancode::VOLUMEDOWN),
		KP_COMMA = SCANCODE_TO_KEYCODE(Scancode::KP_COMMA),
		KP_EQUALSAS400 =
		SCANCODE_TO_KEYCODE(Scancode::KP_EQUALSAS400),

		ALTERASE = SCANCODE_TO_KEYCODE(Scancode::ALTERASE),
		SYSREQ = SCANCODE_TO_KEYCODE(Scancode::SYSREQ),
		CANCEL = SCANCODE_TO_KEYCODE(Scancode::CANCEL),
		CLEAR = SCANCODE_TO_KEYCODE(Scancode::CLEAR),
		PRIOR = SCANCODE_TO_KEYCODE(Scancode::PRIOR),
		RETURN2 = SCANCODE_TO_KEYCODE(Scancode::RETURN2),
		SEPARATOR = SCANCODE_TO_KEYCODE(Scancode::SEPARATOR),
		OUT = SCANCODE_TO_KEYCODE(Scancode::OUT),
		OPER = SCANCODE_TO_KEYCODE(Scancode::OPER),
		CLEARAGAIN = SCANCODE_TO_KEYCODE(Scancode::CLEARAGAIN),
		CRSEL = SCANCODE_TO_KEYCODE(Scancode::CRSEL),
		EXSEL = SCANCODE_TO_KEYCODE(Scancode::EXSEL),

		KP_00 = SCANCODE_TO_KEYCODE(Scancode::KP_00),
		KP_000 = SCANCODE_TO_KEYCODE(Scancode::KP_000),
		THOUSANDSSEPARATOR =
		SCANCODE_TO_KEYCODE(Scancode::THOUSANDSSEPARATOR),
		DECIMALSEPARATOR =
		SCANCODE_TO_KEYCODE(Scancode::DECIMALSEPARATOR),
		CURRENCYUNIT = SCANCODE_TO_KEYCODE(Scancode::CURRENCYUNIT),
		CURRENCYSUBUNIT =
		SCANCODE_TO_KEYCODE(Scancode::CURRENCYSUBUNIT),
		KP_LEFTPAREN = SCANCODE_TO_KEYCODE(Scancode::KP_LEFTPAREN),
		KP_RIGHTPAREN = SCANCODE_TO_KEYCODE(Scancode::KP_RIGHTPAREN),
		KP_LEFTBRACE = SCANCODE_TO_KEYCODE(Scancode::KP_LEFTBRACE),
		KP_RIGHTBRACE = SCANCODE_TO_KEYCODE(Scancode::KP_RIGHTBRACE),
		KP_TAB = SCANCODE_TO_KEYCODE(Scancode::KP_TAB),
		KP_BACKSPACE = SCANCODE_TO_KEYCODE(Scancode::KP_BACKSPACE),
		KP_A = SCANCODE_TO_KEYCODE(Scancode::KP_A),
		KP_B = SCANCODE_TO_KEYCODE(Scancode::KP_B),
		KP_C = SCANCODE_TO_KEYCODE(Scancode::KP_C),
		KP_D = SCANCODE_TO_KEYCODE(Scancode::KP_D),
		KP_E = SCANCODE_TO_KEYCODE(Scancode::KP_E),
		KP_F = SCANCODE_TO_KEYCODE(Scancode::KP_F),
		KP_XOR = SCANCODE_TO_KEYCODE(Scancode::KP_XOR),
		KP_POWER = SCANCODE_TO_KEYCODE(Scancode::KP_POWER),
		KP_PERCENT = SCANCODE_TO_KEYCODE(Scancode::KP_PERCENT),
		KP_LESS = SCANCODE_TO_KEYCODE(Scancode::KP_LESS),
		KP_GREATER = SCANCODE_TO_KEYCODE(Scancode::KP_GREATER),
		KP_AMPERSAND = SCANCODE_TO_KEYCODE(Scancode::KP_AMPERSAND),
		KP_DBLAMPERSAND =
		SCANCODE_TO_KEYCODE(Scancode::KP_DBLAMPERSAND),
		KP_VERTICALBAR =
		SCANCODE_TO_KEYCODE(Scancode::KP_VERTICALBAR),
		KP_DBLVERTICALBAR =
		SCANCODE_TO_KEYCODE(Scancode::KP_DBLVERTICALBAR),
		KP_COLON = SCANCODE_TO_KEYCODE(Scancode::KP_COLON),
		KP_HASH = SCANCODE_TO_KEYCODE(Scancode::KP_HASH),
		KP_SPACE = SCANCODE_TO_KEYCODE(Scancode::KP_SPACE),
		KP_AT = SCANCODE_TO_KEYCODE(Scancode::KP_AT),
		KP_EXCLAM = SCANCODE_TO_KEYCODE(Scancode::KP_EXCLAM),
		KP_MEMSTORE = SCANCODE_TO_KEYCODE(Scancode::KP_MEMSTORE),
		KP_MEMRECALL = SCANCODE_TO_KEYCODE(Scancode::KP_MEMRECALL),
		KP_MEMCLEAR = SCANCODE_TO_KEYCODE(Scancode::KP_MEMCLEAR),
		KP_MEMADD = SCANCODE_TO_KEYCODE(Scancode::KP_MEMADD),
		KP_MEMSUBTRACT =
		SCANCODE_TO_KEYCODE(Scancode::KP_MEMSUBTRACT),
		KP_MEMMULTIPLY =
		SCANCODE_TO_KEYCODE(Scancode::KP_MEMMULTIPLY),
		KP_MEMDIVIDE = SCANCODE_TO_KEYCODE(Scancode::KP_MEMDIVIDE),
		KP_PLUSMINUS = SCANCODE_TO_KEYCODE(Scancode::KP_PLUSMINUS),
		KP_CLEAR = SCANCODE_TO_KEYCODE(Scancode::KP_CLEAR),
		KP_CLEARENTRY = SCANCODE_TO_KEYCODE(Scancode::KP_CLEARENTRY),
		KP_BINARY = SCANCODE_TO_KEYCODE(Scancode::KP_BINARY),
		KP_OCTAL = SCANCODE_TO_KEYCODE(Scancode::KP_OCTAL),
		KP_DECIMAL = SCANCODE_TO_KEYCODE(Scancode::KP_DECIMAL),
		KP_HEXADECIMAL =
		SCANCODE_TO_KEYCODE(Scancode::KP_HEXADECIMAL),

		LCTRL = SCANCODE_TO_KEYCODE(Scancode::LCTRL),
		LSHIFT = SCANCODE_TO_KEYCODE(Scancode::LSHIFT),
		LALT = SCANCODE_TO_KEYCODE(Scancode::LALT),
		LGUI = SCANCODE_TO_KEYCODE(Scancode::LGUI),
		RCTRL = SCANCODE_TO_KEYCODE(Scancode::RCTRL),
		RSHIFT = SCANCODE_TO_KEYCODE(Scancode::RSHIFT),
		RALT = SCANCODE_TO_KEYCODE(Scancode::RALT),
		RGUI = SCANCODE_TO_KEYCODE(Scancode::RGUI),

		MODE = SCANCODE_TO_KEYCODE(Scancode::MODE),

		AUDIONEXT = SCANCODE_TO_KEYCODE(Scancode::AUDIONEXT),
		AUDIOPREV = SCANCODE_TO_KEYCODE(Scancode::AUDIOPREV),
		AUDIOSTOP = SCANCODE_TO_KEYCODE(Scancode::AUDIOSTOP),
		AUDIOPLAY = SCANCODE_TO_KEYCODE(Scancode::AUDIOPLAY),
		AUDIOMUTE = SCANCODE_TO_KEYCODE(Scancode::AUDIOMUTE),
		MEDIASELECT = SCANCODE_TO_KEYCODE(Scancode::MEDIASELECT),
		WWW = SCANCODE_TO_KEYCODE(Scancode::WWW),
		MAIL = SCANCODE_TO_KEYCODE(Scancode::MAIL),
		CALCULATOR = SCANCODE_TO_KEYCODE(Scancode::CALCULATOR),
		COMPUTER = SCANCODE_TO_KEYCODE(Scancode::COMPUTER),
		AC_SEARCH = SCANCODE_TO_KEYCODE(Scancode::AC_SEARCH),
		AC_HOME = SCANCODE_TO_KEYCODE(Scancode::AC_HOME),
		AC_BACK = SCANCODE_TO_KEYCODE(Scancode::AC_BACK),
		AC_FORWARD = SCANCODE_TO_KEYCODE(Scancode::AC_FORWARD),
		AC_STOP = SCANCODE_TO_KEYCODE(Scancode::AC_STOP),
		AC_REFRESH = SCANCODE_TO_KEYCODE(Scancode::AC_REFRESH),
		AC_BOOKMARKS = SCANCODE_TO_KEYCODE(Scancode::AC_BOOKMARKS),

		BRIGHTNESSDOWN =
		SCANCODE_TO_KEYCODE(Scancode::BRIGHTNESSDOWN),
		BRIGHTNESSUP = SCANCODE_TO_KEYCODE(Scancode::BRIGHTNESSUP),
		DISPLAYSWITCH = SCANCODE_TO_KEYCODE(Scancode::DISPLAYSWITCH),
		KBDILLUMTOGGLE =
		SCANCODE_TO_KEYCODE(Scancode::KBDILLUMTOGGLE),
		KBDILLUMDOWN = SCANCODE_TO_KEYCODE(Scancode::KBDILLUMDOWN),
		KBDILLUMUP = SCANCODE_TO_KEYCODE(Scancode::KBDILLUMUP),
		EJECT = SCANCODE_TO_KEYCODE(Scancode::EJECT),
		SLEEP = SCANCODE_TO_KEYCODE(Scancode::SLEEP),
		APP1 = SCANCODE_TO_KEYCODE(Scancode::APP1),
		APP2 = SCANCODE_TO_KEYCODE(Scancode::APP2),

		AUDIOREWIND = SCANCODE_TO_KEYCODE(Scancode::AUDIOREWIND),
		AUDIOFASTFORWARD = SCANCODE_TO_KEYCODE(Scancode::AUDIOFASTFORWARD)
	};
}

/**
 * \brief Enumeration of valid key mods (possibly OR'd together).
 */
namespace Keymod {
	enum Keymod {
		NONE = 0x0000,
		LSHIFT = 0x0001,
		RSHIFT = 0x0002,
		LCTRL = 0x0040,
		RCTRL = 0x0080,
		LALT = 0x0100,
		RALT = 0x0200,
		LGUI = 0x0400,
		RGUI = 0x0800,
		NUM = 0x1000,
		CAPS = 0x2000,
		MODE = 0x4000,
		SCROLL = 0x8000,

		CTRL = LCTRL | RCTRL,
		SHIFT = LSHIFT | RSHIFT,
		ALT = LALT | RALT,
		GUI = LGUI | RGUI
	};
}

#undef SCANCODE_TO_KEYCODE
#undef SCANCODE_MASK