// 2-IN-1 CW KEYER by Anish VR (14-1-2023) vu3ave

// THIS IS : 2-IN-1 CW KEYER PROGRAME CODE //////////
// upload this code to ESP-12 ///
//
//
//
// FIRST UPLOAD - eeprom_clear.ino  /// run code // this will clear eeprom of ESP-12 ,from any previous data







//COMMENT - // 100% working script with ESP12 Wifi Module




// TWO inputs and ONE cw output

// Input 1 : Laptop/Mobile phone/tablet with wifi can act as keyboard Input of This telegraphic keyer (cw keyer)
// Input 2 : Normal paddle keyer as input, two digital input pins are given,   as DIT and DAH for normal paddle keyer ... Center point is GND ( Gound or negative of DC supply)

/*

=====================================================================

Ver-1.22

Date: 14 Jan 2023

WIFI CW KEYER by Anish VR 
Hamradio callsign: vu3ave
contact: vu3ave@gmail.com (Mobile phone : +91 9995957776 )
country: India

Uses ESP-12 OR ESP12-F  WIFI MODULE ( any ESP module will work )

ESP12-F WIFI MODULE BOARD PINS USED : ( DC supply 3.3Volt DC )
===================================
1. GPIO Pin 4 - To speaker , for side tone out of cw
2. GPIO Pin 5 - digital out of CW ( can connect to a relay to drive Transciver Rig)
3. GPIO Pin 2 - DIT connection to paddle key ( no need of pullup resistor)
4. GPIO Pin 0 - DAH connection to paddle key ( no need of pullup resistor)
5. ADC - ADC Pin , which the only one Analog Input Pin ( 0 to 1Volt input range voltage) - Connect center of potentiometer of WPM adjust potentiometr ( Maximum 1 Volt )



UPLOADING 'THIS' CODE PROCEDURE
===============================

STEP 1:
 First upload the EEPROM cleaning ino file (eeprom_clear.ino) and Run ESP12 , once. 
 This will clear fresh EEPROM MEMORY points of ESP12 module to all 0 default values

STEP 2:

 Now upload code (wifi-cw-keyer.ino) along with index.h 
 Once uploadedd, press restart the ESP12 Module
 

STEP 3:

 Module will Run in AP mode ( Access Point ) and create a Wifi Hotspot named "92.168.4.1"
 
 Using a laptop computer or Mobile Smart phoneLog in to that wifi network(no password needed) 
 
 Now , navigate to http://192.168.4.1 using your web browser
 
 Type in English using default keyboard and that will be converted 
 to Telegraphy messages ( via Pin 4)  and send as Tone as well as digital out (via Pin 5)




WIRING DETAILS FOR ESP12 TO MAKE IT CW KEYER
============================================



*/


// More details for another prorammer

//KEY_PIN  = pin 5 of ESP12 > cw out pin
// tonepin is pin 4 of ESP12 , this for tone out through external speaker
// EEPROM STORES  time_unit data - millisecond for DIT
// EEPROM also STORES  side tone frequency - hertz for Side tone for telegraphy , though speaker
// EEPROM also stores Typing speed data
// On first loading , ESP12 recalls these two data from eeprom to html page for dispaying pre-saved data
// 3 numbers of input fields to type in a set GO the text as CW



#include <EEPROM.h>
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include "index.h" //Our HTML webpage contents with javascripts

// EEPROM STORAGE variables
String data;
void writeString(char add,String data);
String read_String(char add);
String recivedData;

int count = 0;
int last_sent_location=0;
int messagetocw();

                   
int KEY_PIN=5; // relay drive to transimit cw in port of ESP8266
int sm_time;
int TIME_UNIT = 73; // default time for DIT
bool dxing_mode = true; // put false for normal mode


String  morsecode;
String message;
String dit_time;
String freq;
String typingspeed;


int present_message_length;

String present_message;

String my_mod ="pk";

 int tonepin = 4;
 int my_tone_frequency = 500;
 
 //lambic keyer
 int dit_pin = 2;
 int dah_pin = 0;
 
 int speed_pot_pin = A0;
 int speed_pot = 0;
 

