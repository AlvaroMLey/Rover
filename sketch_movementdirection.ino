void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  // Defines the port 13 (orange led) as output
  pinMode(13,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("Hello Pi, This is Arduino UNO... ");
  if(Serial.available()){
    flash(Serial.parseInt());
    Serial.flush();
    }
    delay(1000);
}

void flash(int n){
  Serial.print("Movement:");
  Serial.println(n);
  
  Serial.print("1 = w");
  Serial.print("2 = s");
  Serial.print("3 = a");
  Serial.print("4 = d");

  switch (n) {
  case 1:
    Serial.print("Moving forward: n=1=w");
    Serial.print("Expected 2 flashes");
    for (int i=0 ; i<2 ; i++){
    digitalWrite(13,HIGH);
    delay(750);
    digitalWrite(13,LOW);
    delay(750);
    Serial.print("Flash number:");
    Serial.println(i+1);
    }
    break;
  case 2:
    Serial.print("Moving backwards: n=2=s");
    Serial.print("Expected 3 flashes");
    for (int i=0 ; i<3 ; i++){
    digitalWrite(13,HIGH);
    delay(750);
    digitalWrite(13,LOW);
    delay(750);
    Serial.print("Flash number:");
    Serial.println(i+1);
    }
    break;
  case 3:
    Serial.print("Moving left: n=3=a");
    Serial.print("Expected 5 fast flashes");
    for (int i=0 ; i<5 ; i++){
    digitalWrite(13,HIGH);
    delay(100);
    digitalWrite(13,LOW);
    delay(100);
    Serial.print("Flash number:");
    Serial.println(i+1);
    }
  
    break;

  case 4:
    Serial.print("Moving right: n=4=d");
    Serial.print("Expected 5 slow flashes");
    for (int i=0 ; i<5 ; i++){
    digitalWrite(13,HIGH);
    delay(750);
    digitalWrite(13,LOW);
    delay(750);
    Serial.print("Flash number:");
    Serial.println(i+1);
    }

  }
  Serial.println("Movement complete");
  }
  
