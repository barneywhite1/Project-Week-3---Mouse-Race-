void setup() {
  // put your setup code here, to run once:
  inductor_1_pin = A0;
  inductor_2_pin = A2;
  motor_1_pin = A1;
  motor_2_pin = A3;
  pinMode(motor_1_pin, OUTPUT);
  pinMode(motor_2_pin, OUTPUT);
  pinMode(inductor_1_pin, INPUT);
  pinMode(inductor_2_pin, INPUT);
}

k_p = 100;

void loop() {
  // put your main code here, to run repeatedly:
  V_L1 = analogRead(inductor_1_pin);
  V_L2 = analogRead(inductor_2_pin);
  V_M2 = V_L1/V_L2 * k_p;
  V_M1 = V_L2/V_L1 * k_p;
  analogWrite(motor_1_pin, V_M1);
  analogWrite(motor_2_pin, V_M2);
}
