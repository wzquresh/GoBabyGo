int pin = 3;
double high_time = 1.2;
double period = 20;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(pin, OUTPUT);
//  Serial.println("TEST SERIES");
//  Serial.println("127");
//  analogWrite(pin, 127);
//  delay(5000);
//  Serial.println("191");
//  analogWrite(pin, 191);
//  delay(5000);
//  Serial.println("255");
//  analogWrite(pin, 255);
//  delay(5000);
//  Serial.println("0");
//  analogWrite(pin, 0);
//  delay(5000);
//  Serial.println("64");
//  analogWrite(pin, 64);
//  delay(5000);
//  Serial.println("127");
//  analogWrite(pin, 127);
//  delay(5000);
}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i = 181; i > 124; i--){
    Serial.print("GOING: "); Serial.println(i);
    analogWrite(pin, i);
    delay(300);
  }
  for(int i = 124; i < 181; i++){
    Serial.print("STOPPING: "); Serial.println(i);
    analogWrite(pin, i);
    delay(300);
  }

  for(int i = 181; i < 255; i++){
    Serial.print("REVERSING: "); Serial.println(i);
    analogWrite(pin, i);
    delay(300);
  }
  for(int i = 254; i > 181; i--){
    Serial.print("STOPPING: "); Serial.println(i);
    analogWrite(pin, i);
    delay(300);
  }
//  digitalWrite(pin, HIGH);
//  delay(high_time);
//  digitalWrite(pin, LOW);
//  delay(period - high_time);


}
