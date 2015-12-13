
// Analog read from potentiometr
#define PIN_SPEED_READ A0
// Write to Servo (ESC) has same controlling interface
#define PIN_SPEED_WRITE 11 



void setup() {

  Serial.begin(9600);
  
  pinMode(PIN_SPEED_READ, INPUT);
  pinMode(PIN_SPEED_WRITE, OUTPUT);

}

void loop() {

  // read speed in reang 0 to 1023
  int inputSpeed = analogRead(PIN_SPEED_READ);

  // convert analog value to PWM values
  int outputSpeed = map(inputSpeed, 0, 1023, 0, 255);

  // Set speed for ESC
  analogWrite(PIN_SPEED_WRITE, outputSpeed);
  
  Serial.print("Out speed: ");
  Serial.println(outputSpeed);
}
