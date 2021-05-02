// NeoPixel Ring simple sketch (c) 2013 Shae Erisson
// Released under the GPLv3 license to match the rest of the
// Adafruit NeoPixel library

#include "pico/stdio.h"
#include "pico/time.h"
#include <tusb.h>
#include "Adafruit_NeoPixel.hpp"

// Which pin on the Arduino is connected to the NeoPixels?
#define PIN        27 // On Trinket or Gemma, suggest changing this to 1

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS 60 // Popular NeoPixel ring size

// When setting up the NeoPixel library, we tell it how many pixels,
// and which pin to use to send signals. Note that for older NeoPixel
// strips you might need to change the third parameter -- see the
// strandtest example for more information on possible values.


#define DELAYVAL 50 // Time (in milliseconds) to pause between pixels
#define CYCLEDELAY 12 // Time to wait after a cycle
static uint8_t level = 0 ;

uint8_t adjust (uint8_t value) {
	if (level == 0) return value ;
	return ((value * neopixels_gamma8(level)) >> 8) ;
};
	

void example() {
  Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

  
  pixels.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
  pixels.setBrightnessFunctions(adjust,adjust,adjust,adjust);
 

  
  for (int l=0 ; l <4 ; l++) {
  pixels.clear(); // Set all pixel colors to 'off'
   printf("cleared pixels 1, level = %d\n",level); 

  for(int i=0; i<NUMPIXELS; i++) { // For each pixel...
    pixels.setPixelColor(i,pixels.Color(222, 49, 99));
//	pixels2.setPixelColor(NUMPIXELS - (i +1),pixels2.Color((i%3)*150,((i+1)%3)*150 ,((i+2)%3)*150));
    pixels.show();   // Send the updated pixel colors to the hardware.
//	pixels2.show() ;
    sleep_ms(DELAYVAL); // Pause before next pass through loop
  }
  for (int i=0; i <255 ; i++) {
  level = (255-i) ;
  pixels.setBrightnessFunctions(adjust,adjust,adjust,adjust);
  pixels.show() ;
  sleep_ms(CYCLEDELAY);
  }
  level = 0 ;
  }
};
  


int main () {
	
  stdio_init_all();
  while (!tud_cdc_connected()) {sleep_ms(100);}
  printf("Starting simple\n"); 
  example() ;
  printf ("Ending example\n");
  example() ;
  printf("Ending 2nd example\n");
  sleep_ms(5000);
};