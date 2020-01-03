#include <FastLED.h>        //  http://fastled.io/
#include <RotaryEncoder.h>  //  https://github.com/mathertel/RotaryEncoder

/*  LED SETUP  */
#define LED_PIN     15
#define NUM_LEDS    120
int BRIGHTNESS =    255; //value to be controlled by the rotary encoder

#define LED_TYPE    NEOPIXEL
//#define COLOR_ORDER GRB
CRGB leds[NUM_LEDS];
int MAX_POWER = 10000; // in milliamps assuming 5 volts

/* Rotary Encoder Setup */
#define ROTARYSTEPS 3 // multiplier for how fast it adjusts the value
#define ROTARYMIN 0
#define ROTARYMAX 255
#define ROTARYBUTTON 13
#define SHOW_FPS false

RotaryEncoder encoder1(32, 14); //adjust pins for your needs


// This example shows how to cross-fade between different color palettes
// using the function nblendPaletteTowardPalette.
//
// The basic idea is that you always have a "current palette" that you're
// pulling colors from with ColorFromPalette, and you have a "target palette"
// which is the 'next' palette that you want to get to.

// Gradient palette "October_Sky_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/jjg/ccolo/sugar/tn/October_Sky.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 44 bytes of program space.

DEFINE_GRADIENT_PALETTE( October_Sky_gp ) {
  0,  42,  7, 11,
  71,  42,  7, 11,
  142,  75,  9, 12,
  156, 121, 11, 14,
  170, 153, 18, 12,
  184, 192, 25, 11,
  198, 213, 43,  8,
  212, 232, 66,  5,
  226, 229, 91,  7,
  240, 227, 122,  9,
  255, 227, 122,  9
};

// original modified for no blue led
DEFINE_GRADIENT_PALETTE( Ron_Sky_gp ) {
  0, 42, 7, 0,
  50, 192, 25, 0,
  90, 213, 43,  0,
  130, 232, 66,  0,
  170, 229, 91,  0,
  210, 227, 122,  0,
  255, 227, 122,  0
};

// original modified for no blue led
// Gradient palette "sky_04_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/rafi/tn/sky-04.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 16 bytes of program space.

DEFINE_GRADIENT_PALETTE( sky_04_gp ) {
  0, 255, 189,  0,
  200, 110, 19,  0,
  255,  27,  5,  0
};


// original modified for no blue led
// Gradient palette "sky_31_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/rafi/tn/sky-31.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 20 bytes of program space.

DEFINE_GRADIENT_PALETTE( sky_31_gp ) {
  0,  87,  8,  0,
  63, 142, 33,  0,
  131, 157, 71, 0,
  219,  27,  2,  0,
  255,  27,  2,  0
};


/**** END OF NO BLUE PALETTES ************************************/


// Gradient palette "All_kinds_of_green_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/jjg/ccolo/smorin2002/tn/All_kinds_of_green.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 44 bytes of program space.

DEFINE_GRADIENT_PALETTE( All_kinds_of_green_gp ) {
    0, 203,248, 95,
   25, 203,248, 95,
   51, 167,223, 87,
   76, 135,197, 78,
  102, 104,197, 63,
  127,  78,197, 49,
  153,  56,184, 51,
  178,  39,173, 52,
  204,  30,136, 43,
  229,  21,105, 36,
  255,  21,105, 36};

// Gradient palette "sky_21_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/rafi/tn/sky-21.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 20 bytes of program space.

DEFINE_GRADIENT_PALETTE( sky_21_gp ) {
    0, 255,164, 49,
   40, 227,141, 72,
   87, 125,149,135,
  178,   0, 31, 52,
  255,   1, 10, 22};

// Gradient palette "springangel_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/rc/tn/springangel.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 44 bytes of program space.

DEFINE_GRADIENT_PALETTE( springangel_gp ) {
    0,  95,151,140,
   48,  35,101,170,
   71,  74,103,111,
   94,  77, 97,111,
  117, 165,142,132,
  140, 186,142,128,
  163, 182,124, 96,
  186, 188, 95, 57,
  209, 220, 88, 28,
  232,  92, 86, 41,
  255,  92, 86, 41};

