#include QMK_KEYBOARD_H

#define INDICATOR_BRIGHTNESS 30

#define HSV_OVERRIDE_HELP(h, s, v, Override) h, s , Override
#define HSV_OVERRIDE(hsv, Override) HSV_OVERRIDE_HELP(hsv,Override)

// Light combinations
#define SET_INDICATORS(hsv) \
	{0, 1, HSV_OVERRIDE_HELP(hsv, INDICATOR_BRIGHTNESS)}, \
    {36+0, 1, hsv}
#define SET_UNDERGLOW(hsv) \
	{0, 6, hsv}, \
    {36+0, 6,hsv}
#define SET_ARROW(hsv) \
    {36+19, 1, hsv}, \
    {36+23, 2, hsv}, \
    {36+29, 1, hsv}
#define SET_LAYER_ID(hsv) 	\
	{0, 1, HSV_OVERRIDE_HELP(hsv, INDICATOR_BRIGHTNESS)}, \
    {36+0, 1, HSV_OVERRIDE_HELP(hsv, INDICATOR_BRIGHTNESS)}, \
    {1, 6, hsv}, \
    {36+1, 6, hsv}, \
    {8, 4, hsv}, \
    {36+8, 4, hsv}, \
    {7, 1, hsv}, {16, 2, hsv}, {26, 2, hsv}, \
    {36+7, 1, hsv}, {36+16, 2, hsv}, {36+26, 2, hsv}



enum sofle_layers {
    /* _M_XYZ = Mac Os, _W_XYZ = Win/Linux */
    _QWERTY,
    _RAISE,
    _LOWER,
    _ADJUST,
    // _NUMPAD
};

enum custom_keycodes {
    KC_QWERTY = SAFE_RANGE,
    KC_LOWER,
    KC_RAISE,
    KC_ADJUST,
    KC_PRVWD,
    KC_NXTWD,
    KC_LSTRT,
    KC_LEND,
    KC_DLINE,
    // KC_BASH
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * QWERTY
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |  `   |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  | Bspc |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * | Tab  |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
     * |------+------+------+------+------+------|  MUTE |    | bash  |------+------+------+------+------+------|
     * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *            | LGUI | LAlt | LCTR |LOWER | /Space  /       \Enter \  |RAISE | RCTR | RAlt | RGUI |
     *            |      |      |      |      |/       /         \      \ |      |      |      |      |
     *            `----------------------------------'           '------''---------------------------'
     */
    [_QWERTY] = LAYOUT(
        //,------------------------------------------------.                   ,-----------------------------------------------------.
        KC_ESC,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,   KC_8,    KC_9,    KC_0,    KC_GRV,
        //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
        KC_GRV,   KC_Q,  KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,   KC_I,    KC_O,    KC_P,    KC_BSPC,
        //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
        KC_TAB,   KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,   KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
        KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,  KC_MUTE,    XXXXXXX,KC_N,    KC_M,   KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
        //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
                        KC_LGUI, KC_LALT, KC_LCTL,KC_LOWER, KC_SPC,     KC_ENT, KC_RAISE,   KC_RCTL, KC_RALT, KC_RGUI
        //            \--------+--------+--------+---------+-------|   |--------+----------+--------+--------+-------/
    ),

    /* LOWER
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |                    |  F7  |  F8  |  F9  | F10  | F11  | F12  |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * | Tab  |   !  |   @  |   #  |   $  |   %  |-------.    ,-------|   ^  |   &  |   *  |   (  |   )  |   |  |
     * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
     * |  _   |  =   |  -   |  +   |   {  |   }  |-------|    |-------|   [  |   ]  |   ;  |   :  |   \  | Shift|
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *            | LGUI | LAlt | LCTR |LOWER | /Space  /       \Enter \  |RAISE | RCTR | RAlt | RGUI |
     *            |      |      |      |      |/       /         \      \ |      |      |      |      |
     *            `----------------------------------'           '------''---------------------------'
     */
    [_LOWER] = LAYOUT(
        //,------------------------------------------------.                   ,-----------------------------------------------------.
        KC_F1,    KC_F2,  KC_F3,   KC_F4,   KC_F5,   KC_F6,                     KC_F7,   KC_F8,  KC_F9,   KC_F10,  KC_F11,  KC_F12,
        //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
        KC_GRV,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,   KC_8,    KC_9,    KC_0,    KC_GRV,
        //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
        _______,  KC_EXLM,KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                   KC_CIRC, KC_AMPR,KC_ASTR, KC_LPRN, KC_RPRN, KC_PIPE,
        //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
        KC_UNDS,  KC_EQL, KC_MINS, KC_PLUS, KC_LCBR, KC_RCBR,_______,   _______,KC_LBRC, KC_RBRC,KC_SCLN, KC_COLN, KC_BSLS, _______,
        //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
                        _______,_______, _______, _______,  _______,    _______,   _______, _______, _______, _______
        //            \--------+--------+--------+---------+-------|   |--------+----------+--------+--------+-------/
    ),

