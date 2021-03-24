#include "fsm.h"


void fsm_eval(fsm_t * fsm) {

    for (fsm_transition_t* aux = fsm->transitions; aux->prev_state >= 0; aux++) {
        if ((fsm->current_state == aux->prev_state) && aux->condition(fsm)) {
            fsm->current_state = aux->next_state;
            if (aux->action) {
                aux->action(fsm);
            }
        }
    }
}