const String  characters = "abcdefghijklmnopqrstuvwxyz1234567890?.,/-; ";
////////////////////////////// CW sender/////
String mappings[] = {
                     ".-",  // A
                     "-...",
                     "-.-.",  
                     "-..",
                     ".",  
                     "..-.",
                     "--.",  
                     "....",
                     "..",  
                     ".---",
                     "-.-",  
                     ".-..",
                     "--",  
                     "-.",
                     "---",  
                     ".--.",
                     "--.-",  
                     ".-.",
                     "...",  
                     "-",                      
                     "..-",  
                     "...-",
                     ".--",  
                     "-..-",
                     "-.--",  
                     "--..", // Z
                     ".----",  // 1
                     "..---",
                     "...--",  
                     "....-",
                     ".....",  
                     "-....",
                     "--...",  
                     "---..",
                     "----.",  
                     "-----",   // 0
                     "..--..",  // ?
                     ".-.-.-",  // .
                     "--..--",  // ,
                     "-..-.",   // /
                     "-...-",   // -   // spacing symbol
                     ".-.-." ,   // ;  //  "AR" symbol
                     ""
                      };

















//SSID and Password of your WiFi router
const char* ssid = "192.168.4.1";
const char* password = "";

ESP8266WebServer server(80); //Server on port 80



//===============================================================
// This routine is executed when you open its IP in browser
//===============================================================
void handleRoot() {
 String s = MAIN_page; //Read HTML contents on index.h 
 server.send(200, "text/html", s); //Send web page
}



void handleWPMTXT(){
   dit_time = server.arg("mytxt"); 
   Serial.println("received dit_time is :");
    Serial.println(dit_time);
     Serial.println("");
    server.send(200, "text/plane", dit_time);
// store eeprom to continue here...  
data = dit_time;
  Serial.print("Writing Data to address 0:");
  Serial.println(data);
//WRITING NEW WPM DATA (DIT TIME IN MILLISECOND) IN EEPROM
  writeString(0, data);  //Address 0 and String type data
  delay(10);

  TIME_UNIT = data.toInt(); // CONVERTING STRING TO INT and STORING IN TIME_UNIT (NEW WPM STORED )
}



void handleWPMBACK(){
  //////// DISPLAY STORED WPM IN HTML FILE
  recivedData = read_String(0);
  Serial.print("Read Data OF WPM FROM 0:");
  Serial.println(recivedData);
  delay(1000);
  server.send(200, "text/plane", recivedData);
}



void handleTONEBACK(){
  //////// DISPLAY STORED TONE FREQUENCY IN HTML FILE
  recivedData = read_String(10);
  Serial.print("Read Data OF WPM FROM 10:");
  Serial.println(recivedData);
  delay(1000);
  server.send(200, "text/plane", recivedData);
}


void handleSPEEDBACK(){
  //////// DISPLAY STORED TYPESPEED IN HTML SELECTION TOOL
  recivedData = read_String(20);
  Serial.print("Read Data OF WPM FROM 20:");
  Serial.println(recivedData);
  delay(1000);
  server.send(200, "text/plane", recivedData);
}








/////////////////------------

void handleTONETXT(){
   freq = server.arg("mytxt"); 
   Serial.println("received frequency  is :");
    Serial.println(freq );
     Serial.println("");
    server.send(200, "text/plane", freq);
// store eeprom to continue here...  
data = freq;
  Serial.print("Writing Data to address 10:");
  Serial.println(data);
//WRITING NEW SIDE TONE FREQUENCY DATA (FREQUENCY IN HERTZ) IN EEPROM
  writeString(10, data);  //Address 10 and String type data
  delay(10);

  my_tone_frequency = data.toInt(); // CONVERTING STRING TO INT and STORING IN my_tone_frequency (NEW frequency STORED )
}
//////////////////---------------




//-----------ave edit
void handleCWTXT(){
   message = server.arg("mytxt"); 
    Serial.println(message);
    server.send(200, "text/plane", message);


present_message += message; 
message="";  


//int result= messagetocw();

     
}
//-----------ave edit

void handleSPEEDTXT(){
   typingspeed = server.arg("mytxt"); 
   Serial.println("received typing speed  is :");
    Serial.println(typingspeed);
     Serial.println("");
    server.send(200, "text/plane", typingspeed);
// store eeprom to continue here...  
data = typingspeed;
  Serial.print("Writing Data to address 20:");
  Serial.println(data);
//WRITING NEW TYPINGSPEED DATA  (EXAMPLE: 10) IN EEPROM
  writeString(20, data);  //Address 20 and String type data
  delay(10);

     
}
//-----------ave edit





