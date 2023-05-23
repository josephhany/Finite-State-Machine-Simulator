#include "Transition.h"

Transition::Transition(const std::string& sourceState, const std::string& destinationState, const std::string& inputValue)
    : sourceState(sourceState), destinationState(destinationState), inputValue(inputValue) {}

bool Transition::isTriggered(const std::string& currentState, const std::string& input) const {
    return (currentState == sourceState && input == inputValue);
}

std::string Transition::getDestinationState() const {
    return destinationState;
}
