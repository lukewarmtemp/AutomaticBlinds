bool firstTime = false;
bool startRot = false;
bool stopRot = false;
int counter = 0;

void setup() {
  pinMode(9, OUTPUT);
  Serial.begin(9600);
  pinMode(11, OUTPUT);
  digitalWrite(11, LOW);
}

void loop() {
  int reading  = analogRead(0);
  Serial.println(reading);
  if (reading > 650 && firstTime == false){
      startRot = true;
      firstTime = true;
  }
  if (startRot == true && counter <= 15){  
    digitalWrite(9, HIGH);
    counter++;
  }
  if (counter == 15){
    stopRot = true;
  }
  if (stopRot == true){
    digitalWrite(9, LOW);
  }
  delay(200);
}
