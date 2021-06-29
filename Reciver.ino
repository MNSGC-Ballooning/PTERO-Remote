/* NOTE: This whole proess of using a starting and terminating character
    to send a string seems stupid and over complex for a simple task,
    but my Arduino IDE serial was being dumb
    and this was the only work around at the time.


*/

void ReadSerial() { //function to pass bytes in, make into chars, and put into a char array
  static boolean recvInProgress = false; //keep track of if data is incoming
  static byte indx = 0;
  char startMarker = '<';
  char endMarker = '>';
  //int splitter = 1;
  char rc;
  String parseOne;
  String parseTwo;
  String writer;

  while (Serial.available() > 0) {
    rc = Serial.read();
    if (recvInProgress == true) { //logic for normal data
      if (rc != endMarker) {
        receivedChars[indx] = rc;
        indx++;
        if (indx >= numChars) {
          indx = numChars - 1;
        }
      }
      else {

        // for writing serial input into the xbee
        receivedChars[indx] = '\0'; // terminate the string
        xBee_ser.write(receivedChars);
        recvInProgress = false;
        indx = 0;
        newData = true;
        if ( String(receivedChars).substring(5) = "NAME") {
          digitalWrite(LED_BUILTIN, HIGH);
          boolName = true;
        }

      }
    }

    else if (rc == startMarker) {
      recvInProgress = true;
    }

  }
}

void showNewData() {
  if (newData == true) {
    Serial.println(receivedChars);
    newData = false;
  }
}

void updateData() {

  if (starter == false)
    dataPass = xBee.readStringUntil('X');

  if (dataPass.startsWith("START")) {
    updateOled("Signal    Found               Receiving ...");
    starter = true;
  }
  else if (dataPass.startsWith("FAIL")) {
    updateOled("Failed to open, or  file DNE!");
  }



  if (starter == true && SET == 0) {
    while (xBee_ser.available() > 0) {

      dataPass = xBee.readStringUntil('X');


      if (dataPass.startsWith("END")) {
        updateOled("Data      Recived!");
        dataPull = false;
        digitalWrite(LED_BUILTIN, LOW);
        return;
      }
      else {
        updateSD(dataPass);
      }
    }
  }


  /*
    if (starter == false) {
      for (int i = 0; i < 10; i++) {
        dataPass = xBee.readStringUntil('X');
        if (dataPass.startsWith("START")) {
          updateOled("Reciving..");
          starter = true;
          break;
        }
        else if (i == 9){
          updateOled("Signal not found, try again");
          break;
        }
        else {
          updateOled("Searching for radio signal");
        }
        delay(1000);
      }
  */
}
