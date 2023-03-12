const int dry = 620;    // TODO: Check this value with the sensor in the air
const int wet = 239;    // TODO: Check this value with the sensor in the water

const int MOISTURE_SENSOR_PIN = A0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.print("A0's value = ");
  Serial.println(analogRead(MOISTURE_SENSOR_PIN));

  int sensorVal = analogRead(MOISTURE_SENSOR_PIN);
  int percentageHumidity = map(sensorVal, wet, dry, 100, 0);
  Serial.print("Humidity percentage = ");
  Serial.print(percentageHumidity);
  Serial.println("%");

  delay(100);
}