//function to toggle siren via radio on PTERODACYL
void SirenSwitch() {
  IDb = digitalRead(SwitchID);

  if ( read == false && IDb == 0) {
    String sender = ID + "!SIRENOFF";
    xBee_ser.print(sender);
    updateOled(sender);
    Serial.println(sender);
    read = true;
  }


  else if ( read == true && IDb == 1) {
    String sender = ID + "!SIRENON";
    xBee_ser.print(sender);
    updateOled(sender);
    read = false;
  }

}
