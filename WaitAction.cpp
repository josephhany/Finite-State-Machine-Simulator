#include "WaitAction.h"
#include <iostream>

void WaitAction::execute() {
    // Implement the logic to wait for the next transition
    
    // Get the input from the user
    std::string input;
    std::cout << "Enter the input: ";
    std::cin >> input;
    // Process the input
    current_FSM->processInput(input);
}
