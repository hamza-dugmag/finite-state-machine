// Hamza Dugmag
// UTAT Rocketry Avionics
// Liquid Rocket Flight System FSM
// University of Toronto
// 2021-02-16
// https://stackoverflow.com/questions/133214/is-there-a-typical-state-machine-implementation-pattern

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

// pins
#define redPin 6
#define yellowPin 4
#define greenPin 2
#define buttonPin 23

// states and data
typedef enum { STATE_GREEN, STATE_YELLOW, STATE_RED, NUM_STATES } state_t;
typedef struct instance_data {
    int prev;
    int cur;
} instance_data_t;
typedef state_t state_func_t(instance_data_t *data);

// state functions
state_t do_state_green(instance_data_t *data);
state_t do_state_yellow(instance_data_t *data);
state_t do_state_red(instance_data_t *data);

// state manager
state_func_t* const state_table[NUM_STATES] = {
    do_state_green, do_state_yellow, do_state_red
};
state_t run_state(state_t cur_state, instance_data_t *data);

#endif
