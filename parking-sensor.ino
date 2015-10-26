// RGB LED pins
const int RED_LED_PIN = A6;
const int GREEN_LED_PIN = A4;
const int BLUE_LED_PIN = A2;
const int SONAR_PIN = A0;

// The final distance value
double distance = 0.0;
int MIN = 112;
// Used to store the intensity level of the individual LEDs, intitialized to full brightness (0)
int redIntensity = 0;
int greenIntensity = 0;
int blueIntensity = 0;

void setup() {
    pinMode(SONAR_PIN, INPUT);
    pinMode(RED_LED_PIN, OUTPUT);
    pinMode(GREEN_LED_PIN, OUTPUT);
    pinMode(BLUE_LED_PIN, OUTPUT);
    // Register a Spark variable here that we can get via curl
    Spark.variable("dist", &distance, DOUBLE);
}

void loop() {
    int reading = 0;
    double voltage = 0.0;

    reading = analogRead(SONAR_PIN);
    voltage = reading + MIN;

    // 9.8v per inch
    distance = reading / 9.8;
    Serial.println(distance); //for debugging

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