    /* RAISE
     * ,----------------------------------------.                    ,-----------------------------------------.
     * | Esc  |      |      |      |      |      |                    |      |      |      |      |      |      |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |      | Ins  | Pscr | Menu |      |      |                    | PGUp | PWrd |  Up  | NWrd | DLine| Bspc |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * | Tab  | LAt  | LCtl |LShift|      | Caps |-------.    ,-------| PGDwn| Left | Down | Rigth|  Del | Bspc |
     * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
     * |Shift | Undo |  Cut | Copy | Paste|      |-------|    |-------|      | LStr |      | LEnd |      | Shift|
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *            | LGUI | LAlt | LCTR |LOWER | /Space  /       \Enter \  |RAISE | RCTR | RAlt | RGUI |
     *            |      |      |      |      |/       /         \      \ |      |      |      |      |
     *            `----------------------------------'           '------''---------------------------'
     */
    [_RAISE] = LAYOUT(
        //,------------------------------------------------.                   ,-----------------------------------------------------.
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,XXXXXXX,                     XXXXXXX,XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,
        //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
        XXXXXXX,  KC_INS, KC_PSCR,  KC_APP, XXXXXXX,XXXXXXX,                    KC_PGUP,KC_PRVWD, KC_UP,  KC_NXTWD,KC_DLINE,  _______,
        //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
        _______,  KC_LALT,KC_LCTL,  KC_LSFT,XXXXXXX,KC_CAPS,                    KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT,  KC_DEL,  _______,
        //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
        _______,  KC_UNDO, KC_CUT, KC_COPY,KC_PASTE,XXXXXXX,_______,    _______,XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  _______,
        //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
                        _______,_______, _______, _______,  _______,    _______,   _______, _______, _______, _______
        //            \--------+--------+--------+---------+-------|   |--------+----------+--------+--------+-------/
    ),

    /* ADJUST
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * |clear mem| WIN | MAC  |      |      |      |                    |      |      |      |      |      |      |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * | QK_BOOT|      |      |      |      |      |                    |      |      |      |      |      |      |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |RGB_TOG|hue^ |sat ^ | bri ^|      |COLEMAK|-------.   ,-------|      |desk <|      |desk >|      |      |
     * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
     * | mode | hue dn|sat d|bri dn|      |QWERTY|-------|    |-------|      | PREV | PLAY | NEXT |      |      |
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *            | LGUI | LAlt | LCTR |LOWER | /Space  /       \Enter \  |RAISE | RCTR | RAlt | RGUI |
     *            |      |      |      |      |/       /         \      \ |      |      |      |      |
     *            `----------------------------------'           '------''---------------------------'
     */
    [_ADJUST] = LAYOUT(
        //,------------------------------------------------.                   ,-----------------------------------------------------.
        EE_CLR, CG_LSWP, CG_LNRM, XXXXXXX, XXXXXXX, XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
        QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,XXXXXXX,                    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
        RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX,XXXXXXX,            XXXXXXX,C(G(KC_LEFT)),KC_NO, C(G(KC_RGHT)), XXXXXXX, XXXXXXX,
        //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
        RGB_MOD, RGB_HUD, RGB_SAD,RGB_VAD,XXXXXXX,KC_QWERTY,XXXXXXX,    XXXXXXX, XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX, XXXXXXX,
        //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
                        _______,_______, _______, _______,  _______,    _______,   _______, _______, _______, _______
        //            \--------+--------+--------+---------+-------|   |--------+----------+--------+--------+-------/
    ),