// Gradient palette "Adrift_in_Dreams_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/jjg/ccolo/Skyblue2u/tn/Adrift_in_Dreams.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 44 bytes of program space.

DEFINE_GRADIENT_PALETTE( Adrift_in_Dreams_gp ) {
    0, 148,223, 77,
   25, 148,223, 77,
   51, 115,201, 83,
   76,  86,182, 89,
  102,  57,156, 80,
  127,  36,131, 72,
  153,  17, 93, 61,
  178,   5, 61, 51,
  204,   1, 34, 38,
  229,   1, 15, 29,
  255,   1, 15, 29};

// Gradient palette "liahlah2_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/rc/tn/liahlah2.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 40 bytes of program space.

DEFINE_GRADIENT_PALETTE( liahlah2_gp ) {
    0,  38, 73,145,
   30,   7, 19, 51,
   56,  73, 40,230,
   86,  55, 49,182,
  112,  15,135,250,
  140, 125,122,212,
  170,  13, 55,228,
  198, 123, 65,228,
  229,   7, 19, 51,
  255,  38, 73,145};

// Gradient palette "springbird_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/rc/tn/springbird.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 16 bytes of program space.

DEFINE_GRADIENT_PALETTE( springbird_gp ) {
    0,  10, 45,147,
   38,  10, 45,147,
  216, 192,121,162,
  255, 192,121,162};



/****** COOL2 ****/

// Gradient palette "spellbound_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/rc/tn/spellbound.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 84 bytes of program space.

DEFINE_GRADIENT_PALETTE( spellbound_gp ) {
    0, 232,235, 40,
   12, 157,248, 46,
   25, 100,246, 51,
   45,  53,250, 33,
   63,  18,237, 53,
   81,  11,211,162,
   94,  18,147,214,
  101,  43,124,237,
  112,  49, 75,247,
  127,  49, 75,247,
  140,  92,107,247,
  150, 120,127,250,
  163, 130,138,252,
  173, 144,131,252,
  186, 148,112,252,
  196, 144, 37,176,
  211, 113, 18, 87,
  221, 163, 33, 53,
  234, 255,101, 78,
  247, 229,235, 46,
  255, 229,235, 46};

// Gradient palette "titannightfall_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/rc/tn/titannightfall.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 28 bytes of program space.

DEFINE_GRADIENT_PALETTE( titannightfall_gp ) {
    0, 173, 72,109,
   28, 112, 33, 68,
   51,  72, 19, 67,
  127,   2,  1, 33,
  204,  72, 19, 67,
  229, 112, 33, 68,
  255, 173, 72,109};

// Gradient palette "trove_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/rc/tn/trove.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 84 bytes of program space.

DEFINE_GRADIENT_PALETTE( trove_gp ) {
    0,  12, 23, 11,
   12,   8, 52, 27,
   25,  32,142, 64,
   38,  55, 68, 30,
   51, 190,135, 45,
   63, 201,175, 59,
   76, 186, 80, 20,
   89, 220, 79, 32,
  101, 184, 33, 14,
  114, 137, 16, 15,
  127, 118, 20, 27,
  140,  79, 16, 35,
  153,  67,  8, 26,
  165,  22,  9, 42,
  178,  11,  3, 34,
  191,  58, 31,109,
  204, 186, 49, 83,
  216, 182, 25, 55,
  229,  39, 90,100,
  242,  15, 81,132,
  255,  68,135, 52};

// Gradient palette "sunlitwave_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/rc/tn/sunlitwave.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 32 bytes of program space.

DEFINE_GRADIENT_PALETTE( sunlitwave_gp ) {
    0,   5,  9, 84,
   45,  37, 24,111,
   81,  16,  5, 59,
  112,  24,  1, 20,
  150,  34,  1,  2,
  198, 175, 36,  7,
  237, 208,104, 16,
  255, 239,211,158};

// Gradient palette "hangonfatboy_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/rc/tn/hangonfatboy.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 40 bytes of program space.

DEFINE_GRADIENT_PALETTE( hangonfatboy_gp ) {
    0, 215, 74,  6,
   30,  74, 22, 53,
   61,  18,  6, 27,
   96,   5, 36, 85,
  114,   1,  8, 30,
  140,   1,  8, 30,
  158,   5, 36, 85,
  193,  18,  6, 27,
  224,  74, 22, 53,
  255, 215, 74,  6};

