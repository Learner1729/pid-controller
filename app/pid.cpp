/*
* @file pid.cpp
* @Auther Yash Shah (Driver),  Ashish Patel (Navigator)
* @version 1.0
* @brief Definition of PIDController class methods
* @copyright MIT License (c) 2018
*/

// c++ header file
#include <iostream>
// user defined header file
#include "pid.hpp"

/**
 * @brief PIDController constructor
 * @param none
 * @return none
 */
PIDController::PIDController(void) : Kp_(0.5), Ki_(0.001), Kd_(0.01),
                                    time_interval_(0.05), previous_error_(0.0),
                                    accumulation_error_(0.0) {
    std::cout << "Default constructor called" << std::endl;
}

/**
 * @brief Parameterized PID Constructor
 * @param[1] Kp_ which is a proportional coefficient
 * @param[2] Ki_ which is a integral coefficient
 * @param[3] Kd_ which is a differential coefficient
 * @param[4] time_interval_ which is delta t
 * @return none
 */
PIDController::PIDController(double Kp, double Ki, double Kd,
                            double time_interval) : Kp_(Kp), Ki_(Ki), Kd_(Kd),
                            time_interval_(time_interval),
                            previous_error_(0.0), accumulation_error_(0.0) {
    std::cout << "Parameterized constructor called" << std::endl;
}

/**
 * @brief compute method
 * @param[1] target_velocity, which is Set Point(SP)
 * @param[2] actual_velocity, which is Process Value (PV)
 * @return double
 */
auto PIDController::compute(double target_velocity,
                            double actual_velocity) -> double {
  auto error = 0.0;
  error = target_velocity - actual_velocity;
  // Setting new actual velocity to return it in case of error is zero
  auto newActualVelocity = actual_velocity;
  // If error is zero return same velocity
  if (error == 0.0) {
    return newActualVelocity;
  } else {  // compute new velocity based on pid algorithm
    // pid terms
    auto propError = 0.0;
    auto integError = 0.0;
    auto diffError = 0.0;
    // summing up error for integral term
    this->accumulation_error_ = this->accumulation_error_
        + error * this->time_interval_;
    // finding error difference for differential term
    diffError = error - this->previous_error_;
    propError = this->Kp_ * error;
    integError = this->Ki_ * this->accumulation_error_;
    diffError = this->Kd_ * diffError / this->time_interval_;
    // setting new error as previous error
    // to use it next for pid iteration
    this->previous_error_ = error;
    // calculating new velocity by adding pid terms
    // and given velocity
    newActualVelocity = propError + integError + diffError + newActualVelocity;

  }
  return newActualVelocity;
}

/**
 * @brief Method to get value of private class member previous_error_
 * @param none
 * @return double
 */
auto PIDController::getPreviousError() -> double {
    return previous_error_;
}

/**
 * @brief Method to get value of private class member accumulation_error_
 * @param none
 * @return double
 */
auto PIDController::getAccumulationError() -> double {
    return accumulation_error_;
}

/**
 * @brief Method to get value of private class member time_interval_
 * @param none
 * @return double
 */
auto PIDController::getTimeInterval() -> double {
    return time_interval_;
}
