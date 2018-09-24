/* 
* @file test.cpp
* @Auther Yash Shah (Driver),  Ashish Patel (Navigator)
* @version 1.0
* @brief Program that tests the PIDController
* @copyright MIT License (c) 2018  
*/

// c++ header file
#include <gtest/gtest.h>
// user defined header file
#include "pid.hpp"

/**
 * @brief Test for checking initialization methods
 * @section DESCRIPTION Used ASSERT macro instead of EXPECT because 
 *          if there is a failure in initialization tests the test
 *          execution should abort
 */
TEST(PIDControllerTest, initializationValues) {
  PIDController control1;

  // tests getAccumulationError method
  ASSERT_DOUBLE_EQ(control1.getAccumulationError(), 0.0);

  // tests getPreviousError method
  ASSERT_DOUBLE_EQ(control1.getPreviousError(), 0.0);

  // tests getTimeInterval method
  ASSERT_NE(control1.getTimeInterval(), 0.0);

  // tests value initialization using parameterized constructor
  PIDController control2(1.0,1.0,1.0,1.0);
  ASSERT_EQ(control2.getTimeInterval(), 1.0);
}

/**
 * @brief Tests for checking PID algorithm
 */
TEST(PIDControllerTest, computeFunction) {

  // tests compute method
  PIDController control(0.05, 0.4, 0.0001, 0.005);
  EXPECT_DOUBLE_EQ(control.compute(0.0,0.0), 0.0);
  EXPECT_DOUBLE_EQ(control.compute(5.0,4.0), 4.072);
  EXPECT_DOUBLE_EQ(control.compute(7.0,8.0), 7.91);
  EXPECT_DOUBLE_EQ(control.compute(0.0,0.0), 0.00);
}