// Gradient palette "serendil_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/rc/tn/serendil.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 24 bytes of program space.

DEFINE_GRADIENT_PALETTE( serendil_gp ) {
    0,   0, 55,  0,
  117,  61, 81,  9,
  137, 132, 86, 10,
  191, 215,221, 42,
  211, 237,112,184,
  255, 192, 19, 19};

// Gradient palette "mellon_ball_surprise_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/jjg/ccolo/Skyblue2u/tn/mellon_ball_surprise.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 44 bytes of program space.

DEFINE_GRADIENT_PALETTE( mellon_ball_surprise_gp ) {
    0, 152,227, 85,
   25, 152,227, 85,
   51, 182,235, 95,
   76, 215,244,106,
  102, 234,189, 79,
  127, 255,142, 56,
  153, 255,115, 51,
  178, 255, 90, 45,
  204, 242, 59, 52,
  229, 229, 36, 62,
  255, 229, 36, 62};

// Gradient palette "Everglowing_Wonder_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/jjg/ccolo/electroluv/tn/Everglowing_Wonder.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 44 bytes of program space.

DEFINE_GRADIENT_PALETTE( Everglowing_Wonder_gp ) {
    0, 167,244, 89,
   71, 167,244, 89,
  142, 126,211, 52,
  146,  92,182, 26,
  150,  78,130, 20,
  164,  66, 86, 14,
  178,  55, 44, 14,
  186,  46, 16, 13,
  193,  40, 10, 10,
  224,  34,  5,  9,
  255,  34,  5,  9};






// Gradient palette "sky_33_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/rafi/tn/sky-33.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 20 bytes of program space.

DEFINE_GRADIENT_PALETTE( sky_33_gp ) {
  0, 237, 229, 140,
  51, 227, 107, 79,
  87, 155, 55, 54,
  178,  22, 28, 36,
  255,   5, 19, 31
};

// Gradient palette "sky_45_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/rafi/tn/sky-45.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 20 bytes of program space.

DEFINE_GRADIENT_PALETTE( sky_45_gp ) {
  0, 249, 205,  4,
  51, 255, 239, 123,
  87,   5, 141, 85,
  178,   1, 26, 43,
  255,   0,  2, 23
};

// Gradient palette "aquamarinemermaid_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/rc/tn/aquamarinemermaid.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 20 bytes of program space.

DEFINE_GRADIENT_PALETTE( aquamarinemermaid_gp ) {
  0,  23,  4, 32,
  63,  98, 31, 52,
  127, 224, 138, 24,
  191,   7, 55, 164,
  255,  23,  4, 32
};

// Gradient palette "Quick_Vent_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/lb/mp/tn/Quick_Vent.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 80 bytes of program space.

DEFINE_GRADIENT_PALETTE( Quick_Vent_gp ) {
  0,   0,  0,  0,
  25,  42, 55, 45,
  25, 255, 255, 255,
  51,  42, 55, 45,
  51,   0,  0,  0,
  76,  42, 55, 45,
  76, 255, 255, 255,
  101,  42, 55, 45,
  101,   0,  0,  0,
  127,  42, 55, 45,
  127, 255, 255, 255,
  153,  42, 55, 45,
  153,   0,  0,  0,
  178,  42, 55, 45,
  178, 255, 255, 255,
  204,  42, 55, 45,
  204,   0,  0,  0,
  229,  42, 55, 45,
  229, 255, 255, 255,
  255,  42, 55, 45
};

// Gradient palette "Quick_Vent_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/lb/mp/tn/Quick_Vent.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 80 bytes of program space.

DEFINE_GRADIENT_PALETTE( Ron_Vent_gp ) {
  0,   30,  30,  30,
  25,  42, 55, 45,
  25, 255, 255, 255,
  51,  42, 55, 45,
  51,   30,  30,  30,
  76,  42, 55, 45,
  76, 255, 255, 255,
  101,  42, 55, 45,
  101,   30,  30,  30,
  127,  42, 55, 45,
  127, 255, 255, 255,
  153,  42, 55, 45,
  153,   30,  30,  30,
  178,  42, 55, 45,
  178, 255, 255, 255,
  204,  42, 55, 45,
  204,   30,  30,  30,
  229,  42, 55, 45,
  229, 255, 255, 255,
  255,  42, 55, 45
};

