#ifndef ACTION_H
#define ACTION_H
//#include "FSM.h"
class FSM;
class Action {
public:
    FSM *current_FSM;
    
   // Action(FSM* current_FSM){
    //    this->current_FSM = current_FSM;
   // }
    virtual void set_FSM(FSM* fsm) =0;
    // virtual ~Action() = 0; // destructor ya basha
    virtual void execute() = 0;
};

#endif // ACTION_H
