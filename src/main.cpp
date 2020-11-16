#include <Arduino.h>
#include <U8g2lib.h>//importing LED library
#include "AsyncUDP.h"
#include "Wifi.h"
#include "Joystick.h"
#include "Button.h"
#include "Message.h"

 
const int x = 32; // analog pin connected to X output
const int y = 33; //analog pin connected to Y output
const int sw = 17; // digital pin connected to switch output
const int b = 18; // digital pin connected to button
bool a = true;
 
// Creating a Udp connection including sendMessage method
Message message = Message();
// Creating a joystick object
Joystick joystick = Joystick(x, y, sw, &message);
// Creating a button object
Button button(b, &message);
 
void setup() {
 
Serial.begin(9600);
//Wire.begin();
u8g2.begin(); //init OLED
u8g2.enableUTF8Print(); // Enable UTF8 support for Arduino print（）function.
message.wifi();//connection to Wifi
 
}

void writeOnScreen(String write){}
 
// Loop must be at the bottom for the code in order to compile without errors
void loop() {
 
 // Always update for all objects at the start of the loop
 button.updateBState();
 joystick.updateJSState();
 
 //printing out the state of the objects
 Serial.println(joystick.printJoystickState());
 joystick.movement();
 Serial.println(button.movement());
 
 
}
 
 
