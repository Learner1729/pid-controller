/* 
* @file pid.hpp
* @Auther Yash Shah (Driver),  Ashish Patel (Navigator)
* @version 1.0
* @brief Header file for pid class
* @copyright MIT License (c) 2018  
*/

#ifndef INCLUDE_PID_HPP_
#define INCLUDE_PID_HPP_

/**
 * The PIDController class has variables for each of the term as well  as time
 * interval and error variables. It has the method to implement PID controller to achieve the 
 * desired goal.
 */
class PIDController{
 public:
  /**
  * @brief PIDController constructor
  * @param none
  * @return none 
  */
  PIDController();

  /**
  * @brief Parameterized PID Constructor
  * @param[1] Kp which is a proportional coefficient
  * @param[2] Ki which is a integral coefficient
  * @param[3] Kd which is a differential coefficient
  * @param[4] time_interval which is delta t
  * @return none
  */
  PIDController(double Kp, double Ki, double Kd, double time_interval);
  
  /**
  * @brief compute method 
  * @param[1] target_velocity, which is Set Point(SP)
  * @param[2] actual_velocity, which is Process Value (PV)
  * @return double
  */
  auto compute(double target_velocity, double actual_velocity) -> double;

  /**
  * @brief Method to get value of private class member previous_error_ 
  * @param none
  * @return double
  */
  auto getPreviousError() -> double;

  /**
  * @brief Method to get value of private class member accumulation_error_ 
  * @param none
  * @return double
  */
  auto getAccumulationError() -> double;

  /**
  * @brief Method to get value of private class member time_interval_ 
  * @param none
  * @return double
  */
  auto getTimeInterval() -> double;
 private:
  double Kp_ //< Proportional Constant
  double Ki_ //< Integral Constant
  double Kd_ //< Derivative Constant
  double time_interval_ //< Time Step
  double previous_error_ //< Previous Error
  double accumulation_error_ //< Cumulative Error
};

#endif  // INCLUDE_PID_HPP_