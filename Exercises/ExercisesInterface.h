#pragma once
#ifndef EXERCISESINTERFACE_H_
#define EXERCISESINTERFACE_H_
#include "../Lib/MyMath.h"
#include <vector>
class ExercisesInterface {
protected:
    virtual bool Test1() = 0; // Forces at least one test
public:
    virtual ~ExercisesInterface() {}

    virtual bool RunTests() = 0;
};
#endif