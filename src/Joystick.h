#ifndef Joystick_h
#define Joystick_h
#include <Arduino.h>
#include "Message.h"
 
 
#include <U8g2lib.h>//importing LED library
 
U8G2_SSD1306_128X32_UNIVISION_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE); //M0/ESP32/ESP8266/mega2560/Uno/Leonardo
// Set the LCD address to 0x27 for a 16 chars and 2 line display
 
class Joystick{
 
 
 private:
   int X_pin;
   int Y_pin;
   int SW_pin;
 
   int joyX; //X value
   int joyY; //Y value
   int SW; //Joystick Button
 
   bool a = true;
 
   // Add public: to make the methods below accessible, otherwise, the previous private: would make everything private.
public:
 
 
   // Constructor for the Joystick
   Joystick (int X_pin, int Y_pin, int SW_pin, Message *message)
   {
    
     this->message = message;
 
     this->X_pin= X_pin;
     pinMode (this->X_pin, INPUT);
     this->Y_pin = Y_pin;
     pinMode (this->Y_pin, INPUT);
     this->SW_pin = SW_pin;
     pinMode (this->SW_pin, INPUT_PULLUP);
 
 
   }
 
   Message* message;
 
 
    void updateJSState(){
 
     joyX = analogRead(X_pin);
     joyY = analogRead(Y_pin);
     SW = digitalRead(SW_pin);
 
   }
 
  String movement(){
 
     String m; 
do {
 
 if(joyX>1700 && joyX<1800){
   joyX=1750;
 }
 if(joyY>1790 && joyY<1900){
   joyY =1850;
 }
 
 if(SW == 0){
  message->sendMessage("nothing");
  u8g2.setCursor(/* x=*/0, /* y=*/34);    //Define the cursor of print function, any output of the print function will start at this position.
  u8g2.print("NOTHING");
  
  Serial.print("Joystick Button Pressed");
 Serial.println("");
 }
 if(joyY > 3000){
 message->sendMessage("up");
 u8g2.setCursor(20,34); 
 u8g2.print("UP");
}
if(joyY < 1000){
 message->sendMessage("down");
 u8g2.setCursor(0,34);   
  u8g2.print("Down");
}
if(joyX > 3000){
 message->sendMessage("right");
 u8g2.setCursor(0,34);   
  u8g2.print("Right");
}
if(joyX < 1000){
message->sendMessage("left");
 u8g2.setCursor(0,34);    
  u8g2.print("Left");
}
 } while ( u8g2.nextPage() );
 
//u8g2.setFont(u8g2_font_ncenB08_tr);
 u8g2.setFont(u8g2_font_logisoso34_tf);
 u8g2.setFontDirection(0); 
 u8g2.firstPage();
 
 
 return m;
 
 
 }  
 
    String printJoystickState(){
 
     String s;
 
        Serial.println("\nThe X value is: ");
        Serial.println(joyX);
 
        Serial.println("\nThe Y Value is: ");
        Serial.println(joyY);
  
 
 return s;
    
  }
  
};
#endif
