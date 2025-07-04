#define ONBOARD_LED       22

void setup() {

  pinMode(ONBOARD_LED, OUTPUT);
}
void loop() {

  for(int i = 0; i < 255; i++){
    analogWrite(ONBOARD_LED, i);
    delay(5);
  }
  for(int i = 255; i > 0; i--){
    analogWrite(ONBOARD_LED, i);
    delay(5);

  }

}
