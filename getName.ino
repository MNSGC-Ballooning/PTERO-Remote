//function to get name of file currently being logged to on PTERODACYL
void getName() {
  while (xBee_ser.available() > 0) {
    nameHold = xBee.readStringUntil('X');
    
    if (nameHold.length() == 12) {
      for (int i = 0; i < 11; i++) {
        filename[i] = nameHold.charAt(i);
      }
      boolName = false;
      digitalWrite(LED_BUILTIN, LOW); 
      updateOled("Current   PTERODACYLFile:     " + String(filename)); 
    }
  }



}
