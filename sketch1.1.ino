
#include <Arduino.h>
#include "AsyncTelegram.h"
AsyncTelegram myBot;
 
const char* ssid = "Tatka_Vatutinki";
const char* pass = "kuderso1";
const char* token = "7373320672:AAF0WQ9YR7Ko73BWTyOOFNTC8kJZkoMBqPM";    
 
int led = 2; 
 
void setup() 
{
  // initialize the Serial
  Serial.begin(115200);
  Serial.println("Starting TelegramBot...");
 
  WiFi.setAutoConnect(true);   
  WiFi.mode(WIFI_STA);
  
  WiFi.begin(ssid, pass);
  delay(500);
  while (WiFi.status() != WL_CONNECTED) 
  {
  Serial.print('.');
  delay(500);
  }
 
  myBot.setUpdateTime(1000);
  myBot.setTelegramToken(token);
  
  Serial.print("\nTest Telegram connection... ");
  myBot.begin() ? Serial.println("OK") : Serial.println("NOK");
 
  pinMode(led, OUTPUT);
  digitalWrite(led, HIGH); 
}
 
void loop() 
{
  TBMessage msg;
 
  if (myBot.getNewMessage(msg)) 
  {
    if (msg.text.equalsIgnoreCase("On")) 
    {      
      digitalWrite(led, LOW);                          
      myBot.sendMessage(msg, "Light is now ON");        
    }
    else if (msg.text.equalsIgnoreCase("Off")) 
    {       
      digitalWrite(led, HIGH);                         
      myBot.sendMessage(msg, "Light is now OFF");      
    }
    else 
    {                                                  
      // generate the message for the sender
      String reply;
      reply = "Welcome In DIYPROJECTSLAB.Com BOT\n" ;
      reply += "You can use below commands to operate:\n" ;
      reply += "============================\n\n" ;
      //reply += msg.sender.username;
      reply += ". Light  on = On\n";
      reply += ". Light  off = Off\n";
      myBot.sendMessage(msg, reply);
    }
  } 
}
