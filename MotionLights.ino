#define LED_PIN 8
#define READ_LED_PIN 13
#define SENSOR_PIN 12

#define START_DELAY 5000
#define LED_BLINK_DELAY 1000
#define DELAY_PERIOD 100
#define COUNTER_MAX  50

void setup() {
  pinMode(LED_PIN, OUTPUT);
  pinMode(SENSOR_PIN, INPUT);

  delay(START_DELAY);

  for (int i = 0; i <= 2; i++) {
    digitalWrite(LED_PIN, HIGH);
    delay(LED_BLINK_DELAY);
    digitalWrite(LED_PIN, LOW);
    delay(LED_BLINK_DELAY);
  }
}

int test() {
  return digitalRead(SENSOR_PIN);
}

void active() {
  digitalWrite(LED_PIN, HIGH);

  int counter = COUNTER_MAX;

  do {
    delay(DELAY_PERIOD);

    if (test()) {
      counter = COUNTER_MAX;
    } else {
      counter--;
    }
    
  } while (counter > 0);

  digitalWrite(LED_PIN, LOW);
}

void loop() {
  if (test()) {
    active(); 
  }

  delay(DELAY_PERIOD);
}