    /* NUMPAD
    * ,-----------------------------------------.                    ,-----------------------------------------.
    * | trans|      |      |      |      |      |                    |      |NumLck|      |      |      |      |
    * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
    * |  `   |      |      |      |      |      |                    |   ^  |   7  |   8  |   9  |   *  |      |
    * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
    * | trans|      |      |      |      |      |-------.    ,-------|   -  |   4  |   5  |   6  |   =  |   |  |
    * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
    * | trans|      |      |      |      |      |-------|    |-------|   +  |   1  |   2  |   3  |   \  | Shift|
    * `-----------------------------------------/       /     \      \-----------------------------------------'
    *            | Bspc | WIN  |LOWER | Enter| /Space  /       \Enter \  |      | 0    |  .   |      |
    *            |      |      |      |      |/       /         \      \ |      |      |      |      |
    *            `----------------------------------'           '------''---------------------------'
    */
    // [_NUMPAD] = LAYOUT(
    // //,------------------------------------------------.                    ,---------------------------------------------------.
    // _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   _______, KC_NUM,  XXXXXXX, XXXXXXX,XXXXXXX, XXXXXXX,
    // //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
    // XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   KC_CIRC, KC_P7,  KC_P8,   KC_P9,   KC_ASTR, XXXXXXX,
    // //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
    // XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   KC_MINS, KC_P4,  KC_P5,   KC_P6,   KC_EQL,  KC_PIPE,
    // //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
    // XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,_______,   _______,KC_PLUS, KC_P1,  KC_P2,   KC_P3,   KC_SLSH, _______,
    // //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
    //                  _______, _______, _______, _______, _______,   _______, _______,  KC_P0,  KC_PDOT, _______
    // //            \--------+--------+--------+---------+-------|   |--------+---------+--------+---------+-------/
    // ),
};

#ifdef RGBLIGHT_ENABLE
char layer_state_str[72];
// Now define the array of layers. Later layers take precedence

// QWERTY,
// Light on inner column and underglow
const rgblight_segment_t PROGMEM layer_qwerty_lights[] = RGBLIGHT_LAYER_SEGMENTS(
    SET_LAYER_ID(HSV_RED)

);
// _NUM,
// Light on outer column and underglow
const rgblight_segment_t PROGMEM layer_num_lights[] = RGBLIGHT_LAYER_SEGMENTS(
	SET_LAYER_ID(HSV_TEAL)

);
// _SYMBOL,
// Light on inner column and underglow
const rgblight_segment_t PROGMEM layer_symbol_lights[] = RGBLIGHT_LAYER_SEGMENTS(
	SET_LAYER_ID(HSV_BLUE),
    SET_ARROW(HSV_ORANGE)

    );
// _COMMAND,
// Light on inner column and underglow
const rgblight_segment_t PROGMEM layer_command_lights[] = RGBLIGHT_LAYER_SEGMENTS(
  SET_LAYER_ID(HSV_PURPLE)
);


const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    layer_qwerty_lights,
	layer_num_lights,// overrides layer 1
	layer_symbol_lights,
    layer_command_lights
);

layer_state_t layer_state_set_user(layer_state_t state) {
	rgblight_set_layer_state(0, layer_state_cmp(default_layer_state,_QWERTY));

	rgblight_set_layer_state(1, layer_state_cmp(state, _LOWER));
	rgblight_set_layer_state(2, layer_state_cmp(state, _RAISE));
	rgblight_set_layer_state(3, layer_state_cmp(state, _ADJUST));
    return state;
}
void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;

	rgblight_mode(10);// haven't found a way to set this in a more useful way

}
#endif


#ifdef OLED_ENABLE

char wpm_str[32];

// WPM-responsive animation stuff here
#    define IDLE_FRAMES 3
#    define IDLE_SPEED 25 // below this wpm value your animation will idle

// #define PREP_FRAMES 1 // uncomment if >1

#    define TAP_FRAMES 2
#    define TAP_SPEED 30 // above this wpm value typing animation to triggere

#    define ANIM_FRAME_DURATION 200 // how long each frame lasts in ms
// #define SLEEP_TIMER 60000 // should sleep after this period of 0 wpm, needs fixing
#    define ANIM_SIZE 512 // number of bytes in array, minimize for adequate firmware size, max is 1024

