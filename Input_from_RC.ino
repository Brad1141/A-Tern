
// Code for receiving RC signals

int pin1 = 10;//pins for RC_ControllerInput
int pin2 = 11;

void setup() {
    Serial.begin(9600);
    pinMode(pin1, INPUT);
    pinMode(pin2, INPUT);
}

void loop() {
    int speedValue = pulseIn(pin1, HIGH);
    int directionValue = pulseIn(pin2, HIGH);
    
    Serial.println(speedValue);
    Serial.println(directionValue);
    
    delay(50);
}
