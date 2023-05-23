#include "State.h"

State::State(const std::string& name)
    : name(name) ,current_FSM(NULL) {}

void State::addAction(std::shared_ptr<Action> action) {
    action->set_FSM(current_FSM);
    actions.push_back(action);
}

void State::executeActions() {
    for (const auto& action : actions) {
        action->execute();
    }
}

void State::setFSM(FSM* fsm) {
    current_FSM = fsm;
}

std::string State::getName() const {
    return name;
}