uint32_t anim_timer         = 0;
uint32_t anim_sleep         = 0;
uint8_t  current_idle_frame = 0;
// uint8_t current_prep_frame = 0; // uncomment if PREP_FRAMES >1
uint8_t current_tap_frame = 0;

// Images credit j-inc(/James Incandenza) and pixelbenny. Credit to obosob for initial animation approach.
// static void render_anim(void) {
//     static const char PROGMEM idle[IDLE_FRAMES][ANIM_SIZE] = {{
//         0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,128,64,64,32,32,32,32,16,16,16,16,16,8,8,4,4,4,8,48,64,128,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,128,128,128,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,24,100,130,2,2,2,2,2,1,0,0,0,0,128,128,0,0,0,0,0,0,0,0,0,128,0,48,48,0,192,193,193,194,4,8,16,32,64,128,0,0,0,128,128,128,128,64,64,64,64,32,32,32,32,16,16,16,16,8,8,8,8,8,4,4,4,4,4,2,2,2,2,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,192,56,4,3,0,0,0,0,0,0,0,12,12,12,13,1,0,64,160,33,34,18,17,17,17,9,8,8,8,8,4,4,8,8,16,16,16,16,16,17,15,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,128,128,128,128,64,64,64,64,32,32,32,32,16,16,16,16,8,8,8,8,8,4,4,4,4,4,2,3,2,2,1,1,1,1,1,1,2,2,4,4,8,8,8,8,8,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
//     },
//     {
//         0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,128,128,64,64,64,64,32,32,32,32,16,8,4,2,2,4,24,96,128,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,128,128,128,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,60,194,1,1,2,2,4,4,2,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,96,96,0,129,130,130,132,8,16,32,64,128,0,0,0,0,128,128,128,128,64,64,64,64,32,32,32,32,16,16,16,16,8,8,8,8,8,4,4,4,4,4,2,2,2,2,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,128,112,25,6,0,0,0,0,0,0,0,24,24,24,27,3,0,64,160,34,36,20,18,18,18,11,8,8,8,8,5,5,9,9,16,16,16,16,16,17,15,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,128,128,128,128,64,64,64,64,32,32,32,32,16,16,16,16,8,8,8,8,8,4,4,4,4,4,2,3,2,2,1,1,1,1,1,1,2,2,4,4,8,8,8,8,8,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
//     },
//     {
//         0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,128,128,0,0,0,0,0,128,64,64,32,32,32,32,16,16,16,16,8,4,2,1,1,2,12,48,64,128,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,128,128,128,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,30,225,0,0,1,1,2,2,1,0,0,0,0,128,128,0,0,0,0,0,0,0,0,0,128,0,48,48,0,192,193,193,194,4,8,16,32,64,128,0,0,0,128,128,128,128,64,64,64,64,32,32,32,32,16,16,16,16,8,8,8,8,8,4,4,4,4,4,2,2,2,2,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,128,112,12,3,0,0,0,0,0,0,0,12,12,12,13,1,0,64,160,33,34,18,17,17,17,9,8,8,8,8,4,4,8,8,16,16,16,16,16,17,15,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,128,128,128,128,64,64,64,64,32,32,32,32,16,16,16,16,8,8,8,8,8,4,4,4,4,4,2,3,2,2,1,1,1,1,1,1,2,2,4,4,8,8,8,8,8,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
//     }};
//     static const char PROGMEM prep[][ANIM_SIZE] = {{
//         0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,128,128,0,0,0,0,0,128,64,64,32,32,32,32,16,16,16,16,8,4,2,1,1,2,12,48,64,128,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,128,128,128,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,30,225,0,0,1,1,2,2,129,128,128,0,0,128,128,0,0,0,0,0,0,0,0,0,128,0,48,48,0,0,1,225,26,6,9,49,53,1,138,124,0,0,128,128,128,128,64,64,64,64,32,32,32,32,16,16,16,16,8,8,8,8,8,4,4,4,4,4,2,2,2,2,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,128,112,12,3,0,0,24,6,5,152,153,132,195,124,65,65,64,64,32,33,34,18,17,17,17,9,8,8,8,8,4,4,4,4,4,4,2,2,2,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,128,128,128,128,64,64,64,64,32,32,32,32,16,16,16,16,8,8,8,8,8,4,4,4,4,4,2,3,2,2,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
//     }};
//     static const char PROGMEM tap[TAP_FRAMES][ANIM_SIZE] = {
//         {
//             0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,128,128,0,0,0,0,0,128,64,64,32,32,32,32,16,16,16,16,8,4,2,1,1,2,12,48,64,128,0,0,0,0,0,0,0,248,248,248,248,0,0,0,0,0,128,128,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,128,128,128,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,30,225,0,0,1,1,2,2,129,128,128,0,0,128,128,0,0,0,0,0,0,0,0,0,128,0,48,48,0,0,1,1,2,4,8,16,32,67,135,7,1,0,184,188,190,159,95,95,79,76,32,32,32,32,16,16,16,16,8,8,8,8,8,4,4,4,4,4,2,2,2,2,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,128,112,12,3,0,0,24,6,5,152,153,132,67,124,65,65,64,64,32,33,34,18,17,17,17,9,8,8,8,8,4,4,8,8,16,16,16,16,16,17,15,1,61,124,252,252,252,252,252,60,12,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,128,128,128,128,64,64,64,64,32,32,32,32,16,16,16,16,8,8,8,8,8,4,4,4,4,4,2,3,2,2,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
//         },
//         {
//             0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,128,128,0,0,0,0,0,128,64,64,32,32,32,32,16,16,16,16,8,4,2,1,1,2,12,48,64,128,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,128,128,128,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,30,225,0,0,1,1,2,2,1,0,0,0,0,128,128,0,0,0,0,0,0,0,0,0,128,0,48,48,0,0,1,225,26,6,9,49,53,1,138,124,0,0,128,128,128,128,64,64,64,64,32,32,32,32,16,16,16,16,8,8,8,8,8,4,4,4,4,4,2,2,2,2,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,128,112,12,3,0,0,0,0,0,0,0,0,0,0,1,1,0,64,160,33,34,18,17,17,17,9,8,8,8,8,4,4,4,4,4,4,2,2,2,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,128,128,128,128,64,64,64,64,32,32,32,32,16,16,16,16,8,8,8,8,8,4,4,4,4,4,2,3,122,122,121,121,121,121,57,49,2,2,4,4,8,8,8,8,8,7,0,0,0,48,60,124,124,126,126,126,126,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
//         },
//     };

