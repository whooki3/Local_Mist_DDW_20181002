
int streams = 13;
int trail = strip.numPixels() / streams / 2;


void dataAnim() {

  

  for (int i = 0; i < ring.numPixels(); i++) {
    ring.setPixelColor(i, ring.Color(255, 255, 255));
    ring.show();
    delay(35);
  }

  for (int i = 0; i < ring.numPixels(); i++) {
    ring.setPixelColor(i, ring.Color(0, 0, 0));
    ring.show();
    delay(45);
  }

  for (int i = 0; i < strip.numPixels() + trail + (trail * streams * 2); i++) {

    for (int j = 0; j < strip.numPixels(); j++) {
      strip.setPixelColor(j, strip.Color(0, 0, 0));
    }



    for (int k = 0; k < trail; k++) {

      //          strip.setPixelColor(i - k, strip.Color(255 / k, 255 / k, 255 / k));

      for ( int s = 1; s <= streams * 2; s++) {
        if (s % 2) {
          strip.setPixelColor(i - (k + (trail * s)), strip.Color(255 / k, 255 / k, 255 / k));
        }
        else {
          strip.setPixelColor(i - (k + (trail * s)), strip.Color(0, 0, 0));
        }
      }


    }


    strip.show();
  }

  Serial.println(1);
}
