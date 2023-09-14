int redLED = 12;
int blueLED = 11;
int buttonPin = 2;
int buzzerPin = 8;

volatile int buttonState;

void buttonInterrupt () {
  buttonState = digitalRead(buttonPin);

 if (buttonState == LOW) {
    digitalWrite(blueLED, HIGH);
    tone(buzzerPin, 1000); // Turn on the buzzer at 1000 Hz
    }

 if (buttonState == HIGH){
    digitalWrite(blueLED, LOW);
    noTone(buzzerPin); // Turn off the buzzer
      }
  }

void setup() {
 pinMode (redLED, OUTPUT);
 pinMode (blueLED, OUTPUT);
 pinMode(buttonPin, INPUT_PULLUP);
 pinMode(buzzerPin, OUTPUT);
 attachInterrupt(digitalPinToInterrupt(buttonPin), buttonInterrupt, CHANGE);
}

void loop() {
  digitalWrite(redLED, HIGH);
  delay(250);
  digitalWrite(redLED, LOW);
  delay(250);
}
