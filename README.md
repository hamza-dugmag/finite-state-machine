# Liquid Rocket Flight System

This project is a finite-state machine (FSM) framework for the UTAT Liquid Rocket Flight System.
Testing code is a simple LED switcher.

## Description

An FSM is an interconnected collection of different states that the rocket may be in. Each state
is associated with performing a specific task and transitioning to the next state based on input data.
The *state manager* is the interface between the states and the rocket input data. This state manager
runs at each cycle of the flight system and informs the ground system.

In this FSM framework, an **initial state** is performed first and once, and is reservered for flight setup:

- Establishing communication with the ground system
- Resetting actuators to default positions
- Starting up sensors
- etc.

After completing the initialization tasks and transitioning to the first **main state**, the state manager
begins to perform safety checks. If a safety does not fail, the manager continues as normal, otherwise, it
forces a transition to the **abort state** with a specific abort code.

After aborting the flight system, the manager transitions to the **alert state**, where it coordinates
with the ground system for any override signals.

<img src="img/fsm-model.png?raw=true" height="300" width="auto">

The state manager is fed a **Data Package (DP)** on each cycle, which contains all sensor data, calculations,
and input from the ground system. The DP is updated on each cycle.

## Usage

In `states.h`, specify all input and output pins connected to the flight system's microcontroller.
In `fsm.ino`, initialize all pinModes for the input and output pins.

In `states.h`, please follow the template below to set up the FSM:

```cpp
// states and data
typedef enum { STATE_INIT, /* CREATE STATES HERE */ STATE_ABORT, STATE_COMMS, NUM_STATES } state_t;

typedef struct instance_data {
    /* ADD DATA PACKAGE CONTENTS HERE */
} instance_data_t;


// states and data
typedef enum { STATE_INIT, /* CREATE STATES HERE */, STATE_ABORT, STATE_COMMS, NUM_STATES } state_t;
typedef struct instance_data {
    /* ADD DATA PACKAGE CONTENTS HERE */
} instance_data_t;
typedef state_t state_func_t(instance_data_t *data);

// state functions
int check_safety(instance_data_t *data);
state_t do_state_INIT(instance_data_t *data);
state_t do_state_ABORT(instance_data_t *data);
state_t do_state_COMMS(instance_data_t *data);

state_t /* CREATE ALL STATE FUNCTIONS */(instance_data_t *data);

// state manager
state_func_t* const state_table[NUM_STATES] = {
    do_state_INIT, /* ADD ALL STATE FUNCTION NAMES HERE */, do_state_ABORT, do_state_COMMS
};
state_t run_state(state_t cur_state, instance_data_t *data);
```

Implement all the state functions in `states.cpp`

## Contact
Please contact @Hamza on the UTAT Rocketry Slack for any help, questions, etc.
