#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>
#endif

#define RING_PIN 6
#define STRIP_PIN 9


Adafruit_NeoPixel strip = Adafruit_NeoPixel(107, STRIP_PIN, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel ring = Adafruit_NeoPixel(24, RING_PIN, NEO_GRB + NEO_KHZ800);

byte incomingByte;

#include "datastream.h"
#include "occupied.h"
#include "progress.h"


void setup() {
  // This is for Trinket 5V 16MHz, you can remove these three lines if you are not using a Trinket
#if defined (__AVR_ATtiny85__)
  if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
#endif
  // End of trinket special code
  Serial.begin(9600);
  Serial.setTimeout(500);

  ring.begin();
  ring.show();

  strip.begin();
  strip.show();


}

void loop() {

  if (Serial.available() > 0) {
    // read the incoming byte:
    incomingByte = Serial.read();

    if (incomingByte == 't') {
        dataAnim();
    }

    if (incomingByte == 'i') {
        someoneIsIn = true;
    }

    if (incomingByte == 'o') {

        for (int i = ring.numPixels(); i >= 0; i--) {
          ring.setPixelColor(i, ring.Color(0, 0, 0));    
        ring.show();
        delay(20);
      }
      
        someoneIsIn = false;
    }

    // ZET EEN LETTER P VOOR DE PERCENTAGE
    percentage = 

    percentageRead = Serial.parseFloat();

    if(percentageRead == 0){
      percentage = lastPercentage;
    } else {
      

    if(someoneIsIn){
      for (int i = ring.numPixels(); i >= 0; i--) {
          ring.setPixelColor(i, ring.Color(0, 0, 0));    
        ring.show();
        delay(20);
      }

      someoneIsIn = false;
    }
      
      percentage = percentageRead;
    }
    
  }

  //Serial.println(percentage);

  if( someoneIsIn ) {
    blockAnim();
  }
  else {
    showProgress();
  }
  

}







