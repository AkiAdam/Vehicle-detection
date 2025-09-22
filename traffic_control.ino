#include <WiFi.h>




const char *ssid = "gestbot";
const char *password = "gest1234";
String url1;
int x;
const char* host = "192.168.4.1";


// Define LED pin
const int r1 = 15;
const int g1 = 14;
const int ye1 = 4;


const int r2 = 5;
const int g2 = 18;
const int y2 = 19;


const int r3 = 21;
const int g3 = 22;
const int y3 = 23;


const int r4 = 12;
const int g4 = 32;
const int y4 = 33;


const int r5 = 25;
const int g5 = 26;
const int y5 = 27;
#define BUTTON_PIN 13


void setup() {




  Serial.begin(9600);


  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);


  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);


  WiFi.begin(ssid, password);


  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }


  digitalWrite(LED_BUILTIN, HIGH);
  delay(500);
  digitalWrite(LED_BUILTIN, LOW);
  delay(100);
  digitalWrite(LED_BUILTIN, HIGH);
  delay(500);
  digitalWrite(LED_BUILTIN, LOW);


   
  pinMode(r1, OUTPUT);
  pinMode(g1, OUTPUT);
  pinMode(ye1, OUTPUT);
  pinMode(r2, OUTPUT);
  pinMode(g2, OUTPUT);
  pinMode(y2, OUTPUT);
  pinMode(r3, OUTPUT);
  pinMode(g3, OUTPUT);
  pinMode(y3, OUTPUT);
  pinMode(r4, OUTPUT);
  pinMode(g4, OUTPUT);
  pinMode(y4, OUTPUT);
  pinMode(r5, OUTPUT);
  pinMode(g5, OUTPUT);
  pinMode(y5, OUTPUT);
  digitalWrite(r1, LOW);
  digitalWrite(g1, LOW);
  digitalWrite(ye1, LOW);


  digitalWrite(r2, LOW);
  digitalWrite(g2, LOW);
  digitalWrite(y2, LOW);


  digitalWrite(r3, LOW);
  digitalWrite(g3, LOW);
  digitalWrite(y3, LOW);


  digitalWrite(r4, LOW);
  digitalWrite(g4, LOW);
  digitalWrite(y4, LOW);
 
  digitalWrite(r5, LOW);
  digitalWrite(g5, LOW);
  digitalWrite(y5, LOW);
}


void loop()
{


 if (Serial.available() > 0) {
    char receivedChar = Serial.read();
    if (receivedChar == '1') {
            url1 = "/move?dir=B";
      req(url1);
      digitalWrite(r1, LOW);
      digitalWrite(g1, HIGH);
      digitalWrite(ye1, HIGH);


      digitalWrite(r2, HIGH);
      digitalWrite(g2, LOW);
      digitalWrite(y2, LOW);


      digitalWrite(r3, HIGH);
      digitalWrite(g3, LOW);
      digitalWrite(y3, LOW);


      digitalWrite(r4, HIGH);
      digitalWrite(g4, LOW);
      digitalWrite(y4, LOW);
     
    } else if (receivedChar == '2') {
            url1 = "/move?dir=B";
      req(url1);
      digitalWrite(r1, HIGH);
      digitalWrite(g1, LOW);
      digitalWrite(ye1, LOW);


      digitalWrite(r2, LOW);
      digitalWrite(g2, HIGH);
      digitalWrite(y2, HIGH);


      digitalWrite(r3, HIGH);
      digitalWrite(g3, LOW);
      digitalWrite(y3, LOW);


      digitalWrite(r4, HIGH);
      digitalWrite(g4, LOW);
      digitalWrite(y4, LOW);
     
    } else if (receivedChar == '3') {
         url1 = "/move?dir=B";
      req(url1);
      digitalWrite(r1, HIGH);
      digitalWrite(g1, LOW);
      digitalWrite(ye1, LOW);


      digitalWrite(r2, HIGH);
      digitalWrite(g2, LOW);
      digitalWrite(y2, LOW);


      digitalWrite(r3, LOW);
      digitalWrite(g3, HIGH);
      digitalWrite(y3, HIGH);


      digitalWrite(r4, HIGH);
      digitalWrite(g4, LOW);
      digitalWrite(y4, LOW);
     
    }else if (receivedChar == '4') {
          url1 = "/move?dir=B";
      req(url1);
      digitalWrite(r1, HIGH);
      digitalWrite(g1, LOW);
      digitalWrite(ye1, LOW);


      digitalWrite(r2, HIGH);
      digitalWrite(g2, LOW);
      digitalWrite(y2, LOW);


      digitalWrite(r3, HIGH);
      digitalWrite(g3, LOW);
      digitalWrite(y3, LOW);


      digitalWrite(r4, LOW);
      digitalWrite(g4, HIGH);
      digitalWrite(y4, HIGH);
     
    }else if (receivedChar == '5') {


            url1 = "/move?dir=F" ;
      req(url1);
      digitalWrite(r1, HIGH);
      digitalWrite(g1, LOW);
      digitalWrite(ye1, LOW);


      digitalWrite(r2, LOW);
      digitalWrite(g2, HIGH);
      digitalWrite(y2, HIGH);


      digitalWrite(r3, HIGH);
      digitalWrite(g3, LOW);
      digitalWrite(y3, LOW);


      digitalWrite(r4, HIGH);
      digitalWrite(g4, LOW);
      digitalWrite(y4, LOW);


     // Serial.println('1');
     
    }else if (receivedChar == '6') {
            url1 = "/move?dir=B";
      req(url1);
     // Serial.println('0);
      digitalWrite(r1, HIGH);
      digitalWrite(g1, LOW);
      digitalWrite(ye1, LOW);


      digitalWrite(r2, LOW);
      digitalWrite(g2, HIGH);
      digitalWrite(y2, LOW);


      digitalWrite(r3, HIGH);
      digitalWrite(g3, LOW);
      digitalWrite(y3, LOW);


      digitalWrite(r4, HIGH);
      digitalWrite(g4, LOW);
      digitalWrite(y4, LOW);
     
    }
  }




//  if (Serial.available()>0)
//  {
//    x=Serial.read();
//    if (x=='1')
//    {
//      url1 = "/move?dir=F" ;
//      req(url1);
//    }
//    else if (x=='2')
//    {
//      url1 = "/move?dir=B";
//      req(url1);
//    }
//
//  delay(50);
//}
}
void req(String url)
{
  Serial.print("connecting to ");
  Serial.println(host);
  WiFiClient client;   //Use WiFiClient class to create TCP connections
  const int httpPort = 8080;
  if (!client.connect(host, httpPort)) {
    Serial.println("connection failed");
    return;
  }
  Serial.print("Requesting URL: ");
  Serial.println(url);


  digitalWrite(LED_BUILTIN, HIGH);
  delay(50);
  digitalWrite(LED_BUILTIN, LOW);


  // This will send the request to the server
  client.print(String("GET ") + url + " HTTP/1.1\r\n" +
               "Host: " + host + "\r\n" +
               "Connection: close\r\n\r\n");
  unsigned long timeout = millis();
  while (client.available() == 0)
  {
    if (millis() - timeout > 3000)
    {
      Serial.println(">>> Client Timeout !");
      client.stop();
      return;
    }
  }
  Serial.println("closing connection");
  client.stop();
  delay(10);
}


