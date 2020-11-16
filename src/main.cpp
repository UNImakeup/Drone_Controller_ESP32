#include <Arduino.h>
#include <U8g2lib.h>//importing LED library
#include "AsyncUDP.h"
#include "Wifi.h"
#include "Joystick.h"
#include "Button.h"
#include "Message.h"


//#include "WiFi.h"
//#include <Button.h> //importing accelerometer class
//#include <Message.h>
//#include <Joystick.h> //importing joytick class
 
const int X_pin = 32; // analog pin connected to X output
const int Y_pin = 33; //analog pin connected to Y output
const int SW_pin = 18; // digital pin connected to switch output
const int Button_pin = 17; // digital pin connected to button
bool a = true;
 
// Creating a Udp connection including sendMessage method
Message message = Message();
// Creating a joystick object
Joystick joystick = Joystick(X_pin, Y_pin, SW_pin, &message);
// Creating a button object
Button button(Button_pin, &message);
 
void setup() {
 
Serial.begin(9600);
//Wire.begin();
u8g2.begin(); //init OLED
u8g2.enableUTF8Print(); // Enable UTF8 support for Arduino print（）function.
message.wifi();//connection to Wifi
 
}
 
// Loop must be at the bottom for the code in order to compile without errors
void loop() {
 
 // Always update for all objects at the start of the loop
 button.updateBState();
 joystick.updateJSState();
 
 //printing out the state of the objects
 Serial.println(joystick.printJoystickState());
 joystick.movement();
 Serial.println(button.movement());
 
// Wait some time before running the loop again as to not flood the terminal with information.
 delay(500);
 
}
 
 
