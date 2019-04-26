#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

// Layers
#define BASE 0 // Base layer
#define NUMP 4 // Numpad
#define FCTN 8 // Functions

// Tap Dancing
void dance_lock (qk_tap_dance_state_t *state, void *user_data) {
	switch (state->count){
		case 1: // Press once for LGUI
			tap_code(KC_LGUI);
			break;
		case 2: // Press twice for CAPSLOCK
			tap_code(KC_CAPS);
			break;
		case 3: // Press three times for NUMLOCK
			tap_code(KC_NLCK);
			break;
		default:
			break;
	}
};

void dance_layer (qk_tap_dance_state_t *state, void *user_data) {
	switch (state -> count) {
		case 1: // Press once for MENU
			tap_code(KC_APP);
			break;
		case 2: // Press twice for NUMPAD
			layer_invert(NUMP);
			break;
		default:
			break;
	}
};

enum tap_dances {LOCKS = 0, LAYERS = 1};
qk_tap_dance_action_t tap_dance_actions[] = {
	[LOCKS] = ACTION_TAP_DANCE_FN(dance_lock),
	[LAYERS] = ACTION_TAP_DANCE_FN(dance_layer)
};

// Make layering more clear
#define CC_ESC LCTL_T(KC_ESC)
#define CC_QUOT RCTL_T(KC_QUOT)
#define AC_SLSH LT(FCTN, KC_SLSH)
#define AC_EQL RALT_T(KC_EQL)
#define FC_BSLS LALT_T(KC_BSLS)
#define FC_MINS LT(FCTN, KC_MINS)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	[BASE] = LAYOUT(
// ┌──────────┬──────────┬──────────┬──────────┬──────────┬──────────┐                              ┌──────────┬──────────┬──────────┬──────────┬──────────┬──────────┐
	KC_GRV,    KC_1,      KC_2,      KC_3,      KC_4,      KC_5,                                     KC_6,      KC_7,      KC_8,      KC_9,      KC_0,      KC_DEL,
// ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤                              ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
	KC_TAB,    KC_Q,      KC_W,      KC_E,      KC_R,      KC_T,                                     KC_Y,      KC_U,      KC_I,      KC_O,      KC_P,      KC_BSPC,
// ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤                              ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
	CC_ESC,    KC_A,      KC_S,      KC_D,      KC_F,      KC_G,                                     KC_H,      KC_J,      KC_K,      KC_L,      KC_SCLN,   CC_QUOT,
// ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┐        ┌──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
	KC_LSPO,   KC_Z,      KC_X,      KC_C,      KC_V,      KC_B,      TD(LOCKS),          TD(LAYERS),KC_N,      KC_M,      KC_COMM,   KC_DOT,    KC_SLSH,   KC_RSPC,
// └──────────┴──────────┴──────────┴────┬─────┴────┬─────┴────┬─────┴────┬─────┘        └────┬─────┴────┬─────┴────┬─────┴────┬─────┴──────────┴──────────┴──────────┘
	                                                 FC_BSLS,   AC_SLSH ,   KC_SPC,                        KC_ENT,    FC_MINS,   AC_EQL
//                                                  └──────────┴──────────┴──────────┘                   └──────────┴──────────┴──────────┘
	),

	[NUMP] = LAYOUT(
// ┌──────────┬──────────┬──────────┬──────────┬──────────┬──────────┐                              ┌──────────┬──────────┬──────────┬──────────┬──────────┬──────────┐
	_______,   _______,   KC_P7,     KC_P8,     KC_P9,     KC_PSLS,                                  _______,   KC_P7,     KC_P8,     KC_P9,     KC_PSLS,   _______,
// ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤                              ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
	_______,   _______,   KC_P4,     KC_P5,     KC_P6,     KC_PAST,                                  _______,   KC_P4,     KC_P5,     KC_P6,     KC_PAST,   _______,
// ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤                              ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
	_______,   _______,   KC_P1,     KC_P2,     KC_P3,     KC_PMNS,                                  _______,   KC_P1,     KC_P2,     KC_P3,     KC_PMNS,   _______,
// ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┐        ┌──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
	_______,   _______,   KC_P0,     KC_PCMM,   KC_PDOT,   KC_PPLS,   _______,            _______,   _______,   KC_P0,     KC_PCMM,   KC_PDOT,   KC_PPLS,   _______,
// └──────────┴──────────┴──────────┴────┬─────┴────┬─────┴────┬─────┴────┬─────┘        └────┬─────┴────┬─────┴────┬─────┴────┬─────┴──────────┴──────────┴──────────┘
										  _______,   _______,   _______,                       KC_PENT,   _______,   _______
//                                       └──────────┴──────────┴──────────┘                   └──────────┴──────────┴──────────┘
	),

	[FCTN] = LAYOUT(
// ┌──────────┬──────────┬──────────┬──────────┬──────────┬──────────┐                              ┌──────────┬──────────┬──────────┬──────────┬──────────┬──────────┐
	KC_ESC,    KC_F1,     KC_F2,     KC_F3,     KC_F4,     KC_F5,                                    KC_F6,     KC_F7,     KC_F8,     KC_F9,     KC_F10,    KC_SYSREQ,
// ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤                              ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
	KC_PSCR,   UC_MOD,    KC_HOME,   KC_UP,     KC_END,    KC_PGUP,                                  KC_PIPE,	KC_LBRC,   KC_RBRC,   S(KC_LBRC),S(KC_RBRC),KC_INS,
// ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤                              ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
	KC_PAUS,   RGB_TOG,   KC_LEFT,   KC_DOWN,   KC_RGHT,   KC_PGDN,                                  KC_LEFT,   KC_DOWN,   KC_UP,     KC_RGHT,   KC_BRIU,   KC_CLR,
// ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┐        ┌──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
	_______,   KC_MPRV,   KC_MRWD,   KC_MPLY,   KC_MFFD,   KC_MNXT,   KC_F11,             KC_F12,    KC_MSTP,   KC_MUTE,   KC_VOLD,   KC_VOLU,   KC_BRID,   _______,
// └──────────┴──────────┴──────────┴────┬─────┴────┬─────┴────┬─────┴────┬─────┘        └────┬─────┴────┬─────┴────┬─────┴────┬─────┴──────────┴──────────┴──────────┘
										  _______,   _______,   _______,                       _______,   _______,   _______
//                                       └──────────┴──────────┴──────────┘                   └──────────┴──────────┴──────────┘
	)
};

// Initialize rgblight
void keyboard_post_init_user(void) {
	rgblight_enable_noeeprom();
	for (int i = 360; i > 0; i--) {
		rgblight_sethsv_noeeprom(i, 255, 255);
	}
	layer_state_set_user(layer_state);
};

// Turn on RGB underglow according to active layer
uint32_t layer_state_set_user(uint32_t state) {
	switch (biton32(state)) {
		case FCTN:
			rgblight_sethsv_noeeprom(136, 255, 255);
			break;
		case NUMP:
			rgblight_sethsv_noeeprom(228, 255, 255);
			break;
		default: //  for any other layers, or the default layer
			rgblight_sethsv_noeeprom(19, 255, 255);
			break;
	}
	return state;
};
