#ifndef WAITACTION_H
#define WAITACTION_H

#include "Action.h"
#include "FSM.h"

class WaitAction : public Action {
public:
    void execute() override;
    void set_FSM(FSM* fsm) { current_FSM = fsm; };

};

#endif // WAITACTION_H
