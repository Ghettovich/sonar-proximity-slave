const int TRIG_PIN = 7;
const int ECHO_PIN = 8;
const int INTERVAL = 60;

int distance = 0;
unsigned long currentMillis = 0, previousMillis = 0;

void setupSonar() {
  // Define inputs and outputs for sonar
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
}

int getUSDistance() {
  return distance;
}

/*
   Measure distance in centimeters. A delay of 10 microseconds is necessary
   because we have to wait untill the sensors receives the emitted sound wave.
   We then calculate the distance based on the duration. We divide by 2 because
   the sound wave travels from sensor to object and from object to sensor.
*/
void measureDistance() {

  // Clear the trigPin by setting it LOW:
  digitalWrite(TRIG_PIN, LOW);

  delayMicroseconds(5);
  // Trigger the sensor by setting the trigPin high for 10 microseconds:
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // Read the echoPin. pulseIn() returns the duration (length of the pulse) in
  // microseconds:
  long duration = pulseIn(ECHO_PIN, HIGH);

  if (duration > 0) {
    distance = duration * 0.034 / 2; // cm calculation
  }

  Serial.println(distance);
}

void usLoop() {
  currentMillis = millis();

  if (currentMillis >= previousMillis + INTERVAL) {
    previousMillis = currentMillis;
    measureDistance();
  }
}
