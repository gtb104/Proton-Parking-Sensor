// RGB LED pins
const int RED_LED_PIN = A6;
const int GREEN_LED_PIN = A4;
const int BLUE_LED_PIN = A2;
const int SONAR_PIN = A0;

// The final distance value
double distance = 0.0;

void setup() {
    pinMode(SONAR_PIN, INPUT);
    pinMode(RED_LED_PIN, OUTPUT);
    pinMode(GREEN_LED_PIN, OUTPUT);
    pinMode(BLUE_LED_PIN, OUTPUT);
    // Register a Spark variable here that we can get via curl
    Spark.variable("distance", &distance, DOUBLE);
}

void loop() {
    int reading = 0;
    reading = analogRead(SONAR_PIN);
    // 9.8v per inch
    distance = reading / 9.8;

    if (distance < 24) {
        // Red
        digitalWrite(RED_LED_PIN, 0);
        digitalWrite(GREEN_LED_PIN, 255);
        digitalWrite(BLUE_LED_PIN, 255);
    } else if (distance >= 24 && distance <= 48) {
        // Yellow
        digitalWrite(RED_LED_PIN, 0);
        digitalWrite(GREEN_LED_PIN, 0);
        digitalWrite(BLUE_LED_PIN, 255);
    } else {
        // Green
        digitalWrite(RED_LED_PIN, 255);
        digitalWrite(GREEN_LED_PIN, 0);
        digitalWrite(BLUE_LED_PIN, 255);
    }
}
