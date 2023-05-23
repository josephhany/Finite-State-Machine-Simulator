#ifndef JUMPACTION_H
#define JUMPACTION_H

#include "Action.h"
#include <string>
#include "FSM.h"

class JumpAction : public Action {
private:
    FSM* current_FSM;
    std::string nextState;

public:
    void set_FSM(FSM* fsm) { current_FSM = fsm; };

    JumpAction(const std::string& nextState);
    void execute() override;
};

#endif // JUMPACTION_H
