int streams = 4;
//const int trail = strip.numPixels() / streams / 2;
const int trail = 9;

void dataAnim() {

  for (int i = strip.numPixels() + trail + (trail * streams * 2); i >= 0 ; i--) {

    for (int j = 0; j < strip.numPixels(); j++) {
      strip.setPixelColor(j, strip.Color(0, 0, 0));
    }
    
    for (int k = 1; k <= trail; k++) {
      int brightness = 255 / ((k - trail-1)*-1);
      delay(3);

      for ( int s = 1; s <= streams * 2; s++) {
        if (s % 2) {
        strip.setPixelColor(i - (k + (trail * s)), strip.Color(brightness,brightness,brightness));
        }
        else {
        strip.setPixelColor(i - (k + (trail * s)), strip.Color(0,0,0));
        }
      }
    }

    strip.show();
  }


}

