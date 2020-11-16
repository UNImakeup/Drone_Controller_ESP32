#ifndef SendMessage_h
#define SendMessage_h
#include <Arduino.h>
#include "AsyncUDP.h"
#include "WiFi.h"
 
AsyncUDP udp;
 
class Message{
 
   public:
  
   Message(){
 
     }
 
// Connecting to the drone wifi
const char * ssid = "aliersej";
const char * password = "ganggang";
 
     //Wifi setup
void wifi(){
 WiFi.mode(WIFI_STA);
 WiFi.begin(ssid, password);
 if (WiFi.waitForConnectResult() != WL_CONNECTED) {
   Serial.println("WiFi Failed");
   while (1) {
     delay(1000);
   }
 }
 if (udp.listen(4000)) {
   Serial.print("UDP Listening on IP: ");
   Serial.println(WiFi.localIP());
   udp.onPacket([](AsyncUDPPacket packet) {
     Serial.print("UDP Packet Type: ");
     Serial.print(packet.isBroadcast()
                      ? "Broadcast"
                      : packet.isMulticast() ? "Multicast" : "Unicast");
     Serial.print(", From: ");
     Serial.print(packet.remoteIP());
     Serial.print(":");
     Serial.print(packet.remotePort());
     Serial.print(", To: ");
     Serial.print(packet.localIP());
     Serial.print(":");
     Serial.print(packet.localPort());
     Serial.print(", Length: ");
     Serial.print(packet.length());
     Serial.print(", Data: ");
     Serial.write(packet.data(), packet.length());
     Serial.println();
     // reply to the client/sender
     packet.printf("Got %u bytes of data", packet.length());
   });
 }
 // Send unicast
 // udp.print("Hello Server!");
 // udp.
 
}
 
      void sendMessage(String msg){
 
       udp.writeTo((const uint8_t *)msg.c_str(), msg.length(),
      IPAddress(192, 168, 43, 254), 6000);
 
       }
      
  };
 
#endif

