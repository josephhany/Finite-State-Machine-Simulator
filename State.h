#ifndef STATE_H
#define STATE_H

#include <string>
#include <vector>
#include <memory>
#include "Action.h"
//#include "FSM.cpp"

class FSM;
class State {
private:
    std::string name;
    FSM* current_FSM;
    std::vector<std::shared_ptr<Action>> actions;

public:
    State(const std::string& name);
    void setFSM(FSM * fsm);
    void addAction(std::shared_ptr<Action> action);
    void executeActions();
    std::string getName() const ;
};

#endif // STATE_H