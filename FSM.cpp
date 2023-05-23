#include "FSM.h"

FSM::FSM(const std::string& machineName)
    : machineName(machineName) {}

void FSM::addState(State* state) {
    state->setFSM(this);
    states.push_back(state);
}

// void FSM::addTransition(std::shared_ptr<Transition> transition) {
//     transitions.push_back(transition);
// }

void FSM::addTransition(const std::string& sourceState, const std::string& destState, const std::string& inputValue) {
    transitions.emplace_back(std::make_shared<Transition>(sourceState, destState, inputValue));
}

void FSM::setCurrentState(const std::string& state_in) {
    for (const auto& state : states) {
        if (state->getName() == state_in) {
            currentState = state_in;
            executeStateAction(currentState); // execute action in current state
            return;
        }
    }
    std::cerr << "Error: Invalid State!" << std::endl;
}

void FSM::processInput(const std::string& input) {

    for (const auto& transition : transitions) {
        if (transition->isTriggered(currentState, input)) {
            currentState = transition->getDestinationState();
            executeStateAction(currentState);
            return;
        }
    }

    std::cerr << "Error: Invalid input!" << std::endl;
}

void FSM::addVariable(const std::string& variable) {
    // variables[variable] = 0;
    std::shared_ptr<Variable<int>> var = std::make_shared<Variable<int>>(variable);
    variables.push_back(var);
}

std::shared_ptr<Variable<int>> FSM::getVariable(const std::string& variable){

    for(const auto& var : variables){
        if(var->getName() == variable){
            return var;
        }
    }
    return nullptr;
}

void FSM::executeStateAction(std::string stateName){
    for (const auto& state : states) {
        if (state->getName() == stateName) {
            state->executeActions();
            break;
        }
    }
}

// destructor
FSM::~FSM() {
    for (const auto& state : states) {
        delete state;
    }
}