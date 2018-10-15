/*------------------------------------------------------------------------
  Example sketch for Adafruit Thermal Printer library for Arduino.
  Demonstrates a few text styles & layouts, bitmap printing, etc.

  IMPORTANT: DECLARATIONS DIFFER FROM PRIOR VERSIONS OF THIS LIBRARY.
  This is to support newer & more board types, especially ones that don't
  support SoftwareSerial (e.g. Arduino Due).  You can pass any Stream
  (e.g. Serial1) to the printer constructor.  See notes below.

  You may need to edit the PRINTER_FIRMWARE value in Adafruit_Thermal.h
  to match your printer (hold feed button on powerup for test page).
  ------------------------------------------------------------------------*/

// TX (GROEN) 5
// RX (GEEL) 6


#include "Adafruit_Thermal.h"
#include "cmd.h"
#include "local_mist.h"

// Here's the new syntax when using SoftwareSerial (e.g. Arduino Uno) ----
// If using hardware serial instead, comment out or remove these lines:

#include "SoftwareSerial.h"
#define TX_PIN 6 // Arduino transmit  YELLOW WIRE  labeled RX on printer
#define RX_PIN 5 // Arduino receive   GREEN WIRE   labeled TX on printer

SoftwareSerial mySerial(RX_PIN, TX_PIN); // Declare SoftwareSerial obj first
Adafruit_Thermal printer(&mySerial);     // Pass addr to printer constructor
// Then see setup() function regarding serial & printer begin() calls.

// Here's the syntax for hardware serial (e.g. Arduino Due) --------------
// Un-comment the following line if using hardware serial:

//Adafruit_Thermal printer(&Serial1);      // Or Serial2, Serial3, etc.

// -----------------------------------------------------------------------


bool isPrinting = false;

void setup() {

  // This line is for compatibility with the Adafruit IotP project pack,
  // which uses pin 7 as a spare grounding point.  You only need this if
  // wired up the same way (w/3-pin header into pins 5/6/7):
  pinMode(7, OUTPUT);
  digitalWrite(7, LOW);

  Serial.begin(9600);

  mySerial.begin(19200);  // Initialize SoftwareSerial




  printer.begin();        // Init printer (same regardless of serial type)
  printer.feed(1);


}


int    Minimal_Age, Median_Age, Maximal_Age, Ethnicity, Sexual_Preference = 0;
float Female_Ratio, Male_Ratio = 0;

int DDWID, weekday, day, month, year, hour, minute = 0;


void loop() {

  // send data only when you receive data:
  //  if (Serial.available() > 0) {
  //    // read the incoming byte:
  //    String incomingByte = Serial.readString();
  //
  //    // say what you got:
  //    Serial.print("I received: ");
  //    Serial.println(incomingByte);
  //
  //    printer.println(incomingByte);
  //    printer.feed(2);
  //  }


  if (Serial.available() > 0) {
    
    int incomingByte = Serial.read();

    Minimal_Age = Serial.parseInt();
    Median_Age = Serial.parseInt();
    Maximal_Age = Serial.parseInt();
    Female_Ratio = Serial.parseFloat();
    Male_Ratio = Serial.parseFloat();
    Ethnicity = Serial.parseInt();
    Sexual_Preference = Serial.parseInt();

    DDWID = Serial.parseInt();
    weekday = Serial.parseInt();
    day = Serial.parseInt();
    month = Serial.parseInt();
    year = Serial.parseInt();
    hour = Serial.parseInt();
    minute = Serial.parseInt();


    if (Minimal_Age > 0  && !isPrinting) {
      isPrinting = true;

      printer.flush();
      PrintReciept();
      printer.flush();
      Minimal_Age, Median_Age, Maximal_Age, Ethnicity, Sexual_Preference = 0;
      Female_Ratio, Male_Ratio = 0;
      DDWID, weekday, day, month, year, hour, minute = 0;
    }


  }

  Serial.flush();

}

void PrintReciept() {

  printer.boldOn();
  printer.setSize('S');
  printer.justify('C');
  printer.printBitmap(Print_width, Print_height, Print_data);
  printer.println(F("Thank you for your data."));
  printer.boldOff();

  delay(100);

  printer.justify('L');
  printer.feed(1);

  printer.print(getWeekday(weekday));
  printer.print(" ");
  printer.print(day);
  printer.print(" ");
  printer.print(getMonth(month));
  printer.print(" ");
  printer.print(year);
  printer.print(" ");
  printer.print(hour);
  printer.print(":");
  printer.print(minute);
  printer.println(" ");
  printer.feed(1);

  delay(100);


  printer.print(F("Minimal_Age:        "));
  printer.boldOn();
  printer.println(Minimal_Age);
  printer.boldOff();

  delay(100);

  printer.print(F("Median_Age:         "));
  printer.boldOn();
  printer.println(Median_Age);
  printer.boldOff();

  delay(100);

  printer.print(F("Maximal_Age:        "));
  printer.boldOn();
  printer.println(Maximal_Age);
  printer.boldOff();

  printer.feed(1);
  delay(100);

  printer.print(F("Female_Ratio:       "));
  printer.boldOn();
  printer.print(Female_Ratio);
  printer.println("%");
  printer.boldOff();

  printer.print(F("Male_Ratio:         "));
  printer.boldOn();
  printer.print(Male_Ratio);
  printer.println("%");
  printer.boldOff();

  printer.feed(1);
  delay(100);

  printer.print(F("Ethnicity:          "));
  printer.boldOn();
  printer.println(convertEth(Ethnicity));
  printer.boldOff();

  printer.print(F("Sexual_Preference:  "));
  printer.boldOn();
  printer.println(convertSex(Sexual_Preference));
  printer.boldOff();

  printer.feed(1);
  delay(200);
  printer.printBitmap(cmd_width, cmd_height, CMD_LOGO);
  printer.feed(1);
  delay(200);
  
  
  printer.justify('C');
  printer.println(F("https://localmist.com"));


  printer.feed(3);
  printer.setDefault();

  isPrinting = false;

}

String convertSex(int s) {

  switch (s) {
    case 0:
      return "Heterosexual";
      break;
    case 1:
      return "Homosexual";
      break;
    default:
      return "Apache";
      break;
  }

}


String convertEth(int s) {
  switch (s) {
    case 0:
      return "White";
      break;
    case 1:
      return "Black";
      break;
    default:
      return "Other";
      break;
  }

}


String getWeekday(int w) {
  switch (w) {
    case 0:
      return "MON";
      break;
    case 1:
      return "TUE";
      break;
    case 2:
      return "WED";
      break;
    case 3:
      return "THU";
      break;
    case 4:
      return "FRI";
      break;
    case 5:
      return "SAT";
      break;
    case 6:
      return "SAT";
      break;
  }
}

String getMonth(int m) {
  switch (m) {
    case 1:
      return "JAN";
      break;
    case 2:
      return "FEB";
      break;
    case 3:
      return "MAR";
      break;
    case 4:
      return "APR";
      break;
    case 5:
      return "MAY";
      break;
    case 6:
      return "JUN";
      break;
    case 7:
      return "JUL";
      break;
    case 8:
      return "AUG";
      break;
    case 9:
      return "SEPT";
      break;
    case 10:
      return "OCT";
      break;
    case 11:
      return "NOV";
      break;
    case 12:
      return "DEC";
      break;
  }
}


String getID(int id) {
  return String("DDW-" + id);
}

