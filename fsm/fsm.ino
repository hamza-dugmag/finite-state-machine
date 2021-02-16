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
    pinMode(redPin, OUTPUT);
    pinMode(yellowPin, OUTPUT);
    pinMode(greenPin, OUTPUT);
    pinMode(buttonPin, INPUT_PULLUP);

    // initialize
    digitalWrite(redPin, LOW);
    digitalWrite(yellowPin, LOW);
    digitalWrite(greenPin, LOW);
    data.prev = 1;
    data.cur = 1;
}

void loop()  // while (true)
{
    // update data
    data.prev = data.cur;
    data.cur = digitalRead(buttonPin);
    
    // run state
    cur_state = run_state(cur_state, &data);
    
    delay(15);  // debounce
}
