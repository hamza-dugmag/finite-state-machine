// Hamza Dugmag
// UTAT Rocketry Avionics
// Liquid Rocket Flight System FSM
// University of Toronto
// 2021-02-16

#include "states.h"

state_t cur_state = STATE_GREEN;
instance_data_t data;

void setup()  // int main()
{
    // pinmodes
    pinMode(red_pin, OUTPUT);
    pinMode(yellow_pin, OUTPUT);
    pinMode(green_pin, OUTPUT);
    pinMode(button_pin, INPUT_PULLUP);

    // initialize
    digitalWrite(red_pin, LOW);
    digitalWrite(yellow_pin, LOW);
    digitalWrite(green_pin, LOW);
    data.prev = 1;
    data.cur = 1;
}

void loop()  // while (true)
{
    // update data
    data.prev = data.cur;
    data.cur = digitalRead(button_pin);
    
    // run state
    cur_state = run_state(cur_state, &data);
    
    delay(15);  // debounce
}
