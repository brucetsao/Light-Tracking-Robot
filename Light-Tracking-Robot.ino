void setup() {
  // put your setup code here, to run once:
  pinMode(11, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(13, OUTPUT);

  pinMode(12, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(3, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int right = analogRead(5);
  int center = analogRead(4);
  int left = analogRead(3);
  Serial.print(right);
  Serial.print("\t");
  Serial.print(center);
  Serial.print("\t");
  Serial.println(left);
  if(center>100){
    analogWrite(11, 255);
    analogWrite(3, 255);
    Serial.println("center");
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
    digitalWrite(12, LOW);
    digitalWrite(13, LOW);
  }else if(right>100){
    Serial.println("right");
    analogWrite(11, 125);
    analogWrite(3, 255);
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
    digitalWrite(12, HIGH);
    digitalWrite(13, LOW);
  }else if(left>100){
    Serial.println("left");
    analogWrite(11, 255);
    analogWrite(3, 125);
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
    digitalWrite(12, LOW);
    digitalWrite(13, HIGH);
  }
  if(right < 100 and center < 100 and left < 100){
    digitalWrite(8, HIGH);
    digitalWrite(9, HIGH);
  }
}
