//test code for running motor speed
int VinL = 0;
int VinR = 0;
int relay = 0;
int rrelay = 0;
void setup() {
  // put your setup code here, to run once:
  pinMode(A2, INPUT);  //defines inputs for each sensor
  pinMode(A0, INPUT);
  pinMode(A1, OUTPUT);  // defines outputs for each motor control
  pinMode(A3, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  //PWM, it only runs movement half the time, halving the speed
  if (relay >= 2) {
    VinL = analogRead(A0);  //reads A0 voltage
    VinR = analogRead(A2);  //reads A2 voltage
    if ((VinL <= 3000) && (VinR >= 3000)) { //looks for each of 4 situations and controls the motors to turn towards a different situation
      digitalWrite(A3, 0);
      digitalWrite(A1, 1);
    } else if ((VinL <= 3000) && (VinR <= 3000)) {
      digitalWrite(A3, 1);
      digitalWrite(A1, 0);
    } else if ((VinL >= 3000) && (VinR <= 3000)) {
      digitalWrite(A3, 1);
      digitalWrite(A1, 0);
    } else if ((VinL <= 4000) && (VinR <= 4000)) {
      digitalWrite(A3, 1);
      digitalWrite(A1, 1);
    }
    //redundant peice of code as the above controls every situation, this would have made it go straight when it wasn't sure what to do
    else {
      digitalWrite(A3, 1);
      digitalWrite(A1, 1);
    }
    relay = 0;
  }
  //controls the PWM intervals, between this and the if statement it would allow for more precise control of how regular it checks
  relay = relay + 1;

  //delay for stability
  delay(5);
  //turns off motors for off-periods of PWM
  digitalWrite(A3, 0);
  digitalWrite(A1, 0);
}
