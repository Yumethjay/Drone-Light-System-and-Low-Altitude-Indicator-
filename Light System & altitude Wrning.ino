// ultrasonic sensor
#define TRIG_PIN 9
#define ECHO_PIN 10

// LEDs
#define LED_FRONT 2
#define LED_BACK 3
#define LED_LEFT 4
#define LED_RIGHT 5

// buzzer
#define BUZZER_PIN 6

// Altitude threshold (in cm)
const int LOW_ALTITUDE_THRESHOLD = 50;

void setup() {
  // Initialize serial communication
  Serial.begin(9600);

  // Set pin modes
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  
  pinMode(LED_FRONT, OUTPUT);
  pinMode(LED_BACK, OUTPUT);
  pinMode(LED_LEFT, OUTPUT);
  pinMode(LED_RIGHT, OUTPUT);
  
  pinMode(BUZZER_PIN, OUTPUT);

  // Turn on drone light system
  digitalWrite(LED_FRONT, HIGH);
  digitalWrite(LED_BACK, HIGH);
  digitalWrite(LED_LEFT, HIGH);
  digitalWrite(LED_RIGHT, HIGH);
}

void loop() {
  // For measure altitude
  int altitude = measureAltitude();

  // Print altitude to serial monitor
  Serial.print("Altitude: ");
  Serial.print(altitude);
  Serial.println(" cm");

  // Check low altitude and warning
  if (altitude < LOW_ALTITUDE_THRESHOLD) {
    digitalWrite(BUZZER_PIN, HIGH); // Turn on buzzer
  } else {
    digitalWrite(BUZZER_PIN, LOW); // Turn off buzzer
  }

  delay(200);
}

//  measure altitude using ultrasonic sensor
int measureAltitude() {
  // Send a 10-microsecond pulse to the TRIG_PIN
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // Read ECHO_PIN,calculate the distance
  long duration = pulseIn(ECHO_PIN, HIGH);
  int distance = duration * 0.034 / 2; // Convert to cm

  return distance;
}
