const int switchPin = 8;
unsigned long previousTime = 0;
int switchState = 0;
int prevSwitchState = 0;
int led = 2;
long interval = 128571;
// long interval = 1000; // testing interval

void setup() {
  // preping all pins
  for(int i = 2; i < 8; i++){
    pinMode(i,OUTPUT);
  }
}

void loop() {
  // constantly seeing if button is being pressed
  switchState = digitalRead(8);
  // if it is switch go to 1,
  int go = 0;
  if(switchState == HIGH){
    go = 1;
  }
  // the go variable is used to get around complications of the button having to be
  // held down for the entire duration if it were the subject of the while loop or an if statement

  // if button is pressed
  while(go == 1){
    unsigned long currentTime = millis();
    if(currentTime - previousTime > interval){
      previousTime = currentTime;
      digitalWrite(led, HIGH);
      led++;
      if(led == 9){
        for(int i = 2; i < 8; i++){
          digitalWrite(i,LOW);
          led = 2;
        }
        go = 0;
      }
    }
    // reset
    switchState = digitalRead(switchPin);
    if(switchState != prevSwitchState){
      for(int i = 2; i < 8; i++){
        digitalWrite(i, LOW);
      }
    led = 2;
    previousTime = currentTime;
    }
    prevSwitchState = switchState;
  }
}
