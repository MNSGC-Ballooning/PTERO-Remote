//basic blink functions for use as an indicator as desired 
void Blink(){ 
  for(int i = 0; i < 30; i++){ 
    digitalWrite(LED_BUILTIN, HIGH); 
    delay(50); 
    digitalWrite(LED_BUILTIN, LOW);
    delay(50);  
  }

  
}
