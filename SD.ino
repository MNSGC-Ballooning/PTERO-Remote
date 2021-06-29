//function to set up and write to SD card on the reciving unit

void SDSetup() { //sets up SD card and names it
  String header = "Year, Month, Day, Hour, Minute, Second, Lat, Lon, Alt(ft), AltEst(ft), intT(F), extT(F), batTemp(F), msTemp(F), analogPress(PSI), msPressure(PSI), time since bootup (sec), Recent Radio Traffic, magnetometer x, magnetometer y, magnetometer z, accelerometer x, accelerometer y, accelerometer z, gyroscope x, gyroscope y, gyroscope z";
  pinMode(chipSelect, OUTPUT);
  if (!SD.begin(chipSelect)) {
    updateOled("TURN OFF  AND INSERTSD        CARD!");
    Blink();
    delay(1000);
  }

  else {
    datalog = SD.open(filename, FILE_WRITE);
    sdActive = true;
    updateSD(header);
    updateOled("Logging to: " +  String(filename)); 
    digitalWrite(LED_BUILTIN, HIGH);
    delay(500);
    digitalWrite(LED_BUILTIN, LOW);

  }
  if (!sdActive) {
    Blink();
    delay(1000);
  }
}



void updateSD(String pass) { //function to write to SD card
  datalog = SD.open(filename, FILE_WRITE);
  datalog.print(pass);
  datalog.close();
  dataLogs++;
}