// Gradient palette "Wild_Orange_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/lb/mp/tn/Wild_Orange.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 56 bytes of program space.

DEFINE_GRADIENT_PALETTE( Wild_Orange_gp ) {
  0,   0,  0,  0,
  0, 144, 11,  1,
  0, 144, 11,  1,
  5, 144, 11,  1,
  10, 194, 36,  1,
  30, 252, 79,  1,
  86, 249, 175, 100,
  106, 244, 122, 25,
  124, 237, 79,  1,
  157, 244, 154,  2,
  196, 252, 255,  5,
  209, 252, 223,  3,
  239, 255, 108,  1,
  255, 255, 36,  1
};

// Gradient palette "Molten_lava_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/lb/mp/tn/Molten_lava.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 32 bytes of program space.

DEFINE_GRADIENT_PALETTE( Molten_lava_gp ) {
  0,  40,  2,  1,
  17, 206, 30,  9,
  35, 194, 21,  1,
  51, 255, 55, 17,
  198, 194, 21,  1,
  216, 220, 42,  4,
  232, 255, 84, 22,
  255, 220, 42,  4
};

// Gradient palette "gr67_hult_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/hult/tn/gr67_hult.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 20 bytes of program space.

DEFINE_GRADIENT_PALETTE( gr67_hult_gp ) {
  0,  42,  5,  1,
  63, 194, 175,  3,
  127,  42,  5,  1,
  191, 194, 175,  3,
  255,  42,  5,  1
};

// Gradient palette "Fuschia_6_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/ds/fuschia/tn/Fuschia-6.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 36 bytes of program space.

DEFINE_GRADIENT_PALETTE( Fuschia_6_gp ) {
  0, 148,  6, 180,
  31, 142, 16, 197,
  63, 135, 31, 216,
  95,  90, 17, 226,
  127,  56,  8, 233,
  159,  98,  7, 192,
  191, 153,  6, 156,
  223,  98,  7, 192,
  255,  56,  8, 233
};

// Gradient palette "Warm_summer_day_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/jjg/ccolo/smorin2002/tn/Warm_summer_day.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 44 bytes of program space.

DEFINE_GRADIENT_PALETTE( Warm_summer_day_gp ) {
  0, 255, 225, 39,
  25, 255, 225, 39,
  51, 229, 239, 38,
  76, 206, 255, 38,
  102, 169, 255, 38,
  127, 137, 255, 38,
  153, 109, 255, 38,
  178,  84, 255, 38,
  204,  64, 255, 38,
  229,  46, 255, 38,
  255,  46, 255, 38
};

String getButtonStatus() {
  int buttonState = digitalRead(ROTARYBUTTON);
  String result = "";
  if (buttonState == HIGH)
    result = "HIGH";
  else
    result = "LOW";

  return result;
}

// List of patterns to cycle through.  Each is defined as a separate function below.
typedef void (*SimplePatternList[])();
SimplePatternList gPatterns = { rainbow, chooseSolid, chooseSaturation, warmPalette1, coolPalette1, coolPalette2, fillGradient2, rainbow, rainbowWithGlitter, confetti, sinelon }; //*****************

uint8_t gCurrentPatternNumber = 0; // Index number of which pattern is current


void setup() {
  delay( 1000 ); // power-up safety delay
  Serial.begin(115200);
  delay(10);
  Serial.println("serial comm started");

  pinMode(ROTARYBUTTON, INPUT);

  FastLED.addLeds<NEOPIXEL, LED_PIN>(leds, NUM_LEDS).setCorrection ( TypicalLEDStrip );
  //FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );

  //especially useful when limiting for USB supply
  FastLED.setMaxPowerInMilliWatts(MAX_POWER);

  
  FastLED.clear ();
  FastLED.setBrightness( BRIGHTNESS );

  //FastLED.setDither( 0 ); // FastLED temporal dithering. At very low light levels it causes flickering, 0 disables
  
  //flash the strip to indicate it's working
  for (int i = 0; i < 5; i++)
  {
    fillSolid();
    delay(50);
    FastLED.clear();
    FastLED.show();
    delay(50);
  }
}


