#include <ESP8266WiFi.h>
#include <WiFiUdp.h>

const char* ssid = "iPhone (Timo)";
const char* password = "uaxsgda4m92d5";

WiFiUDP Udp;
unsigned int localUdpPort = 4210;  // local port to listen on
char incomingPacket[255];  // buffer for incoming packets
char  replyPacket[] = "Hi there! Switching Tree30 status! Enjoy! :-)";  // a reply string to send back

boolean messageReceived = false;

void setup()
{
  Serial.begin(115200);
  Serial.println();
  pinMode(2, OUTPUT);

  Serial.printf("Connecting to %s ", ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println(" connected");

  Udp.begin(localUdpPort);
  Serial.printf("Now listening at IP %s, UDP port %d\n", WiFi.localIP().toString().c_str(), localUdpPort);
}


void loop()
{
  int packetSize = Udp.parsePacket();
  if (packetSize)
  {
    // receive incoming UDP packets
    Serial.printf("Received %d bytes from %s, port %d\n", packetSize, Udp.remoteIP().toString().c_str(), Udp.remotePort());
    int len = Udp.read(incomingPacket, 255);
    if (len > 0)
    {
      incomingPacket[len] = 0;
  //    digitalWrite(2, HIGH);
      messageReceived = true;
    }
    Serial.printf("UDP packet contents: %s\n", incomingPacket);
    // send back a reply, to the IP address and port we got the packet from
    Udp.beginPacket(Udp.remoteIP(), Udp.remotePort());
    Udp.write(replyPacket);
    Udp.endPacket();
    delay(1000);
    if(messageReceived) digitalWrite(2, HIGH);
    else digitalWrite(2,LOW);
  }
}

