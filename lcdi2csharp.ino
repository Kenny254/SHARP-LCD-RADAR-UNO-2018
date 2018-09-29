/*
 * Sharp IR (infrared) distance measurement module with LCD1602 and I2C for Arduino
 * Measures the distance in cm.

 * Watch the video https://youtu.be/RHgMwtKLEnE

 *  * 

Original library: https://github.com/guillaume-rico/SharpIR


// Written and updated by Ahmad Nejrabi for Robojax.com
// on Jan 03, 2018 at 20:01 in Ajax, Ontario, Canada
 * Permission granted to share this code given that this
 * note is kept with the code.
 * Disclaimer: this code is "AS IS" and for educational purpose only.
 * 
 /*
/*


#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2);

///////////////////***** start of Sharp IR
#include <SharpIR.h>

#define IR A0 // define Sharp IR signal pin
#define model 430 // the model of the IR module
// Sharp IR code for Robojax.com
// ir: the pin where your sensor is attached
// model: an int that determines your sensor:
/*
 * GP2Y0A02YK0F --> "20150"
 GP2Y0A21YK --> "1080"
 GP2Y0A710K0F --> "100500"
  GP2YA41SK0F --> "430"
 */

SharpIR SharpIR(IR, model);
/////////////////////**** end of Sharp IR

void setup()
{
  // Robojax code for LCD with I2C
  // initialize the LCD, 
  lcd.begin();
 
  // Turn on the blacklight and print a message.
  lcd.backlight();
  // Robojax code for LCD with I2C


}

void loop()
{
  
  //start of loop Robojax code for LCD with I2C
  lcd.clear();
  lcd.print("Robojax IR Test");
  lcd.setCursor (0,1); // go to start of 2nd line
 int dis=SharpIR.distance();// gets the distance in cm
 String distance = String(dis);
 distance ="Distance: "+distance+"cm";
 lcd.print(distance);
  //lcd.print(millis() / 1000);
  delay(500);
 //end of loopcode Robojax code for LCD with I2C
}
