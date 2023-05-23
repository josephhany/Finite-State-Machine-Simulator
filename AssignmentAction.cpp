#include "AssignmentAction.h"
#include <iostream>


AssignmentAction::AssignmentAction(std::shared_ptr<Variable<int>> variable, const std::string& expression1, const std::string& expression2, char op)
    : variable(variable), op(op), expression1(expression1), expression2(expression2) {}

void AssignmentAction::execute() {
    
    
    int value1 = expressionToVal(expression1);
    int value2 = expressionToVal(expression2);

    // Perform the assignment
    if (op == '+') {
        variable->setValue(value1 + value2);
    }
    else if (op == '*') {
        variable->setValue(value1 * value2);
    }
    else {
        std::cout << "Invalid operator: " << op << std::endl;
    }
}

int AssignmentAction::expressionToVal(std::string expression){
    
    std::istringstream iss(expression);
    double val;
    
    // If expression is a constant
    if ((iss >> val) && (iss.eof())){
        size_t pos = 0;
        return std::stoi(expression, &pos);
    }
    
    // If expression is a variable name
    std::shared_ptr<Variable<int>> variable_sh = current_FSM->getVariable(expression);
    if (variable_sh != nullptr) {
        return variable_sh->getValue();
    }

    // Handle error case when expression is neither a valid number nor a variable
    throw std::runtime_error("Invalid expression: " + expression);

}
