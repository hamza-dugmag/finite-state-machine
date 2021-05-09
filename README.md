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
