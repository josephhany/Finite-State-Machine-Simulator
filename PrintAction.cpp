#include "PrintAction.h"
#include <iostream>

PrintAction::PrintAction(const std::string& expression)
    : expression(expression) {}

void PrintAction::execute() {
    std::string result = expression;
    size_t pos = result.find('“');
    if (pos != std::string::npos) {
        while (pos != std::string::npos) {
            result.erase(pos, 1);
            pos = result.find('”', pos);
        }
        std::cout << result << std::endl;

    }
    else {
    
        // Remove spaces using erase-remove idiom (C++11)
        // using lambda expression
        expression.erase(std::remove_if(expression.begin(), expression.end(), [](unsigned char c) {
            return std::isspace(c);
        }), expression.end());

        int val= current_FSM->getVariable(expression)->getValue();
        std::cout << val << std::endl;
    }

}