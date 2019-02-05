// Arduino pin numbers
const int SW_pin = 2; // digital pin connected to switch output
const int X_pin = A0; // analog pin connected to X output
const int Y_pin = A1; // analog pin connected to Y output

void setup() {
  pinMode(SW_pin, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  char c[12];
  int x = analogRead(X_pin);
  int y = analogRead(Y_pin);
  int z = digitalRead(SW_pin);
  sprintf(c,"%04d %04d %d",x,y,z);
  Serial.println(c);
  delay(500);
}
