#include "decoder.h"

void print_button() {
    Serial.print("Button id: ");
    Serial.println(button.get_value() / 10);

    Serial.print("Button state: ");
    Serial.println(button.get_value() % 10);
}

void print_lever() {
    Serial.print("Lever id: ");
    Serial.println(lever.get_value() / 10);

    Serial.print("Lever state: ");
    Serial.println(lever.get_value() % 10);
}

void print_j_l() {
    Serial.print("Left joystick X value: ");
    Serial.println(j_l.get_x());

    Serial.print("Left joystick Y value: ");
    Serial.println(j_l.get_y());
}

void print_j_r() {
    Serial.print("Right joystick X value: ");
    Serial.println(j_r.get_x());

    Serial.print("Right joystick Y value: ");
    Serial.println(j_r.get_y());
}

void print_p_l() {
    Serial.print("Left potentiometer value: ");
    Serial.println(p_l.get_values());
}

void print_p_r() {
    Serial.print("Right potentiometer value: ");
    Serial.print(p_r.get_values());
}

// Analyze dataReceived[] and call the appopriate function for every index
void decoder() 
{
    // Update all the objects with the respective values from dataReceived[]
    update_all(button, lever, j_l, j_r, p_l, p_r);

    for (uint8_t i = 0; i < ARRAY_SIZE; i++)
    {
        switch (i)
        {
            case 0:
                print_button(); break;
            case 1:
                print_lever(); break;
            case 3: 
                print_j_l(); break;
            case 4:
                print_j_r(); break;
            case 6:
                print_p_l(); break;
            case 7:
                print_p_r(); break;
                // Cases 8 to 10 don't have a purpose yet and will be discarded by default
            default:
                break;
        }
    }
    Serial.println("");
}