String buttonStatus = "";
String newStatus = "";


static uint8_t startIndex = 0;
int pos = 0;
int newPos = 0;
boolean firstTime = true;

void loop()
{
  encoder1.tick();
  // get the current physical position and calc the logical position

  if (firstTime)
  {
    encoder1.setPosition(4); // initial brightness
    firstTime = false;
  }
  newPos = encoder1.getPosition() * ROTARYSTEPS;

  if (newPos < ROTARYMIN) {
    encoder1.setPosition(ROTARYMAX / ROTARYSTEPS);
    newPos = ROTARYMAX;
  } else if (newPos > ROTARYMAX) {
    encoder1.setPosition(ROTARYMIN / ROTARYSTEPS);
    newPos = ROTARYMIN;
  } 

  if (pos != newPos) {
    Serial.print("BRIGHTNESS: ");
    Serial.print(newPos);
    Serial.println();
    pos = newPos;
  } 

  // I found I needed to use this 'delay' as a debounce technique
  EVERY_N_MILLISECONDS ( 50 ) newStatus = getButtonStatus();
  
  if (newStatus != buttonStatus)
  {
    buttonStatus = newStatus;
    Serial.println(buttonStatus);
    if (buttonStatus == "LOW")
      toggleRoutine();
  }

  gPatterns[gCurrentPatternNumber]();

  if (gCurrentPatternNumber == 1 || gCurrentPatternNumber == 2)
  {
    
  }
  else BRIGHTNESS = pos;
  
  if (SHOW_FPS == true ) //for clarity not brevity
    showfps();

}

#define ARRAY_SIZE(A) (sizeof(A) / sizeof((A)[0]))

void toggleRoutine() {
  Serial.println("toggling routine");
  gCurrentPatternNumber = (gCurrentPatternNumber + 1) % ARRAY_SIZE( gPatterns);
  fillSolid();
  delay(500);
}

// examples of fill and gradients
// https://github.com/atuline/FastLED-Demos/blob/master/fill_colours/fill_colours.ino
void fillSolid()
{
  CHSV hueToFillWith(245, 128, 255);
  fill_solid(leds, NUM_LEDS, hueToFillWith);
  
  for (int i = 0; i < NUM_LEDS; i++)
    leds[i].fadeLightBy( 255 - BRIGHTNESS );

  FastLED.show();
}

int savedColor = 128;
void chooseSolid()
{
  savedColor = pos;
  CHSV hueToFillWith(savedColor, 255, 255);
  fill_solid(leds, NUM_LEDS, hueToFillWith);
  
  for (int i = 0; i < NUM_LEDS; i++)
    leds[i].fadeLightBy( 255 - BRIGHTNESS );

  FastLED.show();
}

int savedSaturation = 255;
void chooseSaturation()
{
  savedSaturation = pos;
  CHSV hueToFillWith(savedColor, savedSaturation, 255);
  fill_solid(leds, NUM_LEDS, hueToFillWith);
  
  for (int i = 0; i < NUM_LEDS; i++)
    leds[i].fadeLightBy( 255 - BRIGHTNESS );

  FastLED.show();
}

