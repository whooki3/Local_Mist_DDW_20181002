bool someoneIsIn = false;
unsigned long previousMillis = 0;
const long interval = 500; 

bool state = false;

void blockAnim(){

  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    
    previousMillis = currentMillis;

    
    state = !state;


  }

  if( state ){
    for (int i = ring.numPixels(); i >= 0; i--) {
        if(i % 2 == 0){
          ring.setPixelColor(i, ring.Color(255/2, 0, 0));
        }
        else {
          ring.setPixelColor(i, ring.Color(255/4, 0, 0));
        }
        ring.show();
      }
  }
  else {
        for (int i = ring.numPixels(); i >= 0; i--) {
        if(i % 2 == 1){
          ring.setPixelColor(i, ring.Color(255/2, 0, 0));
        }
        else {
          ring.setPixelColor(i, ring.Color(255/4, 0, 0));
        }
        ring.show();
      }
    
  }

  
}

