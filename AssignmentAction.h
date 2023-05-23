#ifndef ASSIGNMENTACTION_H
#define ASSIGNMENTACTION_H

#include "Action.h"
#include <memory>
#include <string>
#include "variable.h"
#include <sstream>
#include "FSM.h"


class AssignmentAction : public Action {
private:
    std::shared_ptr<Variable<int>> variable;
    char op;
    std::string expression1;
    std::string expression2;

public:
    AssignmentAction(std::shared_ptr<Variable<int>> variable, const std::string& expression1, const std::string& expression2, char op);
    void execute() override;
    void set_FSM(FSM* fsm) { current_FSM = fsm; };
    int expressionToVal(std::string expression);
};

#endif // ASSIGNMENTACTION_H
