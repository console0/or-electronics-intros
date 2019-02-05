// Arduino pin numbers
const int SW_pin = 2; // digital pin connected to switch output
const int X_pin = A0; // analog pin connected to X output
const int Y_pin = A1; // analog pin connected to Y output

void setup() {
  pinMode(SW_pin, INPUT_PULLUP);
  Serial.begin(9600);
  Serial.println("Serial Joystick");
}

void loop() {
  char c[12];
  int x = analogRead(X_pin);
  int y = analogRead(Y_pin);
  sprintf(c,"%d,%d",x,y);
  Serial.println(c);
  delay(100);
}
