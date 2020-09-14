#include <FastLED.h>
#define LED_PIN     5
#define NUM_LEDS    128
#define BRIGHTNESS  32
CRGB leds[NUM_LEDS];
CHSV colour( 0, 255, 180);
int timecounter=0;
int counter=0;
const int Digits[10][10] =
{
  {7,8,10,11,14,18,22,24},
  {14,16,18,22,24},
  {7,8,9,11,14,16,18,24},
  {7,9,11,14,16,18,22,24},
  {9,10,11,16,18,22,24},
  {7,9,10,11,14,16,18,22},
  {7,8,9,14,15,16,18,22},
  {7,11,14,16,17,24},
  {7,8,9,10,11,14,16,18,22,24},
  {7,9,10,11,14,16,17,24},
};

void setup()
{
    FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
    FastLED.setBrightness(  BRIGHTNESS );
}

void displaynumber( int place , int number){
  for (int i = 0 ; i < 10 ; i++) {
    if (Digits[number/10][i] != 0) {
      leds[(Digits[number/10][i]+place)] = CRGB(255,255,255);
    }
    if (Digits[number%10][i] != 0) {
      leds[(Digits[number%10][i]+28+place)] = CRGB(255,255,255);
    }
  }
}

void loop(){
  timecounter=(timecounter+1)%10000;
  
  //changes the colour of background every 10 cycles
  if (counter<5){
    counter++;
  }else{
    colour.hue = (colour.hue+1)%256;
    counter=0;
  }  // sets background to rainbow colours
  for ( int i=0; i< 128;i++){
    colour.hue = (colour.hue+1)%256;
    leds[i]= colour;
  }
  colour.hue = (colour.hue+128)%256;
  
  // numbers
  displaynumber(0,timecounter/100);
  displaynumber(70,timecounter/100);
  
  // colons
  leds[64] = CRGB(255,255,255);
  leds[66] = CRGB(255,255,255);

  FastLED.show();
}