#include <WiFi.h>




const char *ssid = "gestbot";
const char *password = "gest1234";
String url1;
int x;
const char* host = "192.168.4.1";


// Define LED pin
const int r1 = 15;
const int g1 = 14;
const int ye1 = 4;


const int r2 = 5;
const int g2 = 18;
const int y2 = 19;


const int r3 = 21;
const int g3 = 22;
const int y3 = 23;


const int r4 = 12;
const int g4 = 32;
const int y4 = 33;


const int r5 = 25;
const int g5 = 26;
const int y5 = 27;
#define BUTTON_PIN 13


void setup() {




  Serial.begin(9600);


  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);


  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);


  WiFi.begin(ssid, password);


  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }






  digitalWrite(LED_BUILTIN, HIGH);
  delay(500);
  digitalWrite(LED_BUILTIN, LOW);
  delay(100);
  digitalWrite(LED_BUILTIN, HIGH);
  delay(500);
  digitalWrite(LED_BUILTIN, LOW);


   
  pinMode(r1, OUTPUT);
  pinMode(g1, OUTPUT);
  pinMode(ye1, OUTPUT);
  pinMode(r2, OUTPUT);
  pinMode(g2, OUTPUT);
  pinMode(y2, OUTPUT);
  pinMode(r3, OUTPUT);
  pinMode(g3, OUTPUT);
  pinMode(y3, OUTPUT);
  pinMode(r4, OUTPUT);
  pinMode(g4, OUTPUT);
  pinMode(y4, OUTPUT);
  pinMode(r5, OUTPUT);
  pinMode(g5, OUTPUT);
  pinMode(y5, OUTPUT);
  digitalWrite(r1, LOW);
  digitalWrite(g1, LOW);
  digitalWrite(ye1, LOW);


  digitalWrite(r2, LOW);
  digitalWrite(g2, LOW);
  digitalWrite(y2, LOW);


  digitalWrite(r3, LOW);
  digitalWrite(g3, LOW);
  digitalWrite(y3, LOW);


  digitalWrite(r4, LOW);
  digitalWrite(g4, LOW);
  digitalWrite(y4, LOW);
 
  digitalWrite(r5, LOW);
  digitalWrite(g5, LOW);
  digitalWrite(y5, LOW);
}


