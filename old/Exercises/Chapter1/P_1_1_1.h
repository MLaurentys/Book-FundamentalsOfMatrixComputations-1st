//P_1_1_1 Matheus T. de Laurentys

#pragma once
#ifndef P_1_1_1__H_
#define P_1_1_1__H_

#include "../ExercisesInterface.h"

class P_1_1_1 : ExercisesInterface{
protected:
    bool Test1();
    bool Test2();
public:
    std::vector<float> Solution(std::vector<std::vector<float>>& matrix, const std::vector<float>& list);
    bool RunTests();
};

#endif

