#define LEDGREEN D7
#define LEDYELLOW D6
#define LEDRED D5

void setup() {
    pinMode(LEDGREEN, OUTPUT);
    pinMode(LEDYELLOW, OUTPUT);
    pinMode(LEDRED, OUTPUT);
    
    Particle.function("trafficLight", switchLight);
}

void loop() {

}

int switchLight(String colour) {
    digitalWrite(LEDRED, LOW);
    digitalWrite(LEDYELLOW, LOW);
    digitalWrite(LEDGREEN, LOW);
    
    Particle.publish("ChangeLight", colour);

    if (colour.equals("red")) {
        digitalWrite(LEDRED, HIGH);
        return 1;
    }
    else if (colour.equals("yellow")) {
        digitalWrite(LEDYELLOW, HIGH);
        return 1;
    }
    else if (colour.equals("green")) {
        digitalWrite(LEDGREEN, HIGH);
        return 1;
    }
    return -1;
}
