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
    // abort if unsafe
    if (cur_state != STATE_ABORT)
        if (check_safety(data) == 1)
            return state_table[STATE_ABORT](data);

    return state_table[cur_state](data);
}

int check_safety(instance_data_t *data)
{
    Serial.println("Checking safety...");
    return 0;  // return 1 to abort (can use other numbers for different abort situations)
}


// FORMALIZED STATES
state_t do_state_INIT(instance_data_t *data)
{
    Serial.println("Initializing system...");
    return STATE_GREEN;
}

state_t do_state_ABORT(instance_data_t *data)
{
    Serial.println("Aborting...");
    return STATE_COMMS;
}

state_t do_state_COMMS(instance_data_t *data)
{
    Serial.println("Reporting back to ground...");
    // do whatever you want here (can even re-check safety in case you want to get back up)
    return STATE_COMMS;
}


// MAIN STATES
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
