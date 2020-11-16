#ifndef Button_h
#define Button_h
#include <Arduino.h>
#include "Message.h"
 
#include <U8g2lib.h>//importing LED library
 
 
class Button{
 
 
   private:
   int B_pin;
   int B;
 
   // Add public: to make the methods below accessible, otherwise, the previous private: would make everything private.
   public:
 
   // Constructor for Button
   Button(int Button_Pin, Message *message){
      
           this-> message = message;
           this-> B_pin = Button_Pin;
           this-> B = B;
           pinMode(this->B_pin,INPUT_PULLUP);
 
    }
    //making a pointer to Message for the sendMessage method
    Message* message;
 
    // updateState reads the breadboard input and passes it to the Button variables.
   void updateBState(){
 
    B = digitalRead(B_pin);
   }
 
  
 String movement(){
 
   String m;
 
     if (B == 0){
      
         message->sendMessage("w");
         Serial.println("Create Button");
         // u8g2.setFont(u8g2_font_ncenB08_tr);
         //u8g2.setCursor(/* x=*/20, /* y=*/0);   
    
     }   return m;
  }
    
 
 
};
 
#endif
 
 
