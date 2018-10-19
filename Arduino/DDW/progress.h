float percentage;

int currentPixel = 0;

float lastPercentage = 1;
float percentageRead;


void showProgress() {

  //  if ( percentage > 100 || percentage < 1) {
  //    percentage = 1;
  //
  //    for (int i = ring.numPixels(); i >= 0; i--) {
  //      ring.setPixelColor(i, ring.Color(0, 0, 0));
  //      //Serial.println(i);
  //      delay(25);
  //      ring.show();
  //    }
  //  }

  // Calculations
  float result = ring.numPixels() * (percentage / 100);
  int allPixels = round(result);
  float excess = result - (int)result;
  int brightness = (255 / 100) * percentage ;


 
  if (percentage < lastPercentage) {
    for (int i = ring.numPixels(); i >= 0; i--) {
      ring.setPixelColor(i, ring.Color(0, 0, 0));
      ring.show();
      delay(25);
    }
  }
 
    for (int i = 0; i < allPixels; i++) {

      ring.setPixelColor(i, ring.Color(brightness, brightness, brightness));

      delay(45);
      ring.show();
    }

  

  if ( percentage >= 100 ) {
    Serial.println(0);
    for (int i = 0; i < ring.numPixels(); i++) {

      ring.setPixelColor(i, ring.Color(0, 0, 0));

      delay(45);
      ring.show();
    }

    
    dataAnim();
    someoneIsIn = true;
  }


 lastPercentage = percentage;

}
