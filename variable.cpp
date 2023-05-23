#include "Variable.h"

template <typename T>
Variable<T>::Variable(const std::string& name) : name(name), value(T(0)) {}

template <typename T>
void Variable<T>::setValue(const T& value) {
    this->value = value;
}

template <typename T>
T Variable<T>::getValue() const {
    return value;
}

template <typename T>
std::string Variable<T>::getName() const {
    return name;
}

// Explicit template instantiation for int
template class Variable<int>;