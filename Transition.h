#ifndef TRANSITION_H
#define TRANSITION_H

#include <string>

class Transition {
private:
    std::string sourceState;
    std::string destinationState;
    std::string inputValue;

public:
    Transition(const std::string& sourceState, const std::string& destinationState, const std::string& inputValue);
    bool isTriggered(const std::string& currentState, const std::string& input) const;
    std::string getDestinationState() const;
};

#endif // TRANSITION_H