//==============================================================
//                  SETUP
//==============================================================
void setup(void){

  pinMode(KEY_PIN, OUTPUT);
  pinMode(tonepin, OUTPUT);
  pinMode(dit_pin, INPUT_PULLUP);
  pinMode(dah_pin, INPUT_PULLUP);


  Serial.begin(115200);
  EEPROM.begin(512);
  WiFi.softAP(ssid, password);

  IPAddress myIP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(myIP);



 
  server.on("/", handleRoot);      //Which routine to handle at root location. This is display page
  server.on("/cwtxt", handleCWTXT);
  server.on("/wpmtxt", handleWPMTXT);
  server.on("/tonetxt", handleTONETXT);
   server.on("/speedtxt", handleSPEEDTXT);

   
  server.on("/wpmback", handleWPMBACK);
  server.on("/toneback", handleTONEBACK);
  server.on("/speedback", handleSPEEDBACK);


  
 

  server.begin();                  //Start server
  Serial.println("");
  Serial.println("HTTP server started");


  Serial.print("EEPROM length: ");
  Serial.println(EEPROM.length());





// FOR FIRST RUN >> WPM VALUE FROM EEPROM TO RUNNING PROGRAMME
// reading eeprom value of TIME_UNIT from address 0, to store in TIME_UNIT

  recivedData = read_String(0);
  Serial.print("Read Data from address 0 : ");
  Serial.println(recivedData);
  delay(1000);
if(recivedData.length() >=1){
  TIME_UNIT = recivedData.toInt(); // CONVERTING STRING TO INT and STORING IN TIME_UNIT (NEW WPM STORED )
}else{

  TIME_UNIT = 100;
}
// reading eeprom value of TIME_UNIT from address 0, to store in TIME_UNIT





// FOR FIRST RUN >> FREQUENCY VALUE FROM EEPROM TO RUNNING PROGRAMME
// reading eeprom value of my_tone_frequency from address 10, to store in my_tone_frequency

  recivedData = read_String(10);
  Serial.print("Read Data from address 10 : ");
  Serial.println(recivedData);
  delay(1000);
if(recivedData.length() >=1){
  my_tone_frequency = recivedData.toInt(); // CONVERTING STRING TO INT and STORING IN my_tone_frequency (NEW SIDE TONE FREQUENCY STORED )
}else {

  my_tone_frequency = 1000;
}
// reading eeprom value of TIME_UNIT from address 0, to store in TIME_UNIT







// FOR FIRST RUN >>TYPINGSPEED FROM EEPROM 
// reading eeprom value  from address 20
  recivedData = read_String(20);
  Serial.print("Read Data from address 20 : ");
  Serial.println(recivedData);
  delay(1000);





  
}
//==============================================================
//                     LOOP
//==============================================================
void loop(void){

// First checking for mode change is needed
speed_pot = (map(analogRead(speed_pot_pin), 0, 670, 30, 200));
if(!digitalRead(dah_pin) && !digitalRead(dit_pin) && speed_pot >= 180) { my_mod="pk"; Serial.println("Mode Changed to : Paddle Keyer"); }
if(!digitalRead(dah_pin) && !digitalRead(dit_pin) && speed_pot < 35)  { my_mod="kk"; Serial.println("Mode Changed to : Keyboard Keyer"); }
////////////////////
 


  

//////////////////////////////////////
  if(my_mod =="kk"){
    // in mode kk (keyboard keyer)

  int result= messagetocw(); // WHOLE STRING sending string as cw
  server.handleClient();          //Handle client requests
  
  }

/////////////////////////////////////






////////////////////////////////////
  if(my_mod =="pk"){

// in mode pk (paddle keyer)
//Paddle keyer code


 if(!digitalRead(dit_pin))        // If the dot lever is presssed..
     {
  //  keyAndBeep(speed_pot);           // ... send a dot at the given speed
  // delay(speed_pot / 3);                //     and wait before sending next

  digitalWrite(KEY_PIN, HIGH);            // Key down
  tone(tonepin, my_tone_frequency);
  delay(speed_pot);
  noTone(tonepin);
  digitalWrite(KEY_PIN, LOW);             // Key up
  
   delay(speed_pot);
   
Serial.println(speed_pot);
Serial.println(my_mod);

     }


  
if(!digitalRead(dah_pin))       // If the dash lever is pressed...
    {
//   keyAndBeep(speed_pot*3);         // ... send a dash at the given speed
// delay(speed_pot / 3);                   //     and wait before sending next
digitalWrite(KEY_PIN, HIGH);            // Key down
  tone(tonepin, my_tone_frequency);
  delay(speed_pot*3);
  noTone(tonepin);
  digitalWrite(KEY_PIN, LOW);             // Key up
   
  delay(speed_pot);

    }

  }
////////////////////////////

  

} //loop()











