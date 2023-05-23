#ifndef SLEEPACTION_H
#define SLEEPACTION_H

#include "Action.h"

class SleepAction : public Action {
private:
    int amount;

public:
    SleepAction(int amount);
    void execute() override;
    void set_FSM(FSM* fsm) { current_FSM = fsm; };

};

#endif // SLEEPACTION_H
