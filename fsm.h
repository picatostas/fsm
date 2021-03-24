/*
 * fsm.h
 *
 *  Created on: January 21
 *      Author: Pablo Costas
 */

#ifndef FSM_H_
#define FSM_H_

#include <stdint.h>
#include <stdbool.h>


typedef struct fsm_s fsm_t;

typedef bool (*fsm_condition_t)(fsm_t *fsm);
typedef void (*fsm_action_t)(fsm_t *fsm);

typedef struct {
    int8_t prev_state;
    int8_t next_state;
    fsm_condition_t condition;
    fsm_action_t action;
} fsm_transition_t;

struct fsm_s {
    uint8_t current_state;
    fsm_transition_t *transitions;
    void *user_context;
};

/**
 * @brief iterate over all transitions to evaluate if a state change will be produced or not.
 * @args:
 * @param[inout] fsm pointer to fsm to evaluate
 *
 **/
void fsm_eval(fsm_t * fsm);

#endif