void fillGradient1()
{
  CHSV hue1(250, 255, 255);
  CHSV hue2(210, 255, 255);
  fill_gradient(leds, NUM_LEDS, hue1, hue2, SHORTEST_HUES);
  
  // Dim a color by X/256ths
  // using "video" scaling, meaning: never fading to full black
  for (int i = 0; i < NUM_LEDS; i++)
    leds[i].fadeLightBy( 255 - BRIGHTNESS );

  FastLED.show();

  //  fill_solid(leds+5,5, CRGB::Green);
  //  fill_solid(leds+10,5, hsvval);

  // fill_gradient section
  //  fill_gradient_RGB(leds, startpos, 0x000011, endpos, 0x110000);   // You can mix and match long values and CRGB values. Remember, endpos goes up to NUM_LEDS-1
  //  fill_gradient_RGB(leds, NUM_LEDS, CRGB(50,0,200), CRGB(80,200,240));  // up to 4 CRGB (or long) values

  //FORWARD_HUES, BACKWARD_HUES, SHORTEST_HUES, LONGEST_HUES
  //  fill_gradient(leds, startpos, CHSV(50, 255,255) , endpos, CHSV(150,255,255), SHORTEST_HUES);
  //  fill_gradient(leds, NUM_LEDS, CHSV(50, 255,255), CHSV(100,255,255), LONGEST_HUES);    // up to 4 CHSV values

  // fill_rainbow section
  //  fill_rainbow(leds, NUM_LEDS, thishue, deltahue);            // Use FastLED's fill_rainbow routine.
  //  fill_solid(leds,NUM_LEDS,0);                                // Clear the strip for. . .
  //  fill_rainbow(leds+1, NUM_LEDS-2, thishue, deltahue);        // One pixel border at each end.

}

//uint8_t hueValueToRotate = 0;
void fillGradient2()
{
  int hueValueToRotate = beatsin8(2, 0, 127, 90);
  //int hueValueToRotate2 = beatsin8(2, 128, 255, 90);
  int hueValueToRotate2 = hueValueToRotate + 128;
  CHSV hue2(hueValueToRotate2, 255, 255);
  CHSV hueToRotate(hueValueToRotate, 255, 255);
  //fill_gradient(leds, NUM_LEDS, hue1, hueToRotate, hue2, SHORTEST_HUES);
 
  fill_gradient(leds, NUM_LEDS, hue2, hueToRotate, SHORTEST_HUES);
  
  for (int i = 0; i < NUM_LEDS; i++)
  {
    // Dim a color by X/256ths
    // using "video" scaling, meaning: never fading to full black
    leds[i].fadeLightBy( 255 - BRIGHTNESS );
  }
  FastLED.show();
}

CRGBPalette16 currentPalette( Ron_Sky_gp );
CRGBPalette16 targetPalette( Ron_Sky_gp );

// max number of changes to the palette during a blend operation
// I prefer low values with faster updates
uint8_t maxChanges = 7;

void warmPalette1()
{
  EVERY_N_MILLISECONDS(1000) {
    Serial.println("warmPalette1");
  };
  EVERY_N_MILLISECONDS(200) {
    ChangePaletteWarm1();
  };

  // rotation speed. lower millis to go faster
  EVERY_N_MILLISECONDS ( 48 ) startIndex++;

  // how often to blend and write to the LEDS
  EVERY_N_MILLISECONDS( 8) {
    nblendPaletteTowardPalette( currentPalette, targetPalette, maxChanges );
    FillLEDsFromPaletteColors( startIndex);
  };
  
  FastLED.show();
}

void coolPalette1()
{
  EVERY_N_MILLISECONDS(1000) {
    Serial.println("coolPalette1");
  };
  EVERY_N_MILLISECONDS(200) {
    ChangePaletteCool1();
  };

  // rotation speed. lower millis to go faster
  EVERY_N_MILLISECONDS ( 32 ) startIndex++;

  // how often to blend and write to the LEDS
  EVERY_N_MILLISECONDS( 8 ) {
    nblendPaletteTowardPalette( currentPalette, targetPalette, maxChanges );
    FillLEDsFromPaletteColors( startIndex);
  };

    FastLED.show();
}

void coolPalette2()
{
  EVERY_N_MILLISECONDS(1000) {
    Serial.println("coolPalette2");
  };
  EVERY_N_MILLISECONDS(200) {
    ChangePaletteCool2();
  };

  // rotation speed. lower millis to go faster
  EVERY_N_MILLISECONDS ( 32 ) startIndex++;

  // how often to blend and write to the LEDS
  EVERY_N_MILLISECONDS( 8 ) {
    nblendPaletteTowardPalette( currentPalette, targetPalette, maxChanges );
    FillLEDsFromPaletteColors( startIndex);
  };

  FastLED.show();
}

uint8_t gHue = 110; // rotating "base color" used by many of the patterns

