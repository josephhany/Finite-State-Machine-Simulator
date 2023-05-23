#include "FSM.h"
#include "Parser.h"
#include <iostream>

int main() {
    std::string filename = "fsm4.fsm";  // Specify the input file name here

    FSM * fsm_simulator = new FSM(""); // Create a FSM simulator object

    // Parse the FSM file and build the FSM
    if (!Parser::parseFSMFile(filename, *fsm_simulator)) {
        std::cout << "Failed to parse FSM file: " << filename << std::endl;
        return 1;
    }
    
    // Set the starting state to "a"
    fsm_simulator->setCurrentState("start");

    return 0;
}