//     // assumes 1 frame prep stage
//     void animation_phase(void) {
//         if (get_current_wpm() <= IDLE_SPEED) {
//             current_idle_frame = (current_idle_frame + 1) % IDLE_FRAMES;
//             oled_write_raw_P(idle[abs((IDLE_FRAMES - 1) - current_idle_frame)], ANIM_SIZE);
//         }
//         if (get_current_wpm() > IDLE_SPEED && get_current_wpm() < TAP_SPEED) {
//             // oled_write_raw_P(prep[abs((PREP_FRAMES-1)-current_prep_frame)], ANIM_SIZE); // uncomment if IDLE_FRAMES >1
//             oled_write_raw_P(prep[0], ANIM_SIZE); // remove if IDLE_FRAMES >1
//         }
//         if (get_current_wpm() >= TAP_SPEED) {
//             current_tap_frame = (current_tap_frame + 1) % TAP_FRAMES;
//             oled_write_raw_P(tap[abs((TAP_FRAMES - 1) - current_tap_frame)], ANIM_SIZE);
//         }
//     }
//     if (get_current_wpm() != 000) {
//         oled_on(); // not essential but turns on animation OLED with any alpha keypress
//         if (timer_elapsed32(anim_timer) > ANIM_FRAME_DURATION) {
//             anim_timer = timer_read32();
//             animation_phase();
//         }
//         anim_sleep = timer_read32();
//     } else {
//         if (timer_elapsed32(anim_sleep) > OLED_TIMEOUT) {
//             oled_off();
//         } else {
//             if (timer_elapsed32(anim_timer) > ANIM_FRAME_DURATION) {
//                 anim_timer = timer_read32();
//                 animation_phase();
//             }
//         }
//     }
// }

