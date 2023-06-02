int buzzer = 6;
int ldrs[4] = {2, 3, 4, 5};
int greenLed = 8;
int lives = 2;
bool cont = true;


void setup() {
  lives--;
  Serial.begin(9600);
  for (int i = 0; i < 4; i++) {pinMode(ldrs[i], INPUT);}
  pinMode(buzzer, OUTPUT);
}

void loop() {
  while (cont == true) {
    for (int i = 0; i < 4; i++) {
      if (digitalRead(ldrs[i]) == 0) {
        Serial.println(ldrs[i]);
        if (lives > 0) {
          lives--;
          for (int i = 0; i < 5; i++) {
            digitalWrite(buzzer, HIGH);
            delay(200);
            digitalWrite(buzzer, LOW);
            delay(200);
          }
        break;
        } else {
            cont = false;
            digitalWrite(buzzer, HIGH);
            delay(10000);
            digitalWrite(buzzer, LOW);
        }
      }
    }
  }
}


