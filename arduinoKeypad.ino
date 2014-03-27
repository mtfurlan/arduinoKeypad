const int DEBOUNCE = 50;

const int GREEN_PIN = 2;
int greenState = 1;
int greenStateLast = 1;
int greenDebounce = 0;

void setup(){
  Serial.begin(9600);
  pinMode(GREEN_PIN, INPUT_PULLUP);
  
}

void loop(){
  greenState = digitalRead(GREEN_PIN);
  if(millis() - greenDebounce > DEBOUNCE && greenState != greenStateLast){
    if(greenState == LOW){
      Serial.println("science");
    }
    greenStateLast = greenState;
    greenDebounce = millis();
  }
}

