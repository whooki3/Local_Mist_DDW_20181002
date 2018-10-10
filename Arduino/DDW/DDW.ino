#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>
#endif

#define RING_PIN 6
#define STRIP_PIN 9


Adafruit_NeoPixel strip = Adafruit_NeoPixel(300, STRIP_PIN, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel ring = Adafruit_NeoPixel(24, RING_PIN, NEO_GRB + NEO_KHZ800);

byte incomingByte;

#include "datastream.h"
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

    if (incomingByte == 'x') {
      for (int i = 0; i < 1; i++) {
        dataAnim();
      }
    }

    // ZET EEN LETTER P VOOR DE PERCENTAGE
    percentage = Serial.parseFloat();
  }

  showProgress();

}







