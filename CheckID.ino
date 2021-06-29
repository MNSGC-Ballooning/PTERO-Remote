//function that uses the siren switch to toggle IDs should this be enabled in the code 
void CheckID(){ 
 IDb = digitalRead(SwitchID);

if (IDb == 0){ 
  read = false;
}

if (IDb == 1){ 
  off = true;
}
 
if (track == 0 && IDb == 0 && read == false && off == true){ 
  ID = "UMN1"; 
  track = 1; 
  updateOled("ID = UMN1");
  read = true; 
  off = false;
}

else if (track == 1 && IDb == 0 && read == false && off == true){ 
  ID = "UMN2"; 
  track = 2; 
  updateOled("ID = UMN2");
  read = true; 
  off = false;
}

else if (track == 2 && IDb == 0 && read == false && off == true){ 
  ID = "UMN3"; 
  track = 3; 
  updateOled("ID = UMN3");
  read = true; 
  off = false;
}

else if (track == 3 && IDb == 0 && read == false && off == true){ 
  ID = "UMN4"; 
  track = 0; 
  updateOled("ID = UMN4");
  read = true; 
  off = false;
}


 
}
