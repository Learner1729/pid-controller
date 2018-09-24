/* 
* @file main.cpp
* @Auther Yash Shah (Driver),  Ashish Patel (Navigator)
* @version 1.0
* @brief Week 4 Test Driven Development Exercise 
* @copyright MIT License (c) 2018  
*/

// c++ header file
#include <iostream>
// user defined header file
#include "pid.hpp"

int main()
{
    PIDController control(0.05, 0.4, 0.0001, 0.005);
    std::cout << control.compute(0.0,0.0) << std::endl;
    std::cout << control.compute(5.0,4.0) << std::endl;
    std::cout << control.compute(7.0,8.0) << std::endl;
    std::cout << control.compute(0.0,0.0) << std::endl;
    return 0;
}