void rainbow()
{
  EVERY_N_MILLISECONDS(1000) {
    Serial.println("rainbow");
  };
  EVERY_N_MILLISECONDS( 48 ) {
    gHue++;  // slowly cycle the "base color" through the rainbow
  }
  fill_rainbow( leds, NUM_LEDS, gHue, 5); //lower number spreads out the rainbow more

  // Dim a color by X/256ths
  // using "video" scaling, meaning: never fading to full black
  for (int i = 0; i < NUM_LEDS; i++)
    leds[i].fadeLightBy( 255 - BRIGHTNESS );

  FastLED.show();
}

void rainbowWithGlitter()
{
  EVERY_N_MILLISECONDS(1000) {
    Serial.println("rainbow with glitter");
  };
  EVERY_N_MILLISECONDS( 48 ) gHue++; // slowly cycle the "base color" through the rainbow
  fill_rainbow( leds, NUM_LEDS, gHue, 5); //lower number spreads out the rainbow more

  for (int i = 0; i < NUM_LEDS; i++)
    leds[i].fadeLightBy( 255 - BRIGHTNESS );

  addGlitter(10);
  //EVERY_N_MILLISECONDS(8)
  FastLED.show();
}

void addGlitter( fract8 chanceOfGlitter)
{
  if ( random8() < chanceOfGlitter) {
    leds[ random16(NUM_LEDS) ] += CRGB::White;
  }
}

void confetti()
{
  EVERY_N_MILLISECONDS(64) fadeToBlackBy( leds, NUM_LEDS, 2);
  EVERY_N_MILLISECONDS(10) gHue++;
  EVERY_N_MILLISECONDS(2000) Serial.println("confetti");

  EVERY_N_MILLISECONDS(200)
  {
    int daPos = random16(NUM_LEDS);
    int posLeft = daPos - 1;
    if (posLeft < 0) posLeft = 0;
    int posRight = daPos + 1;
    if (posRight > (NUM_LEDS - 1)) posRight = NUM_LEDS - 1;

    //  leds[pos] += CHSV( gHue + random8(64), 255, 255);
    uint8_t randomValue = gHue + random8(64);
    leds[daPos] += CHSV( randomValue, 255, 255 );
    leds[posLeft] += CHSV( randomValue, 200, round(255 / 1.5));
    leds[posRight] += CHSV( randomValue, 200, round(255 / 1.5));

    leds[daPos].fadeLightBy( 255 - BRIGHTNESS );
    leds[posLeft].fadeLightBy( 255 - BRIGHTNESS );
    leds[posRight].fadeLightBy( 255 - BRIGHTNESS );
  }
  FastLED.show();
}

uint8_t gHue2 = 0;
void sinelon()
{
  // a colored dot sweeping back and forth, with fading trails
  EVERY_N_MILLISECONDS(16) fadeToBlackBy( leds, NUM_LEDS, 3);
  EVERY_N_MILLISECONDS(40) gHue++;
  EVERY_N_MILLISECONDS(8) gHue2++;

  EVERY_N_MILLISECONDS(2000) Serial.println("sinelon");
  int pos = beatsin16(5, 0, NUM_LEDS - 1);
  int pos2 = beatsin16(10, 0, NUM_LEDS - 1);
  leds[pos] += CHSV( gHue, 255, 255);
  leds[pos2] += CHSV( gHue2, 255, 255);

  leds[pos].fadeLightBy( 255 - BRIGHTNESS );
  leds[pos2].fadeLightBy( 255 - BRIGHTNESS );
  
  FastLED.show();
}

uint8_t placeOnColorPalette = 0;

void FillLEDsFromPaletteColors( uint8_t colorIndex)
{
  for ( int i = 0; i < NUM_LEDS; i++)
  {
      //leds[i] = ColorFromPalette( currentPalette, colorIndex + sin8(i*16), 255);
    placeOnColorPalette = colorIndex + sin8( round((i * (256 / NUM_LEDS)) / 4 )); // <-- change divisor here for how much we spread out the spectrum on the leds
    leds[i] = ColorFromPalette( currentPalette, placeOnColorPalette, 255); //full bright then dim with scaling
    // Dim a color by X/256ths
    // using "video" scaling, meaning: avoids fading a single led (R,G,B) to 0 which would look wrong 
    leds[i].fadeLightBy( 255 - BRIGHTNESS );
  }
}

