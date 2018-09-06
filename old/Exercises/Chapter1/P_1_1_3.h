#pragma once
#ifndef P_1_1_3__H_
#define P_1_1_3__H_

#include "../ExercisesInterface.h"

class P_1_1_3 : ExercisesInterface{
protected:
    bool Test1();
public:
    std::vector<std::vector<float>> Solution(std::vector<float>& vector1, std::vector<float>& vector2, int exponent);
    bool RunTests();
};

#endif
