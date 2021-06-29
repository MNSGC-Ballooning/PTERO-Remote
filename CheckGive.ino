//function to check if the give swtich is toggled for reception of data and to send the command to the PTERODACTYL 
void CheckGive() {
  SET = digitalRead(SwitchGive);
  if ( sendCheck == false && SET == 0) {

    if (sendCheck == false) {
      SDSetup();
    }
    digitalWrite(LED_BUILTIN, HIGH);
    dataPull = true;
    String sender = ID + "!GIVE" + String(filename);
    xBee_ser.print(sender);
    Serial.println(sender);
    sendCheck = true;
  }
  else if ( sendCheck == true && SET == 1) {
    sendCheck = false;
    digitalWrite(LED_BUILTIN, LOW);
    dataPull = false;
  }

}
