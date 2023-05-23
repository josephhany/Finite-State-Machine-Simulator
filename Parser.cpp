#include "Parser.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include "PrintAction.h"
#include "JumpAction.h"
#include "AssignmentAction.h"
#include "SleepAction.h"
#include "WaitAction.h"
#include "EndAction.h"

bool Parser::parseFSMFile(const std::string& filename, FSM& fsm) {
    std::ifstream file(filename);
    
    if (!file.is_open()) {
        std::cout << "Failed to open file: " << filename << std::endl;
        return false;
    }

    std::string line;
    std::string section;

    while (std::getline(file, line)) {
        
        if (line.empty())
            continue;
            
        std::istringstream iss(line);
        std::string token;
        iss >> token;
        
        if (token == "FSM") {
            iss >> token; // Assuming only one FSM in the file
            fsm = *(new FSM(token)); // Specify the FSM name here
        }
        else if (token == "VAR") {
            while (iss >> token) {
                
                // Remove the trailing comma, if present
                if (token.back() == ',')
                    token.pop_back();
                
                fsm.addVariable(token);
                
            }
        }
        else if (token == "States:" || token == "Transitions:") {
            section = token;
        }
        else {
            if (section == "States:") {
                std::string stateName = token.substr(0, token.size() - 1);
                // std::shared_ptr<State> state_temp = std::make_shared<State>(stateName);
                State* state_temp = new State(stateName);
                
                fsm.addState(state_temp);

                std::string actionToken;
                std::getline(iss, actionToken);  // Read the entire line after the state name
                std::istringstream actionIss(actionToken);
            
                while (std::getline(actionIss, actionToken, ',')) {
                    std::istringstream tokenIss(actionToken);
                    std::string action;
                    tokenIss >> action;

                    state_temp->addAction(create_action(action, tokenIss, fsm)); // create action

                }
                
                
            }
            else if (section == "Transitions:") {
                std::string sourceState = token;
                
                if (sourceState.back() == ',')
                    sourceState.pop_back();  // Remove the trailing comma
                
                std::string destinationState;
                std::string input;
                iss >> destinationState >> input;
                
                if (destinationState.back() == ',')
                    destinationState.pop_back();  // Remove the trailing comma
                
                fsm.addTransition(sourceState, destinationState, input);
            }
        }
        
    }

    file.close();
    return true;
}

// Using Method Factory Pattern to delegate the creation of actions to the method create_action
std::shared_ptr<Action> Parser::create_action(const std::string& action, std::istringstream& tokenIss, FSM& fsm){

    if (action == "PRINT") { // PRINT action
        std::string message;
        std::string nextToken;

        // Read the entire line after the PRINT token
        while (tokenIss >> nextToken && nextToken != "PRINT")
            message += nextToken + " ";

        return std::make_shared<PrintAction>(message);
    }
    else if (action == "JMP") { // JMP action
        std::string destState;
        tokenIss >> destState; // Read the destination state
        return std::make_shared<JumpAction>(destState);
    }
    else if (action == "sleep") { // sleep action
        int sleepTime;
        tokenIss >> sleepTime; // Read the sleep time
        return std::make_shared<SleepAction>(sleepTime);
    }
    else if (action == "wait") { // wait action
        return std::make_shared<WaitAction>();
    }
    else if (action == "end") { // end action
        return std::make_shared<EndAction>();
    }
    else if (isalpha(action[0]) && action[1] == '=') {

        std::string variable, expression1, expression2;
        char operation;

        variable = action[0];
        expression1 = action[2];
        operation = action[3];
        expression2 = action[4];

        if (!isNumber(expression1)) {
            // check if the variable is in the fsm
            if (fsm.getVariable(expression1) == nullptr) {
                std::cerr << "Error: Invalid l Variable!" << std::endl;
            }
        }

        if (!isNumber(expression2)) {
            // check if the variable is in the fsm
            if (fsm.getVariable(expression2) == nullptr) {
                std::cerr << "Error: Invalid l Variable!" << std::endl;
            }
        }

        std::shared_ptr<Variable<int>> variable_sh = fsm.getVariable(variable);
        // check if the variable is in the fsm
        if (variable_sh != nullptr) {
            return std::make_shared<AssignmentAction>(variable_sh, expression1, expression2, operation);
        }
        else {
            std::cerr << "Error: Invalid R Variable!" << std::endl;
        }

    }
    std::cerr << "Error: Invalid Action!" << std::endl;
    return nullptr;
}

bool Parser::isNumber(const std::string& str) {
    try {
        std::stoi(str);
        return true;
    }
    catch (const std::exception& e) {
        return false;
    }
}