// For led chips like WS2812, which have a data line, ground, and power

#include <FastLED.h>

#define BRIGHTNESS 50
// How many leds in your strip?
#define NUM_LEDS 4 
#define DATA_PIN 7
#define POTAR_PIN A5

// Define the array of leds
CRGB leds[NUM_LEDS];
float Level = 0;
float val_analogique = 0;

void annimation_leds(){
  for(int k = 0; k<3; k++){
    for(int z = 0; z<20; z++){
      for (int i = 0; i < NUM_LEDS; i++) {
      leds[i] = CRGB::White;
      }
      FastLED.setBrightness(5*z/2); //percent of brightness
      FastLED.show();
      delay(50);
    }
    delay(50);
  }
}

void setup() {
  //Serial.begin(9600);
  pinMode(POTAR_PIN, INPUT);
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);  // GRB ordering is assumed
  annimation_leds();
  FastLED.setBrightness(BRIGHTNESS); //percent of brightness
}

void loop() {
  val_analogique = analogRead(POTAR_PIN);
  Level = val_analogique*5/1024;
  //Serial.print(val_analogique);
  //Serial.print("---");
  //Serial.println(Level);
  if(Level <= 1.8){
    leds[0] = CRGB::Black;
    leds[1] = CRGB::Black;
    leds[2] = CRGB::Black;
    leds[3] = CRGB::Black;
  }
  else if(Level > 1.8 && Level <= 2.3){
    leds[0] = CRGB::Red;
    leds[1] = CRGB::Black;
    leds[2] = CRGB::Black;
    leds[3] = CRGB::Black;
  }
  else if(Level > 2.3 && Level <= 2.8){
    leds[0] = CRGB::Red;
    leds[1] = CRGB::Red;
    leds[2] = CRGB::Black;
    leds[3] = CRGB::Black;
  }
  else if(Level > 2.8 && Level <= 3.3){
    leds[0] = CRGB::Red;
    leds[1] = CRGB::Red;
    leds[2] = CRGB::Red;
    leds[3] = CRGB::Black;
  }
  else if(Level > 3.8){
    leds[0] = CRGB::Red;
    leds[1] = CRGB::Red;
    leds[2] = CRGB::Red;
    leds[3] = CRGB::Red;
  }
      FastLED.show();
      delay(300);
}