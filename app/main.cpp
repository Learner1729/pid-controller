#include <iostream>
#include "pid.hpp"

int main()
{
    PIDController control(0.05, 0.4, 0.0001, 0.005);
    std::cout << control.compute(0.0,0.0) << std::endl;
    std::cout << control.compute(5.0,4.0) << std::endl;
    std::cout << control.compute(7.0,8.0) << std::endl;
    return 0;
}