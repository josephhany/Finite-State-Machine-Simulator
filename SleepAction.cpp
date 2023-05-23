#include "SleepAction.h"
#include <chrono>
#include <thread>
#include <iostream>


SleepAction::SleepAction(int amount)
    : amount(amount) {}

void SleepAction::execute() {
    // Sleep for the specified amount of time
    std::cout<<"I will sleep for "<<amount<<" seconds\n";
    std::this_thread::sleep_for(std::chrono::seconds(amount));
    std::cout<<"I am awake\n";
}
