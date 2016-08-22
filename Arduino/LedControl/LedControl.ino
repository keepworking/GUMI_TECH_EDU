void setup() {
  Serial.begin(9600);
  pinMode(13,OUTPUT);
}

void loop() {
  if(Serial.available() > 0){
    char read = Serial.read();
    if(read == 'A'){
      digitalWrite(13,HIGH);
    }
    if(read == 'B'){
      digitalWrite(13,LOW);
    }
  }
}
