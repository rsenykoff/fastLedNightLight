#include <FastLED.h>        //  http://fastled.io/
#include <RotaryEncoder.h>  //  https://github.com/mathertel/RotaryEncoder

/*  LED SETUP  */
#define LED_PIN     15
#define NUM_LEDS    19
int BRIGHTNESS =    255; //value to be controlled by the rotary encoder
#define LED_TYPE    NEOPIXEL
//#define COLOR_ORDER GRB
CRGB leds[NUM_LEDS];

/* Rotary Encoder Setup */
#define ROTARYSTEPS 3 // multiplier for how fast it adjusts the value
#define ROTARYMIN 0
#define ROTARYMAX 255
#define ROTARYBUTTON 27
RotaryEncoder encoder(14, 32); //adjust pins for your needs


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



// Gradient palette "liahlah2_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/rc/tn/liahlah2.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 40 bytes of program space.

DEFINE_GRADIENT_PALETTE( liahlah2_gp ) {
  0,  38, 73, 145,
  30,   7, 19, 51,
  56,  73, 40, 230,
  86,  55, 49, 182,
  112,  15, 135, 250,
  140, 125, 122, 212,
  170,  13, 55, 228,
  198, 123, 65, 228,
  229,   7, 19, 51,
  255,  38, 73, 145
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

// Gradient palette "galaxy02_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/pd/astro/tn/galaxy02.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 196 bytes of program space.

DEFINE_GRADIENT_PALETTE( galaxy02_gp ) {
  0, 247, 133, 36,
  5, 210, 125, 41,
  10, 179, 118, 45,
  15, 157, 103, 41,
  21, 135, 90, 37,
  26, 125, 85, 33,
  31, 117, 81, 30,
  37,  95, 68, 25,
  42,  77, 56, 21,
  47,  58, 44, 15,
  53,  42, 33, 11,
  58,  31, 27, 10,
  63,  22, 22,  8,
  69,  20, 20,  9,
  74,  18, 18, 10,
  79,  19, 20, 10,
  84,  19, 22, 10,
  90,  24, 26, 13,
  95,  30, 31, 17,
  100,  34, 39, 23,
  106,  39, 47, 30,
  111,  41, 62, 37,
  116,  44, 79, 44,
  122,  47, 70, 38,
  127,  51, 60, 34,
  132,  53, 55, 31,
  138,  56, 49, 29,
  143,  55, 52, 35,
  148,  54, 54, 42,
  154,  50, 49, 34,
  159,  46, 45, 28,
  164,  46, 47, 31,
  170,  46, 49, 34,
  175,  50, 51, 31,
  180,  56, 52, 27,
  185,  59, 59, 37,
  191,  64, 68, 50,
  196,  66, 77, 47,
  201,  69, 85, 43,
  207,  78, 80, 43,
  212,  87, 77, 43,
  217,  94, 81, 46,
  223, 103, 86, 49,
  228, 117, 96, 59,
  233, 133, 107, 69,
  239, 163, 135, 84,
  244, 199, 164, 102,
  249, 224, 171, 100,
  255, 252, 176, 98
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
SimplePatternList gPatterns = { warmPalette1, solidColor };

uint8_t gCurrentPatternNumber = 0; // Index number of which pattern is current


//CRGBPalette16 currentPalette( CRGB::Black);
CRGBPalette16 currentPalette( Fuschia_6_gp );

CRGBPalette16 targetPalette( Fuschia_6_gp );


void setup() {
  delay( 1000 ); // power-up safety delay
  Serial.begin(115200);
  delay(10);
  Serial.println("serial comm started");

  pinMode(ROTARYBUTTON, INPUT);

  FastLED.addLeds<NEOPIXEL, LED_PIN>(leds, NUM_LEDS).setCorrection ( TypicalLEDStrip );
  //FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
  FastLED.clear ();
  FastLED.setBrightness(  BRIGHTNESS );
}



String buttonStatus = "";
String newStatus = "";

// max number of changes to the palette during a blend operation
// I prefer low values with faster updates
uint8_t maxChanges = 10;

static uint8_t startIndex = 0;
int pos = 0;
void loop()
{
  encoder.tick();
  // get the current physical position and calc the logical position
  int newPos = encoder.getPosition() * ROTARYSTEPS;

  if (newPos < ROTARYMIN) {
    encoder.setPosition(ROTARYMAX / ROTARYSTEPS);
    newPos = ROTARYMAX;
  } else if (newPos > ROTARYMAX) {
    encoder.setPosition(ROTARYMIN / ROTARYSTEPS);
    newPos = ROTARYMIN;
  } // if

  if (pos != newPos) {
    Serial.print(newPos);
    Serial.println();
    pos = newPos;
  } // if

  EVERY_N_MILLISECONDS ( 50 )
  {
    newStatus = getButtonStatus();    
  }
  
  if (newStatus != buttonStatus)
  {
    buttonStatus = newStatus;
    Serial.println(buttonStatus);
    if (buttonStatus == "LOW")
      toggleRoutine(); 
  }
 
  gPatterns[gCurrentPatternNumber]();


BRIGHTNESS = pos;
EVERY_N_MILLISECONDS(200) {
  ChangePalettePeriodically();
};


// rotation speed. lower millis to go faster
EVERY_N_MILLISECONDS ( 32 ) startIndex++;

// how often to blend and write to the LEDS
EVERY_N_MILLISECONDS( 16 ) {
  nblendPaletteTowardPalette( currentPalette, targetPalette, maxChanges );
  FillLEDsFromPaletteColors( startIndex);
  FastLED.show();
};
}

#define ARRAY_SIZE(A) (sizeof(A) / sizeof((A)[0]))

void toggleRoutine() {
  Serial.println("toggling routine");
  gCurrentPatternNumber = (gCurrentPatternNumber + 1) % ARRAY_SIZE( gPatterns);
}

void warmPalette1()
{
  EVERY_N_MILLISECONDS(1000) { Serial.println("warm palette"); };
}

void solidColor()
{
  EVERY_N_MILLISECONDS(1000) { Serial.println("solid colors"); };
}

uint8_t placeOnColorPalette = 0;

void FillLEDsFromPaletteColors( uint8_t colorIndex)
{
  for ( int i = 0; i < NUM_LEDS; i++) {
    //    leds[i] = ColorFromPalette( currentPalette, colorIndex + sin8(i*16), BRIGHTNESS);
    placeOnColorPalette = colorIndex + sin8( round((i * (256 / NUM_LEDS)) / 2 )); // <-- change divisor here for how much we spread out the spectrum on the leds
    leds[i] = ColorFromPalette( currentPalette, placeOnColorPalette, BRIGHTNESS);
    // Serial.println(sin8( i * 12 ));
  }
}

// The code below is not how I would recommend changing palettes.
// Instead we'll create a way to iterate over a list of palettes when triggered
// by another EVERY_N_MILLISECONDS kind of thing.
// Anyways, below is where you can easily mess with
// the colors and palettes. The RainbowColors_p, LavaColors_p, ... are built
// in palettes that use minimal memory so are nice to use. On this ESP32 board
// though there's tons of memory so totally custom palettes are no problem.
//
//--Ron




void ChangePalettePeriodically()
{
  uint8_t secondHand = (millis() / 1000) % 60;
  static uint8_t lastSecond = 99;

  if ( lastSecond != secondHand) {
    lastSecond = secondHand;
    CRGB p = CHSV( HUE_PURPLE, 255, 255);
    CRGB g = CHSV( HUE_GREEN, 255, 255);
    CRGB bl = CHSV( HUE_BLUE, 255, 255);
    CRGB b = CRGB::Black;
    CRGB w = CRGB::White;
    //    if( secondHand ==  0)  { targetPalette = RainbowColors_p;
    if ( secondHand ==  0)  {
      targetPalette = October_Sky_gp;
      Serial.println("sky 45 for Owen");
    }
    if ( secondHand == 16)  {
      targetPalette = Quick_Vent_gp;
      Serial.println("quick vent");
    }
    /*   if( secondHand == 10)  { targetPalette = CRGBPalette16( g,p,b,bl, p,p,bl,p, p,g,b,b, bl,p,bl,b);
                                 //Serial.println("purple blue");
                               } */
    // if( secondHand == 20)  { targetPalette = CRGBPalette16( b,b,b,w, b,b,b,w, b,b,b,w, b,b,b,w);
    //Serial.println("black white");
    // }
    if ( secondHand == 20)  {
      targetPalette = Warm_summer_day_gp;
      Serial.println("sky 33 for Savannah");
    }
    if ( secondHand == 36)  {
      targetPalette = Quick_Vent_gp;
      Serial.println("wild orange");
    }
    if ( secondHand == 40)  {
      targetPalette = Warm_summer_day_gp;
      Serial.println("molten lava");
    }
    if ( secondHand == 56)  {
      targetPalette = Quick_Vent_gp;
      Serial.println("liahlah2");
    }
  }
}
