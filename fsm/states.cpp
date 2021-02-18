// Hamza Dugmag
// UTAT Rocketry Avionics
// Liquid Rocket Flight System FSM
// University of Toronto
// 2021-02-16

// C code in C++ file.

#include "states.h"
#include "Arduino.h"

state_t run_state(state_t cur_state, instance_data_t *data)
{
    return state_table[cur_state](data);
}

state_t do_state_green(instance_data_t *data)
{
    digitalWrite(red_pin, LOW);
    digitalWrite(yellow_pin, LOW);
    digitalWrite(green_pin, HIGH);
    if (data->prev == 1 && data->cur == 0)
    {
        return STATE_YELLOW;
    }
    return STATE_GREEN;
}

state_t do_state_yellow(instance_data_t *data)
{
    digitalWrite(red_pin, LOW);
    digitalWrite(yellow_pin, HIGH);
    digitalWrite(green_pin, LOW);
    if (data->prev == 1 && data->cur == 0)
    {
        return STATE_RED;
    }
    return STATE_YELLOW;
}

state_t do_state_red(instance_data_t *data)
{
    digitalWrite(red_pin, HIGH);
    digitalWrite(yellow_pin, LOW);
    digitalWrite(green_pin, LOW);
    if (data->prev == 1 && data->cur == 0)
    {
        return STATE_GREEN;
    }
    return STATE_RED;
}
