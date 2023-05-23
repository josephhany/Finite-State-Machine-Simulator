#pragma once
#ifndef VARIABLE_H
#define VARIABLE_H

#include <string>

// use template to support different types of variables
template <typename T>
class Variable {
private:
    std::string name;
    T value;

public:
    Variable(const std::string& name);
    void setValue(const T& value);
    T getValue() const;
    std::string getName() const;
};

#endif // VARIABLE_H
