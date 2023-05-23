#include "EndAction.h"
#include <iostream>

void EndAction::execute() {
    std::cout << "End of Finite state machine \n";
    free(current_FSM);
    exit(0);
}
