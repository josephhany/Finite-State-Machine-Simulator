#ifndef PARSER_H
#define PARSER_H

#include "FSM.h"
#include <string>

class Parser {
public:
    static bool parseFSMFile(const std::string& filename, FSM& fsm);
private:
    // create an action factory
    static std::shared_ptr<Action> create_action(const std::string& action, std::istringstream& tokenIss, FSM& fsm);
    static bool isNumber(const std::string& str);
};

#endif  // PARSER_H