void ChangePaletteWarm1()
{
  uint8_t secondHand = (millis() / 1000) % 60;
  static uint8_t lastSecond = 99;

  if ( lastSecond != secondHand) {
    lastSecond = secondHand;
    //    if( secondHand ==  0)  { targetPalette = RainbowColors_p;
    if ( secondHand ==  0)  {
      targetPalette = Ron_Sky_gp;
      //     targetPalette = sky_31_gp;
      Serial.println("Ron_Sky_gp");
    }
    if ( secondHand == 10)  {
      //      targetPalette = Ron_Vent_gp;
      targetPalette = sky_04_gp;

      Serial.println("sky_04_gp");
    }
    if ( secondHand == 20)  {
      //      targetPalette = Warm_summer_day_gp;
      targetPalette = sky_31_gp;
      Serial.println("sky_31_gp");
    }
    if ( secondHand == 30)  {
      targetPalette = Ron_Sky_gp;
      Serial.println("Ron_Sky_gp");
    }
    if ( secondHand == 40)  {
      targetPalette = sky_04_gp;
      Serial.println("sky_04_gp");
    }
    if ( secondHand == 50)  {
      targetPalette = sky_31_gp;
      Serial.println("sky_31_gp");
    }
  }
}

void ChangePaletteCool1()
{
  uint8_t secondHand = (millis() / 1000) % 60;
  static uint8_t lastSecond = 99;

  if ( lastSecond != secondHand) {
    lastSecond = secondHand;
    if ( secondHand ==  0)  {
      targetPalette = Warm_summer_day_gp;
      Serial.println("Warm_summer_day_gp");
    }
    if ( secondHand == 10)  {
      //      targetPalette = Ron_Vent_gp;
      targetPalette = All_kinds_of_green_gp;
      Serial.println("All_kinds_of_green_gp");
    }
    if ( secondHand == 20)  {
      targetPalette = sky_21_gp;
      Serial.println("sky_21_gp");
    }
    if ( secondHand == 30)  {
      targetPalette = springangel_gp;
      Serial.println("springangel_gp");
    }
    if ( secondHand == 40)  {
      targetPalette = Adrift_in_Dreams_gp;
      Serial.println("Adrift_in_Dreams_gp");
    }
    if ( secondHand == 50)  {
      targetPalette = springbird_gp;
      Serial.println("springbird_gp");
    }
  }
}

void ChangePaletteCool2()
{
  uint8_t secondHand = (millis() / 1000) % 60;
  static uint8_t lastSecond = 99;

  if ( lastSecond != secondHand) {
    lastSecond = secondHand;
    if ( secondHand ==  0)  {
      targetPalette = spellbound_gp;
      Serial.println("spellbound_gp");
    }
    if ( secondHand == 10)  {
      targetPalette = trove_gp;
      Serial.println("trove_gp");
    }
    if ( secondHand == 20)  {
      targetPalette = sunlitwave_gp;
      Serial.println("sunlitwave_gp");
    }
    if ( secondHand == 30)  {
      targetPalette = hangonfatboy_gp;
      Serial.println("hangonfatboy_gp");
    }
    /* if ( secondHand == 10)  {
      targetPalette = Everglowing_Wonder_gp;
      Serial.println("Everglowing_Wonder_gp");
    }
    if ( secondHand == 20)  {
      targetPalette = mellon_ball_surprise_gp;
      Serial.println("mellon_ball_surprise_gp");
    }
    if ( secondHand == 30)  {
      targetPalette = spellbound_gp;
      Serial.println("spellbound_gp");
    } */
    if ( secondHand == 40)  {
      targetPalette = Everglowing_Wonder_gp;
      Serial.println("Everglowing_Wonder_gp");
    }
    if ( secondHand == 50)  {
      targetPalette = mellon_ball_surprise_gp;
      Serial.println("mellon_ball_surprise_gp");
    }
  }
}
int loops = 0;
void showfps() {                                              
  loops++;
  EVERY_N_MILLISECONDS(1000) {
    Serial.print("FPS: ");
    Serial.println(loops);
    loops = 0;
  }
}
