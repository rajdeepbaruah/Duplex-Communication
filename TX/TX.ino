
//Tx
 
 
#include <SPI.h>
#include <Ethernet.h>
#include <EthernetUdp.h>
 
//PIN on board
 
 
int pinButton = 4;
int pinButton1= 5;
int flame = 8;
int LED = 12;
int LED1 =13;
int stateLED,stateLED1,stateLED2 = LOW;
int stateButton,stateButton1,stateButton2;
int previous,previous1,previous2 = LOW;
long time = 0;
long debounce = 100;
 
 
 
//-------- system config -----------------
byte mac[] = {0x2A, 0x00, 0x22, 0x22, 0x22, 0x22};
IPAddress ip(192, 168, 1, 20);
const unsigned int localPort = 9631;
 
char remote_IP[] = "192.168.1.10";
int remote_Port = 1369;
 
char UDP_TX_Buffer[80]; // For future use...
 
char recvdBuffer[UDP_TX_PACKET_MAX_SIZE + 1];
//char UDP_RX_Buffer[80]; // For future use...
EthernetUDP Udp;
//-----------------------------------------
 
int analogPin = 3;
int firstpin=2;
int reading;
float tempC;
 
void setup()
{
 
  Ethernet.begin(mac, ip);  // Set up the Ethernet Shield
  Udp.begin(localPort);     // Open a socket for this port
  Serial.begin(9600);       // Set up serial monitor with PC
  //pinMode(13, OUTPUT);
 analogReference(INTERNAL);
 
pinMode(6,OUTPUT);
pinMode(7,OUTPUT);
pinMode(8,INPUT);
   pinMode(pinButton, INPUT);
   pinMode(pinButton1,INPUT);
  pinMode(LED, OUTPUT);
  pinMode(LED1,OUTPUT);
 
 
  delay(100);
 
 
}
 
int newS1, oldS1 = 0, newS2, oldS2 = 0, newS3, oldS3 = 0, newS4, oldS4 = 0;
 
int sData_code = 1;
int codeS1 = 2; //Codes must be even
int codeS2 = 4;
int codeS3 = 6;
int codeS4 = 8;
 
 
void loop()
{
int recvdSize = Udp.parsePacket();
 
reading = digitalRead(analogPin);
tempC = reading;
Serial.println(tempC);
delay(100);
 
 itoa(tempC, UDP_TX_Buffer, 10); 
 
   Udp.beginPacket(remote_IP, remote_Port);
 
   Udp.write(UDP_TX_Buffer);
 
   Udp.endPacket();
 
   strcpy(UDP_TX_Buffer,"");
 
   delay(200);
 
 
   
  if (Udp.available()) {
    IPAddress remote = Udp.remoteIP();
    Udp.read(recvdBuffer, UDP_TX_PACKET_MAX_SIZE);
    recvdBuffer[recvdSize] = '\0';
    recvdSize -= 8; 
 
 
    Serial.println(recvdBuffer);
  
 
  }
}
  
  
void remote_Send(int data)
{
  itoa(data, UDP_TX_Buffer, 10);
  Udp.beginPacket(remote_IP, remote_Port); // REMOTE IP/Port
  Udp.write(UDP_TX_Buffer);                         //Byte/string
  Udp.endPacket();
  delay(200);
}
 

