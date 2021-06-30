//functions that operate the buttons on board and all of thier functionalities 

bool buttonPress = false;
bool buttonPress1 = false;
bool buttonPress2 = false;

void button() {

  if (count.toInt() >= 100) {

    count = "00";
  }

  if (digitalRead(Button1) == HIGH && buttonPress == false) {
    if (count.toInt() < 90) {
      count = String(count.toInt() + 10);
    }
    else {
      count = "0" + String(filename[7]) ;
    }
    filename[6] = count.charAt(0);
    filename[7] = count.charAt(1);
    updateOled("File      Select:   " + String(filename));

    buttonPress = true;
  }
  else if (digitalRead(Button1) == LOW && buttonPress == true) {
    buttonPress = false;
    delay(100);
  }

  else if (digitalRead(Button2) == HIGH && buttonPress1 == false) {
    if (count.toInt() < 9) {
      count = "0" + String(count.toInt() + 1);
    }
    else {
      count = String(count.toInt() + 1);
    }
    filename[6] = count.charAt(0);
    filename[7] = count.charAt(1);
    updateOled("File      Select:   " + String(filename));

    buttonPress1 = true;
  }
  else if (digitalRead(Button2) == LOW && buttonPress1 == true) {
    buttonPress1 = false;
    delay(100);
  }

  else if (digitalRead(Button2) == HIGH && digitalRead(Button1) == HIGH && buttonPress2 == false) {
    String sender = "NAME";
    xBee_ser.print(sender);
    buttonPress2 = true;
    updateOled("File Name Requested!");
    delay(200);
    digitalWrite(LED_BUILTIN, HIGH);
    boolName = true;
    delay(100);
  }
  else if (digitalRead(Button2) == HIGH && digitalRead(Button1) == LOW && buttonPress2 == true) {
    buttonPress2 = false;
  }
}
