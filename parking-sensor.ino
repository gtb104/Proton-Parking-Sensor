// RGB LED pins
const int RED_LED_PIN = A6;
const int GREEN_LED_PIN = A4;
const int BLUE_LED_PIN = A2;
const int SONAR_PIN = A0;

// Colors
const int RED = 0;
const int YELLOW = 1;
const int GREEN = 2;
const int OFF = 3;

// The final distance value
double distance = 0.0;

// Voltage reading from sonar
int voltage = 0;

void setup() {
    pinMode(SONAR_PIN, INPUT);
    pinMode(RED_LED_PIN, OUTPUT);
    pinMode(GREEN_LED_PIN, OUTPUT);
    pinMode(BLUE_LED_PIN, OUTPUT);

    // Register a Spark variable here that we can get via curl
    // curl "https://api.particle.io/v1/devices/55ff6d065075555348131787/dist?access_token=e6e9091b5aadb3443230b1fcddb783d19f2a5e0b"
    Particle.variable("dist", &distance, DOUBLE);
}

void setColor(int color) { 
    if (color == GREEN) {
        digitalWrite(RED_LED_PIN, HIGH);
        digitalWrite(GREEN_LED_PIN, LOW);
        digitalWrite(BLUE_LED_PIN, HIGH);
    } else if (color == YELLOW) {
        digitalWrite(RED_LED_PIN, LOW);
        digitalWrite(GREEN_LED_PIN, LOW);
        digitalWrite(BLUE_LED_PIN, HIGH);
    } else {
        digitalWrite(RED_LED_PIN, LOW);
        digitalWrite(GREEN_LED_PIN, HIGH);
        digitalWrite(BLUE_LED_PIN, HIGH);
    }
}

int getColorForDistance(int distance) {
    if (distance < 36) {
        return RED;
    } else if (distance >= 36 && distance <= 60) {
        return YELLOW;
    } else {
        return GREEN;
    }
}

void loop() {
    voltage = analogRead(SONAR_PIN);
    distance = voltage / 9.8; // 9.8v per inch
    // Serial.println(distance); //for debugging
    setColor(getColorForDistance(distance));
    delay (100);
}
