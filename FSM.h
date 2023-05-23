#ifndef FSM_H
#define FSM_H

#include <string>
#include <vector>
#include <memory>
#include <iostream>
#include <unordered_map>
#include "State.h"
#include "Transition.h"
#include "Variable.h"

class FSM {
private:
    std::string machineName;
    std::vector<State*> states;
    std::vector<std::shared_ptr<Transition>> transitions;
    std::string currentState;
    // std::unordered_map<std::string, int> variables
    std::vector<std::shared_ptr<Variable<int>>> variables;


public:
    FSM(const std::string& machineName);
    void addState(State* state);
    void addVariable(const std::string& variable);
    // void addTransition(std::shared_ptr<Transition> transition);
    void setCurrentState(const std::string& state);
    void processInput(const std::string& input);
    void addTransition(const std::string& sourceState, const std::string& destState, const std::string& inputValue);
    // Variable& getVariable(const std::string& variable);
    std::shared_ptr<Variable<int>> getVariable(const std::string& variable);
    void executeStateAction(std::string stateName);
    ~FSM();
};

#endif // FSM_H
