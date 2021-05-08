#include "decoder.h"

void button() {
    Serial.print("Button id: ");
    Serial.println(button.get_value / 10);

    Serial.print("Button state: ");
    Serial.println(button.get_value % 10);
}

void lever() {
    Serial.print("Lever id: ");
    Serial.println(lever.get_value / 10);

    Serial.print("Lever state: ");
    Serial.println(lever.get_value % 10);
}

void j_l() {
    Serial.print("Left joystick X value: ");
    Serial.println(j_l.get_x);

    Serial.print("Left joystick Y value: ");
    Serial.println(j_l.get_y);
}

void j_r() {
    Serial.print("Right joystick X value: ");
    Serial.println(j_r.get_x);

    Serial.print("Right joystick Y value: ");
    Serial.println(j_r.get_y);
}

void p_l(uint8_t value) {
    Serial.print("Left potentiometer value: ");
    Serial.println(p_l.get);
}

void p_r(uint8_t value) {
    Serial.print() "Right potentiometer value: "))
    Serial.print(value);
}

void decode() {
    // Update all the objects with the respective values from dataReceived[]
    update_all(button, lever, j_l, j_r, p_l, p_r);

    // Sort the array's value and sort which functions to call
    for (uint8_t i = 0; i <= ARRAY_SIZE; i++)
    {
        switch (i)
        {
            case 0:
                button(); break;
            case 1:
                lever(); break;
            case 2: // The 2 left joystick cases are merged together, same later with the right
            case 3:
                j_l(); break;
            case 4:
            case 5:
                j_r(); break;
            case 6:
                p_l(dataReceived[i]); break;
            case 7:
                p_r(dataReceived[i]); break;
            // Cases 6 to 10 don't have a purpose yet and will be discarded by default
            default:
                break;
        }
    }
}