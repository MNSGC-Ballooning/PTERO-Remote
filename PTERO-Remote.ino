/* Witten By : Ben Stevens 06/19/2021
   Reciver unit has the ability to do a varitey of tasks for use with the PTERODACTYL unit.
   1) Left swtich sends command to recive data from a PTERODACTYL
   2) Right switch can be one of two modes: siren switch, or ID switch (see notes to see how to switch modes)
   3) Buttons can be used to change file name for direct file requesting for download. Top switch changes file name by 10, bottom by 1
   4) Pushing both buttons at the same time will send a request for the name of the current file being logged to by the PTERODACTYL


    Notes about mode switching:
    To switch Modes, change lines, instructions are commented on those lines
    44,68,69,75,76

*/

#include <SoftwareSerial.h>
#include <RelayXBee.h>
#include <SD.h>
#define xBee_ser Serial1  //Pins to communicate with xBee
#define SwitchGive 2
#define SwitchID 3
#define Button1 4
#define Button2 5
//SD Variables
#define chipSelect BUILTIN_SDCARD                       // Using built in chipselect on Teensy 3.5
File datalog;                                           // File object to be opened, written to, and closed

bool sdActive = false;                                  // Boolean to check if there are any available filenames left to be used
int dataLogs = 0;

//Reciver Varibles
const byte numChars = 200;
char receivedChars[numChars];
boolean newData = false;
//ID Name
String ID = "UMM0";
//Function varibles
boolean dataPull = false;
RelayXBee xBee = RelayXBee(&xBee_ser, ID);
void buttonRead();
const int ButtonPin = 6;
int buttonState = 0;
String dataPass;
bool SET = 1;
bool IDb = 1;
bool sendCheck = false;
int track = 0;
String count = "00";
bool read = false; //*** change to "true" when ID capability is active, "false" when Siren switch is on
bool off = true;
bool starter = false;
String nameHold;
bool boolName = false;

//OLED Varibles
#define PIN_RESET 9
#define DC_JUMPER 1


//NAME command varibles
char filename[] = "SDCARD00.csv";


void setup() {
 SetupSequence();
}

void loop() {
  
  button();
  ReadSerial();
  CheckGive();
  //CheckID(); //*** unncomment for ID capability
  SirenSwitch(); //***comment when "CheckID()" is uncommented
  
  if (boolName == true) {
    getName();
  }

  else if (dataPull == false) {
    
    while (xBee_ser.available() > 0) {
      Serial.write(xBee_ser.read());
    }
  }
  
  else {
    updateData();
  }
}

void SetupSequence() {
  pinMode(Button1, INPUT);
  pinMode(Button2, INPUT);
  oledSetup();
  pinMode(SwitchGive, INPUT_PULLUP);
  pinMode(SwitchID, INPUT_PULLUP);
  pinMode(LED_BUILTIN, OUTPUT);
  //SDSetup();
  char xbeeChannel = 'A';
  xBee_ser.begin(9600);
  xBee.init(xbeeChannel); // Need to make sure xbees on both ends have the same identifier. "AAAA"
  xBee.enterATmode();       //Configure XBee as a relay
  xBee.atCommand("ATDL1");
  xBee.atCommand("ATMY0");
  xBee.exitATmode();
  Serial.begin(9600);                 //Open the Serial line to the computer
  updateOled("Relay Mode active");
  delay(500);
  //updateOled("Select an ID,                 default ID = UMN0"); //uncomment when ID capability active
  updateOled("Unit      Active!             LS = RadioRS = Siren"); //uncomment when Siren Mode active
}
