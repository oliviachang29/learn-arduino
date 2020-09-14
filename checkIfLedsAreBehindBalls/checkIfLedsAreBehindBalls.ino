#include <FastLED.h>
#define NUM_LEDS 128
#define DATA_PIN 5
CRGB leds[NUM_LEDS];
unsigned int counter=0;
void setup() {
    FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
}
void loop() { 
     counter++;
     leds[counter%128]=CHSV(counter%255,255,255);
     leds[(counter+64)%128]=CHSV(counter%255,255,255);
     FastLED.show(); 
     leds[counter%128]=CHSV(0,0,0);
     leds[(counter+64)%128]=CHSV(0,0,0);
     delay(200); 
}
