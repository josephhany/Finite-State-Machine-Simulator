#include "JumpAction.h"

JumpAction::JumpAction(const std::string& nextState)
    : nextState(nextState) {}

void JumpAction::execute() {
    
    current_FSM->setCurrentState(nextState);
}
