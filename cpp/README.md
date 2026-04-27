# C++ version of Gilded Rose refactoring kata

## Introduction
The C++ version of the Gilded Rose refactoring kata is available in four variants using different test frameworks:

* Catch2 test framework
  1. Traditional unit test with the [Catch2](https://github.com/catchorg/Catch2) test framework in the `test/cpp_catch2_unittest` folder.
  2. [Approval tests](https://github.com/approvals/ApprovalTests.cpp) with the [Catch2](https://github.com/catchorg/Catch2) test framework in the `test/cpp_catch2_approvaltest` folder.
* GoogleTest framework
  1. Traditional unit test with the [GoogleTest](https://github.com/google/googletest) test framework in the `test/cpp_googletest_unittest` folder.
  2. [Approval tests](https://github.com/approvals/ApprovalTests.cpp) with the [GoogleTest](https://github.com/google/googletest) test framework in the `test/cpp_googletest_approvaltest` folder.

The `GildedRose.cc` file, i.e. the code under test, is identical in all four variants.

## Prerequisites

* CMake version &GreaterEqual; 3.13
* C++ compiler that supports C++14 

## How to build and run tests in a terminal

### Build tests

    $ cd ${GIT_FOLDER}/GildedRose-Refactoring-Kata/cpp
    $ mkdir build
    $ cd build
    $ cmake ..
    $ cmake --build .

The following test specific options for building with CMake are available.

* `BUILD_APPROVAL_TESTS_WITH_CATCH2:BOOL=ON`
This option builds the approval tests with the Catch2 test framework.
* `BUILD_UNIT_TESTS_WITH_CATCH2:BOOL=ON`
This option builds the unit tests with the Catch2 test framework.
* `BUILD_APPROVAL_TESTS_WITH_GTEST:BOOL=ON`
This option builds the approval tests with the GoogleTest test framework.
* `BUILD_UNIT_TESTS_WITH_GTEST:BOOL=ON`
This option builds the unit tests with the GoogleTest test framework.

For example, run the CMake configuration `cmake -DBUILD_APPROVAL_TESTS_WITH_CATCH2=OFF -DBUILD_UNIT_TESTS_WITH_CATCH2=OFF ..` to disable the Catch2 based tests.

### Show available tests

    $ cd ${GIT_FOLDER}/GildedRose-Refactoring-Kata/cpp/build
    $ ctest -N
    Test project ${GIT_FOLDER}/GildedRose-Refactoring-Kata/cpp/build
      Test #1: GildedRoseCatch2ApprovalTests
      Test #2: GildedRoseCatch2UnitTests
      Test #3: GildedRoseGoogletestApprovalTests
      Test #4: GildedRoseGoogletestUnitTests

### Run all tests

    $ ctest

### Run all tests with verbose output

    $ ctest -VV

### Run a specific test with verbose output

    $ ctest -VV --tests-regex Catch2Approval
