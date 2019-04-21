/* This is the code for Arduino MKR1000 used in the 'Smart Relay' part of the 'Smart Table Assistant project' built for the 
 *  'Smart Homes on the Edge' contest conducted by Hackster.io and sponsored by Seeed and Snips.
 * 
 * Contest Page - https://www.hackster.io/contests/building-for-voice
 * 
 * Blog Link - 
 * 
 * Author : Dixon Selvan
 * Date   : April 11, 2019
 * Project: Smart Table Assitant
 * Website: 
 * 
 * Hardware components Required
 * ----------------------------
 * 1. Arduino MKR1000 board
 * 2. Few Jumper wires
 * 3. [Optional] 3.7V Lithium Battery
 * 
 * Connecting Arduino MKR1000 with thinger.io, getting started guide - http://docs.thinger.io/arduino/
 */

/*Disabling the secure TLS/SSL connection*/
#define _DISABLE_TLS_

#include <WiFi101.h>
#include <ThingerWifi101.h>
#include "arduino_secrets.h"

/*Declaring Variables*/
int relayState = 0;

/*Create an account in thinger.io and replace username below with that username. 
Create a new device and replace deviceId, deviceCredential below with the one you had created.*/
ThingerWifi101 thing(SECRET_USERNAME, SECRET_DEVICEID, SECRET_DEVICECREDENTIAL);

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
    
  /*Serial initialisation*/
  Serial1.begin(38400);
  
  /*Replace the below accrodingly with your WiFi SSID and password*/
  thing.add_wifi(SECRET_SSID, SECRET_PASS);

  /*The relay state is obtained as an input resource (integer/ number) from thinger.io*/
  thing["Relay"] << [](pson& in){
      relayState = in["state"];
      changeRelayState();
  };
}

void loop() {
  thing.handle();
}

void changeRelayState(){
  if(relayState == 1)
  {
    digitalWrite(LED_BUILTIN, HIGH);
    Serial1.print(1);
  }
  else if (relayState == 2){
    digitalWrite(LED_BUILTIN, LOW);
    Serial1.print(2);
  }
  else if(relayState == 3)
  {
    digitalWrite(LED_BUILTIN, HIGH);
    Serial1.print(3);
  }
  else if (relayState == 4){
    digitalWrite(LED_BUILTIN, LOW);
    Serial1.print(4);
  }
  else  if(relayState == 5)
  {
    digitalWrite(LED_BUILTIN, HIGH);
    Serial1.print(5);
  }
  else if (relayState == 6){
    digitalWrite(LED_BUILTIN, LOW);
    Serial1.print(6);
  }
}
