#ifndef ENDACTION_H
#define ENDACTION_H

#include "Action.h"

class EndAction : public Action {
public:
    void execute() override;
    void set_FSM(FSM* fsm) { current_FSM = fsm; };

};

#endif // ENDACTION_H
