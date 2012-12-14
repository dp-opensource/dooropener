#include <stdio.h>
#include <string.h>
#include <SPI.h>
#include <Ethernet.h>
#include <WebServer.h>

byte mac[] = { 0x90, 0xA2, 0xDA, 0x0D, 0x64, 0x40 };
byte ip[] = { 10,0,0,64 };
IPAddress myDns( 8,8,8,8 );
byte rip[] = { 0,0,0,0 };

EthernetServer server(80);

char hubotserver[] = "hubot.dpdev.de";
EthernetClient hubotclient;

void setup() {
  Ethernet.begin(mac, ip, myDns);
  server.begin();
  pinMode(8, OUTPUT);
  digitalWrite(8, LOW);
}

void loop() {
  String expectedRequest = "GET /letmein.html HTTP/1.1";
  String request = "";
  String header = "";
  String clientip = "";
  
  EthernetClient client = server.available();
  
  if(client) {
    while(client.connected()) {
      if(client.available()) {
        char c = client.read();
        if (c != '\n') {
          request.concat(c);
        } else {
          break;
        }
      }
    }
      
    client.println("HTTP/1.1 200 OK");
    client.println("Content-Type: text/html");
    client.println("Access-Control-Allow-Origin: *");
    client.println();
    
    if(request.startsWith(expectedRequest)) {
      digitalWrite(8, HIGH);
      delay(500);
      digitalWrite(8, LOW);
      client.getRemoteIP(rip);
      clientip = String(rip[0]) + "." + String(rip[1]) + "." + String(rip[2]) + "." + String(rip[3]);
      client.println("<!DOCTYPE html><html><head><meta charset='UTF-8' /><title>Türöffner</title><meta name='viewport' content='width=device-width, maximum-scale=1.0'><meta name='apple-mobile-web-app-capable' content='yes' /></head><body><h1>Die Tür ist offen</h1>");
      //client.println("<pre>" + clientip + "</pre>");
      client.println("<script>var reload = function(evt) {location.reload();};document.body.addEventListener('click', reload);document.body.addEventListener('touchend', reload);document.body.addEventListener('touchmove', function(evt) {evt.preventDefault();});</script></body></html>");

      hubotclient.connect(hubotserver, 5555);
      hubotclient.println("GET /hubot/doorbell?room=&ip=" + clientip + " HTTP/1.1");
      hubotclient.println(strcat("Host: ", hubotserver));
      hubotclient.println("User-Agent: door-opener");
      hubotclient.println("Connection: close");
      hubotclient.println();
      hubotclient.stop();
    } else {
      client.println("<h1>Go away!</h1>");
    }
  }
  delay(1);
  client.stop();
}
