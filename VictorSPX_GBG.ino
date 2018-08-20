//Go Baby Go Project
//This code sends PWM outputs to the 
//Victor SPX controller, in response to 
//a button press. It gradually increases
//in speed until the button is released,
//then it gradually decreases in speed.

//Console Pins:
//These pins are for the main console,
//they do not operate in the original way,
//instead they remain on as long as the 
//arduino is plugged in. This may be 
//adjusted at a later day if necessary.
const int black = 13;
const int blue = 10;
const int yellow = 9;
const int red = 8;
const int orange = 7;


const int motorPin = 3;
const int buttonPin = 4;
const int killSwitch = 5;

const int power = 12;
const int ground = 11;

int motorSpeed;
int prevSpeed;

bool goState = 0;
bool killState = 0; 

void setup() {
  Serial.begin(9600);

  //Console Pins
  pinMode(black, OUTPUT);
  pinMode(blue, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(red, OUTPUT);
  pinMode(orange, OUTPUT);

  digitalWrite(black, LOW);
  digitalWrite(blue, HIGH);
  digitalWrite(yellow, HIGH);
  //Blue Power Button
  digitalWrite(red, HIGH);
  digitalWrite(orange, LOW);

  //Motor Pins
  pinMode(power, OUTPUT);
  pinMode(ground, OUTPUT);
  
  pinMode(motorPin, OUTPUT);
  pinMode(killSwitch, INPUT);
  pinMode(buttonPin, INPUT);

  digitalWrite(power, HIGH);
  digitalWrite(ground, LOW);

  prevSpeed = 181; //initialize previous speed
}

void loop() {
 
  killState = digitalRead(killSwitch);
  goState = digitalRead(buttonPin);
  Serial.print("Kill State: "); Serial.println(killState);
  Serial.print("Go State: "); Serial.println(goState);

  if (killState == 1){
    if(goState == 0 && motorSpeed != 255){  //Going State
      //motorSpeed = prevSpeed starts with previously stored speed for gradual speed up
      for(motorSpeed = prevSpeed; motorSpeed < 255; motorSpeed++){
        goState = digitalRead(buttonPin);
        if(goState == 1){
          prevSpeed = motorSpeed;  //store previous speed
          break;
        }
        analogWrite(motorPin, motorSpeed);
        //This delay may be adjusted as appropriate.
        delay(100);
        Serial.println("GOING");
      }
    }
    
    
    if(goState == 1 && motorSpeed > 181 && motorSpeed <= 255){  //Stopping State
      //motorSpeed = prevSpeed;  //Start with previously stored speed for gradual decrease
      for(motorSpeed; motorSpeed > 181; motorSpeed--){
        goState = digitalRead(buttonPin);
        if(goState == 0){
          prevSpeed = motorSpeed;  //store previous speed
          break;
        }
        analogWrite(motorPin, motorSpeed);
        //This delay may be adjusted as appropriate.
        delay(100);
        Serial.println("STOPPING");
      }
    }
    if (goState==1 && motorSpeed == 181){
      prevSpeed = 0;  //reset previous speed when we reach zero
      analogWrite(motorPin, 0);  
    }
  }

}
