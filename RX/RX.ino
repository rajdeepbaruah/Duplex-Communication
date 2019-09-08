

//Rx


#include <SPI.h>    // ( Net surf for SPI pins )
#include <Ethernet.h>
#include <EthernetUdp.h>
#include<LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(8, 9, 5, 4, 3, 2);
//code start

int pinButton = 14;
int pinButton1= 15;

int stateLED,stateLED1 = LOW;
int stateButton,stateButton1;
int previous,previous1 = LOW;
long time = 0;
long debounce = 100;
int codeS1 = 2; //Codes must be even
int codeS2 = 4;






//Device IP & MAC (Variable)
byte mac[] = { 0x2A, 0x00, 0x22, 0x22, 0x22, 0x44 }; //(Naming rules)
IPAddress ip(192, 168, 1, 10);                       //(IP rules according to subnet/gateway)

// -------- Do not change the section below -----------------
const unsigned int localPort = 1369;    // Process ID port (TCP/UDP Alternate port = 8888)
char remote_IP1[]="192.168.1.20";
int remote_Port1 = 9631;
char UDP_TX_Buffer[80];
char recvdBuffer[UDP_TX_PACKET_MAX_SIZE + 1]; // Buffer for incoming data
EthernetUDP Udp;  //Class variable (Initiates process of UDP)
// ------------------------------------------------------------




int temperature =atoi(recvdBuffer);
int flamedet=0;

int threshold =400;






void setup()
{
 lcd.begin(16, 2);
 lcd.clear();
  lcd.print("Welcome");
  delay(500);
  lcd.setCursor(0, 1);
 lcd.clear();
 lcd.print("Manless Subtration");
 lcd.setCursor(0,2);
 lcd.print("Optical Fiber");
 delay(2000);
 //lcd.print(temperature);
  pinMode(6,OUTPUT);
  pinMode(pinButton, INPUT);
  pinMode(pinButton1,INPUT);
  pinMode(7,OUTPUT);
  Ethernet.begin(mac, ip);   // Set up the Ethernet Shield
  Udp.begin(localPort);      // Open a socket for this port
  Serial.begin(9600);        // Set up serial monitor with PC4
  delay(500);
}
char first;
int i = 0, flag = 0;
char text;



void loop()
{
 
  //transmit
int recvdSize = Udp.parsePacket();
int count,count1,flag1;
int Pressed = 0;
int incomingByte = 0;

 if (Udp.available()) {
    IPAddress remote = Udp.remoteIP();
    Udp.read(recvdBuffer, UDP_TX_PACKET_MAX_SIZE);
            // Gets rid of the message header
    
    Serial.println(recvdBuffer);


 }
}