int messagetocw()
{  
  // FUNCTION messagetocw() START
 
  // int size = strlen(message);
  
 present_message_length = present_message.length(); 







if(last_sent_location > present_message_length) 
{
  last_sent_location = present_message_length;
}














  
 // int TIME_UNIT = 50; // default time for DIT


 // const int DOT = TIME_UNIT;
 // const int DASH = 3 * TIME_UNIT;
 // const int SYMBOL_SPACE = TIME_UNIT;
  //const int LETTER_SPACE = 3 * TIME_UNIT - SYMBOL_SPACE;
 // const int WORD_SPACE = 7 * TIME_UNIT - LETTER_SPACE;




  const int DOT = TIME_UNIT;
  const int DASH = 3 * TIME_UNIT;


int ss;
int ls;
int ws;
if(dxing_mode)
{
 
ss=DOT;
ls=0.2 * DOT;
ws=1 * DOT;
}
else
{


 ss=DOT;
ls=2 * DOT;
ws=5 * DOT;
}
 
  const int SYMBOL_SPACE = ss;
  const int LETTER_SPACE = ls;
  const int WORD_SPACE = ws;






  
 
 present_message.toLowerCase();
 // for (int i = 0; i < size; i++) {
    
        // const char* ch = strchr(characters, tolower(message[i]));
        char ch = characters.charAt(characters.indexOf(present_message.charAt(last_sent_location)));//
        // if (ch != NULL){
   if (ch != '\0'){
          
          // int position = ch-characters;
          int position = characters.indexOf(present_message.charAt(last_sent_location));




last_sent_location=last_sent_location+1;


          
          
          morsecode = mappings[position];
          
          // int count = strlen(morsecode);
         int count = morsecode.length();
          


          
          
          for( int j=0; j< count; j++)
          {
            
            char symbol = morsecode[j];
            
            if(symbol =='.')
            {
              sm_time = DOT;
            }
            
            if(symbol =='-')
            {
              sm_time = DASH;
            }
            digitalWrite(KEY_PIN, HIGH);


        tone(tonepin, my_tone_frequency);
        
        






            
            delay(sm_time);
            digitalWrite(KEY_PIN, LOW);
            noTone(tonepin);
            delay(SYMBOL_SPACE);
          }// for loop close2
          
          delay(LETTER_SPACE);
          
        }
        delay(WORD_SPACE);
    
 // }// for loop close1


  return 0;
 
} // FUNCTION messagetocw() close



//////// EEPROM WRITE / READ FUNCTIONS ///////////
void writeString(char add,String data)
{
  int _size = data.length();
  int i;
  for(i=0;i<_size;i++)
  {
    EEPROM.write(add+i,data[i]);
  }
  EEPROM.write(add+_size,'\0');   //Add termination null character for String Data
  EEPROM.commit();
}


String read_String(char add)
{
  int i;
  char data[100]; //Max 100 Bytes
  int len=0;
  unsigned char k;
  k=EEPROM.read(add);
  while(k != '\0' && len<500)   //Read until null character
  {    
    k=EEPROM.read(add+len);
    data[len]=k;
    len++;
  }
  data[len]='\0';
  return String(data);
}
//////// EEPROM WRITE / READ FUNCTIONS ///////////







// Key the transmitter  // lambic keyer
void keyAndBeep(int speed)
{
  digitalWrite(KEY_PIN, HIGH);            // Key down
  tone(tonepin, my_tone_frequency);
   delay(speed);
   noTone(tonepin);
   digitalWrite(KEY_PIN, LOW);             // Key up
 }
