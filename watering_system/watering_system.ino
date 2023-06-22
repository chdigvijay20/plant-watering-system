const int dry = 618;
const int wet = 239;

const int MOISTURE_SENSOR_PIN = A0;

const int RELAY_PIN = A5;
const int WATER_DETECT_PIN = 8;

void setup() {
  Serial.begin(9600);

  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, HIGH);

  pinMode(WATER_DETECT_PIN, INPUT);
}

void loop() {
  int moistureValue = analogRead(MOISTURE_SENSOR_PIN);
  int percentageHumidity = map(moistureValue, wet, dry, 100, 0);
  Serial.print("Humidity percentage = ");
  Serial.print(percentageHumidity);
  Serial.println("%");

  if (percentageHumidity > 40)
  {
    Serial.println("Humidity is more than 40, sleeping for 5 minutes...");
    delay(5 * 60 * 1000L);
    //delay(10 * 1000L);
    return;
  }

  for (int i = 1; i <= 3; i++) {
    int waterPresent = digitalRead(WATER_DETECT_PIN);
    if (!waterPresent) {
      Serial.print("Water not found (in iter ");
      Serial.print(i);
      Serial.println(")!!! Sleeping for 15 minutes...");
      delay(15 * 60 * 1000L);
      return;
    }
    delay(5 * 1000);
  }

  Serial.println("Looks like soil is dried... starting motor for 1 minute");
  digitalWrite(RELAY_PIN, LOW);
  delay(60 * 1000UL);

  Serial.println("Watering is done... will wait motor for 10 sec");
  digitalWrite(RELAY_PIN, HIGH);
  delay(10 * 1000UL);
}