static void print_status_narrow(void) {
    // Print current mode
    oled_write_P(PSTR("\n"), false);
    oled_write_ln_P(PSTR("MODE"), false);
    oled_write_ln_P(PSTR(""), false);
    if (keymap_config.swap_lctl_lgui) {
        oled_write_ln_P(PSTR("MAC"), false);
    } else {
        oled_write_ln_P(PSTR("WIN"), false);
    }

    oled_write_ln_P(PSTR("Qwrt"), false);
    oled_write_P(PSTR("\n\n"), false);
    // Print current layer
    oled_write_ln_P(PSTR("LAYER"), false);
    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            oled_write_P(PSTR("Base\n"), false);
            break;
        case _RAISE:
            oled_write_P(PSTR("Raise"), false);
            break;
        case _LOWER:
            oled_write_P(PSTR("Lower"), false);
            break;
        case _ADJUST:
            oled_write_P(PSTR("Adj\n"), false);
            break;
        // case _NUMPAD:
        //     oled_write_P(PSTR("Nump\n"), false);
        //     break;
        default:
            oled_write_ln_P(PSTR("Undef"), false);
    }
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_270;
    } else {
        return OLED_ROTATION_180;
    }
    return rotation;
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        print_status_narrow();
    } else {
        // render_anim();
        oled_set_cursor(0, 0);
        sprintf(wpm_str, "WPM:%03d", get_current_wpm());
        oled_write(wpm_str, false);
        oled_set_cursor(15,3);
        oled_write_P(PSTR("J.Jang"), false);
    }
    return false;
}

#endif

// layer_state_t layer_state_set_user(layer_state_t state) {
//     return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
// }

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;
        case KC_PRVWD:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    register_mods(mod_config(MOD_LALT));
                    register_code(KC_LEFT);
                } else {
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_LEFT);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LALT));
                    unregister_code(KC_LEFT);
                } else {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_LEFT);
                }
            }
            break;
        case KC_NXTWD:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    register_mods(mod_config(MOD_LALT));
                    register_code(KC_RIGHT);
                } else {
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_RIGHT);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LALT));
                    unregister_code(KC_RIGHT);
                } else {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_RIGHT);
                }
            }
            break;
        case KC_LSTRT:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    // CMD-arrow on Mac, but we have CTL and GUI swapped
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_LEFT);
                } else {
                    register_code(KC_HOME);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_LEFT);
                } else {
                    unregister_code(KC_HOME);
                }
            }
            break;
        case KC_LEND:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    // CMD-arrow on Mac, but we have CTL and GUI swapped
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_RIGHT);
                } else {
                    register_code(KC_END);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_RIGHT);
                } else {
                    unregister_code(KC_END);
                }
            }
            break;
        case KC_DLINE:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_BSPC);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_BSPC);
            }
            break;
        case KC_COPY:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_C);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_C);
            }
            return false;
        case KC_PASTE:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_V);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_V);
            }
            return false;
        case KC_CUT:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_X);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_X);
            }
            return false;
            break;
        case KC_UNDO:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_Z);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_Z);
            }
            return false;
        case KC_LOWER:
            if (record->event.pressed) {
                layer_on(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            return false;
        case KC_RAISE:
            if (record->event.pressed) {
                layer_on(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            return false;
    }
    return true;
}

#ifdef ENCODER_ENABLE
static uint8_t volume_counter = 0;
bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            if (volume_counter % 2 == 0) {
                tap_code(KC_VOLU);
            }
        } else {
            if (volume_counter % 2 == 0) {
                tap_code(KC_VOLD);
            }
        }
        volume_counter++;

    } else if (index == 1) {
        switch (get_highest_layer(layer_state)) {
            case _QWERTY:
                // scroll wheel
                if (clockwise) {
                    tap_code(KC_WH_D);
                } else {
                    tap_code(KC_WH_U);
                }
                break;
            case _RAISE:
            case _LOWER:
                // line up/down
                if (clockwise) {
                    tap_code(KC_DOWN);
                } else {
                    tap_code(KC_UP);
                }
                break;
            default:
                // scroll wheel
                if (clockwise) {
                    tap_code(KC_WH_D);
                } else {
                    tap_code(KC_WH_U);
                }
                break;
        }
    }
    return false;
}

#endif
