#define ONBOARD_LED       22

void setup() {

  pinMode(ONBOARD_LED,OUTPUT);
}
void loop() {
  digitalWrite(ONBOARD_LED, HIGH);
  delay(500);
  digitalWrite(ONBOARD_LED, LOW);
  delay(500);

}