void loop()
{


 if (Serial.available() > 0) {
    char receivedChar = Serial.read();
    if (receivedChar == '1') {
            url1 = "/move?dir=B";
      req(url1);
      digitalWrite(r1, LOW);
      digitalWrite(g1, HIGH);
      digitalWrite(ye1, HIGH);


      digitalWrite(r2, HIGH);
      digitalWrite(g2, LOW);
      digitalWrite(y2, LOW);


      digitalWrite(r3, HIGH);
      digitalWrite(g3, LOW);
      digitalWrite(y3, LOW);


      digitalWrite(r4, HIGH);
      digitalWrite(g4, LOW);
      digitalWrite(y4, LOW);
     
    } else if (receivedChar == '2') {
            url1 = "/move?dir=B";
      req(url1);
      digitalWrite(r1, HIGH);
      digitalWrite(g1, LOW);
      digitalWrite(ye1, LOW);


      digitalWrite(r2, LOW);
      digitalWrite(g2, HIGH);
      digitalWrite(y2, HIGH);


      digitalWrite(r3, HIGH);
      digitalWrite(g3, LOW);
      digitalWrite(y3, LOW);


      digitalWrite(r4, HIGH);
      digitalWrite(g4, LOW);
      digitalWrite(y4, LOW);
     
    } else if (receivedChar == '3') {
         url1 = "/move?dir=B";
      req(url1);
      digitalWrite(r1, HIGH);
      digitalWrite(g1, LOW);
      digitalWrite(ye1, LOW);


      digitalWrite(r2, HIGH);
      digitalWrite(g2, LOW);
      digitalWrite(y2, LOW);


      digitalWrite(r3, LOW);
      digitalWrite(g3, HIGH);
      digitalWrite(y3, HIGH);


      digitalWrite(r4, HIGH);
      digitalWrite(g4, LOW);
      digitalWrite(y4, LOW);
     
    }else if (receivedChar == '4') {
          url1 = "/move?dir=B";
      req(url1);
      digitalWrite(r1, HIGH);
      digitalWrite(g1, LOW);
      digitalWrite(ye1, LOW);


      digitalWrite(r2, HIGH);
      digitalWrite(g2, LOW);
      digitalWrite(y2, LOW);


      digitalWrite(r3, HIGH);
      digitalWrite(g3, LOW);
      digitalWrite(y3, LOW);


      digitalWrite(r4, LOW);
      digitalWrite(g4, HIGH);
      digitalWrite(y4, HIGH);
     
    }else if (receivedChar == '5') {


            url1 = "/move?dir=F" ;
      req(url1);
      digitalWrite(r1, HIGH);
      digitalWrite(g1, LOW);
      digitalWrite(ye1, LOW);


      digitalWrite(r2, LOW);
      digitalWrite(g2, HIGH);
      digitalWrite(y2, HIGH);


      digitalWrite(r3, HIGH);
      digitalWrite(g3, LOW);
      digitalWrite(y3, LOW);


      digitalWrite(r4, HIGH);
      digitalWrite(g4, LOW);
      digitalWrite(y4, LOW);


     // Serial.println('1');
     
    }else if (receivedChar == '6') {
            url1 = "/move?dir=B";
      req(url1);
     // Serial.println('0);
      digitalWrite(r1, HIGH);
      digitalWrite(g1, LOW);
      digitalWrite(ye1, LOW);


      digitalWrite(r2, LOW);
      digitalWrite(g2, HIGH);
      digitalWrite(y2, LOW);


      digitalWrite(r3, HIGH);
      digitalWrite(g3, LOW);
      digitalWrite(y3, LOW);


      digitalWrite(r4, HIGH);
      digitalWrite(g4, LOW);
      digitalWrite(y4, LOW);
     
    }
  }
 


//  if (Serial.available()>0)
//  {
//    x=Serial.read();
//    if (x=='1')
//    {
//      url1 = "/move?dir=F" ;
//      req(url1);
//    }
//    else if (x=='2')
//    {
//      url1 = "/move?dir=B";
//      req(url1);
//    }
//
//  delay(50);
//}
}
void req(String url)
{
  Serial.print("connecting to ");
  Serial.println(host);
  WiFiClient client;   //Use WiFiClient class to create TCP connections
  const int httpPort = 8080;
  if (!client.connect(host, httpPort)) {
    Serial.println("connection failed");
    return;
  }
  Serial.print("Requesting URL: ");
  Serial.println(url);


  digitalWrite(LED_BUILTIN, HIGH);
  delay(50);
  digitalWrite(LED_BUILTIN, LOW);


  // This will send the request to the server
  client.print(String("GET ") + url + " HTTP/1.1\r\n" +
               "Host: " + host + "\r\n" +
               "Connection: close\r\n\r\n");
  unsigned long timeout = millis();
  while (client.available() == 0)
  {
    if (millis() - timeout > 3000)
    {
      Serial.println(">>> Client Timeout !");
      client.stop();
      return;
    }
  }
  Serial.println("closing connection");
  client.stop();
  delay(10);
}
