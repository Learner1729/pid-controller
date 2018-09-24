/* 
* @file pid.hpp
* @Auther Yash Shah (Driver),  Ashish Patel (Navigator)
* @version 1.0
* @brief Header file for pid class
* @copyright MIT License (c) 2018  
*/

#ifndef INCLUDE_PID_HPP_
#define INCLUDE_PID_HPP_

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
 double compute(double target_velocity, double actual_velocity);
 private:
  double Kp_, Ki_, Kd_, time_interval_, previous_error_, accumulation_error_;
};

#endif  // INCLUDE_PID_HPP_