/*
========================================================
 Smart Water Tank Control System
 ESP32 + Relay + Float Switch
 Bare Metal Implementation (No RTOS)

 Features:
 - Automatic water level detection
 - Automatic pump ON/OFF control
 - Serial monitoring for debugging

 Hardware:
 - ESP32 WROOM 32
 - Vertical Float Switch
 - Relay Module
 - 6V Water Pump

 Authors: Barath Kumar BA , MahilMithran RS , Kirubhakaran S , Balu B
========================================================
*/

// ---------------- PIN DEFINITIONS ----------------

#define RELAY_PIN 23
#define FLOAT_PIN 4


// ---------------- SETUP ----------------

void setup()
{
    // Serial Monitor
    Serial.begin(115200);

    // Relay Output
    pinMode(RELAY_PIN, OUTPUT);

    // Float Switch Input
    // INPUT_PULLUP enables internal pull-up resistor
    pinMode(FLOAT_PIN, INPUT_PULLUP);

    // Pump OFF initially
    digitalWrite(RELAY_PIN, HIGH);

    Serial.println("System Started...");
}


// ---------------- MAIN LOOP ----------------

void loop()
{
    // Read float switch state
    int levelState = digitalRead(FLOAT_PIN);


    // ------------------------------------
    // FLOAT SWITCH LOGIC
    //
    // HIGH = Tank Empty
    // LOW  = Tank Full
    //
    // (May vary depending on float orientation)
    // ------------------------------------

    if(levelState == HIGH)
    {
        // Tank Empty -> Turn Pump ON
        digitalWrite(RELAY_PIN, LOW);   // Active LOW relay

        Serial.println("Water Level LOW");
        Serial.println("Pump ON");
    }
    else
    {
        // Tank Full -> Turn Pump OFF
        digitalWrite(RELAY_PIN, HIGH);

        Serial.println("Water Level HIGH");
        Serial.println("Pump OFF");
    }

    Serial.println("----------------------");

    // Small stability delay
    delay(500);
}
