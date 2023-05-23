#ifndef PRINTACTION_H
#define PRINTACTION_H

#include "Action.h"
#include <string>
#include "FSM.h"
class PrintAction : public Action {
private:
    std::string expression;

public:
    PrintAction(const std::string& expression);
    void execute() override;
    void set_FSM(FSM* fsm) { current_FSM = fsm; };

};

#endif // PRINTACTION_H
