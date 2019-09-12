String incomingByte = "";

void setup() {

  Serial.begin(9600); // opens serial port, sets data rate to 9600 bps
  while(!Serial);
}

void loop() {

  if (Serial.available() > 0) {
  
  incomingByte = Serial.readString(); // read the incoming byte:
 
  
  Serial.println(incomingByte);
  
  }

}
