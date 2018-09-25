# PID Controller 
[![Build Status](https://travis-ci.org/ysshah95/pid-controller.svg?branch=master)](https://travis-ci.org/ysshah95/pid-controller)
[![Coverage Status](https://coveralls.io/repos/github/ysshah95/pid-controller/badge.svg?branch=master)](https://coveralls.io/github/ysshah95/pid-controller?branch=master)

## Table of Contents
- [Overview](#overview)
- [Introduction to PID Controller](#intro)
- [Authors](#authors)
- [Class Diagram](#class)
- [Activity Diagram](#activity)
- [Test Cases](#test)
- [Standard install via command-line](#implementation)
- [Working with Eclipse IDE](#eclipse)
- [Discussion Notes](#notes)
- [TODO](#todo)

## <a name="overview"></a> Overview
This repo is developed as a part of developing new mobile robot product for ACME Robotics. It implements PID Controller functionality for a new mobile robot. The team members working to develop this project uses pair programming software development technique. The authors are listed in the author section below. 

This repository serves as a simple C++ PID controller algorithm implementation with:

- cmake
- googletest

## <a name="intro"></a> Introduction to PID controller
PID is a control loop feedback mechanism. It continuously calculates an error value as the difference between a defined setpoint (SP) and a measured process value (PV) and applies correction based on Proportional, Integral and Derivative terms. The first component of PID controller is P which stands for proportional, that means it adjusts the output proportionally to the error using Kp, proportional coefficient. It's a constant non-negative value that is determined during the tuning process of the controller. The second component of controller is I which stands for integral, in mathematical term that means the accumulation of something with respect to something else. In this case accumulation of error over time. Its has an integral coefficient Ki. The third compoent of controller is D which stands for derivative, in mathematical term that means the slope of a curve. Its has a derivative coefficient Kd. 

The above three coefficients are used in tuning a PID controller. Tuning is the process of determining the ideal values for Kp, Ki, and Kd in order to achieve the desired response.  

## <a name="authors"></a> Authors for Part 1
- **Driver:** Yash Shah (UID: 115710498) (github: ysshah95)
- **Navigator:** Ashish Patel (UID: 115730625) (github: Learner1729)

## Authors for Part 2
- **Driver:** Hrishikesh Tawade (UID: 116078092) (github: hrishikeshtawade04)
- **Navigator:** Saurav Kumar (UID: 116139960) (github: sauravkdeo)

## <a name="class"></a> Class Diagram
<p align="center">
<a target="_blank"><img src="UML_Diagrams/ClassDiagram_TDD_V2.png"
alt="NMPC" width="480" height="360" border="10" />
</a>
</p>

## <a name="activity"></a> Activity Diagram
<p align="center">
<a target="_blank"><img src="UML_Diagrams/ActivityDiagram_TDD.png"
alt="NMPC" width="480" height="960" border="10" />
</a>
</p>

## <a name="test"></a> Test Cases

>Note: The below materials were taken from a pdf file of PID turning process downloaded from this [website](https://controlstation.com/).
We discussed few more test cases after completing part 2, to improve upon current implementation. There are a variety of tests that are commonly performed in industry. They include the Step Test, Pulse Test, Doublet Test, and Pseudo-Random Binary Sequence (PRBS). 
1. **Step or Convergence Test**: In step test a Controller Output is “stepped” from one constant value to another. It's used to check that the measured variable is steping up from one steady state to new steady state. We can implement to check the convergence of the controller to a new velocity in a particular duration.
2. **Pulse test**: Two step test performed in a rapid succession denotes pulse test.
3. **Doublet Test**: Two pulse tests performed in rapid succession and in opposite directions. The second pulse is implemented when a clear response is achieved in first pulse. 

## <a name="implementation"></a> Standard install via command-line
```
git clone --recursive https://github.com/ysshah95/pid-controller.git
cd <path to repository>
mkdir build
cd build
cmake ..
make
Run tests: ./test/cpp-test
Run program: ./app/shell-app
```

## Building for code coverage (for assignments beginning in Week 4)
```
sudo apt-get install lcov
cmake -D COVERAGE=ON -D CMAKE_BUILD_TYPE=Debug ../
make
make code_coverage
```
This generates a index.html page in the build/coverage sub-directory that can be viewed locally in a web browser.

## <a name="eclipse"></a> Working with Eclipse IDE ##

## Installation

In your Eclipse workspace directory (or create a new one), checkout the repo (and submodules)
```
mkdir -p ~/workspace
cd ~/workspace
git clone --recursive https://github.com/ysshah95/pid-controller.git
```

In your work directory, use cmake to create an Eclipse project for an [out-of-source build] of cpp-boilerplate

```
cd ~/workspace
mkdir -p boilerplate-eclipse
cd boilerplate-eclipse
cmake -G "Eclipse CDT4 - Unix Makefiles" -D CMAKE_BUILD_TYPE=Debug -D CMAKE_ECLIPSE_VERSION=4.7.0 -D CMAKE_CXX_COMPILER_ARG1=-std=c++14 ../cpp-boilerplate/
```

## Import

Open Eclipse, go to File -> Import -> General -> Existing Projects into Workspace -> 
Select "boilerplate-eclipse" directory created previously as root directory -> Finish

# Edit

Source files may be edited under the "[Source Directory]" label in the Project Explorer.


## Build

To build the project, in Eclipse, unfold boilerplate-eclipse project in Project Explorer,
unfold Build Targets, double click on "all" to build all projects.

## Run

1. In Eclipse, right click on the boilerplate-eclipse in Project Explorer,
select Run As -> Local C/C++ Application

2. Choose the binaries to run (e.g. shell-app, cpp-test for unit testing)


## Debug


1. Set breakpoint in source file (i.e. double click in the left margin on the line you want 
the program to break).

2. In Eclipse, right click on the boilerplate-eclipse in Project Explorer, select Debug As -> 
Local C/C++ Application, choose the binaries to run (e.g. shell-app).

3. If prompt to "Confirm Perspective Switch", select yes.

4. Program will break at the breakpoint you set.

5. Press Step Into (F5), Step Over (F6), Step Return (F7) to step/debug your program.

6. Right click on the variable in editor to add watch expression to watch the variable in 
debugger window.

7. Press Terminate icon to terminate debugging and press C/C++ icon to switch back to C/C++ 
perspetive view (or Windows->Perspective->Open Perspective->C/C++).


## Plugins

- CppChEclipse

    To install and run cppcheck in Eclipse

    1. In Eclipse, go to Window -> Preferences -> C/C++ -> cppcheclipse.
    Set cppcheck binary path to "/usr/bin/cppcheck".

    2. To run CPPCheck on a project, right click on the project name in the Project Explorer 
    and choose cppcheck -> Run cppcheck.


- Google C++ Sytle

    To include and use Google C++ Style formatter in Eclipse

    1. In Eclipse, go to Window -> Preferences -> C/C++ -> Code Style -> Formatter. 
    Import [eclipse-cpp-google-style][reference-id-for-eclipse-cpp-google-style] and apply.

    2. To use Google C++ style formatter, right click on the source code or folder in 
    Project Explorer and choose Source -> Format

[reference-id-for-eclipse-cpp-google-style]: https://raw.githubusercontent.com/google/styleguide/gh-pages/eclipse-cpp-google-style.xml

- Git

    It is possible to manage version control through Eclipse and the git plugin, but it typically requires creating another project. If you're interested in this, try it out yourself and contact me on Canvas.

## <a name="notes"></a> Discussion Notes

For this assignment we conducted two discussion meetings. First, before fully implementing part1, regarding how the project should be developed. Second, after Part2, regarding what kind of changes are needed to be done. 

First discussion meeting took place on 22th September (Saturday) between 5:30 pm to 6:30 pm at Mckeldin library. In this meeting, we covered the concepts regarding pair programming, decided the drivers and navigators for part 1 and discussed what kind of unit test can be developed for a generalized system. Few doubts regarding the directory structure, git commiting & git pull request, Travis & Coveralls badges and regarding UML diagrams were also discussed.

Second discussion meeting took place on 24th September (Monday) between 10:00 pm to 12:00 am at Mckeldin library. In this meeting, we firstly resolved issues regrading part 1 and then completed part 2. After implementing correct compute function of both the pairs, pull request where generated and tested in travis before finally merging it into the repository. After mergeing it, we discussed following topics and listed out further improvements in TODO section.

>Note: Discussion Notes and TODO were added after mergeing the pull request, because we wanted to make sure that we aren't facing any issuses regarding Travis and Coveralls badges.

**Discussion Topics:**
- **C++:** Discussed improvements regarding code developed in part 1 and part 2, mostly how we can use inline contructors and auto & decltype keyword to corporate C++11 syntax in our code. Along with that, file naming conventions and necessary improvements regarding C++ coding were suggested.
- **UML Diagram & Object oriented class definition:** Discussed how class implementation can be done in a better way, mainly regarding how private member variables in a particular class can be selected. Suggestions regarding PID algorithm variables like previous_error_, accumulation_error_ should be class variables instead of local class method variables to retain their values. This can facilitate easy integration with other class modules and control loop in main function.
- **PID Controller Implementation:** Discussed the ways in which both pairs have implemented PID controller.
- **Test cases:** Discussed various test cases that can be developed for PID Controller and mentioned the new test cases that can be incorported within the program in TODO list. Also, discussed the difference between EXPECT & ASSERT macros and made suggestions of incorporating it in the test cases. Furthermore, suggestion of incorporating new test cases listed in Test Cases section were discussed to implement in our repository.

## <a name="todo"></a> TODO

- Issuses regarding Coveralls badge was to be resolved. 
>(Note: Apart from modification in CMakeLists.txt to include the "include" directory no other modifications were needed. The issue was with browser cache memory.)
- Incorporating coverage test case for PID controller.

