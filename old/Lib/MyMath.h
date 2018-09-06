#pragma once
#ifndef MYMATH_H_
#define MYMATH_H_
#include <vector>
#include <tuple>
namespace MyMath {
    extern void addIndentity(std::vector<std::vector<float>>& matrix, float scalar = 1);
    extern std::vector<float> getColumn(const std::vector<std::vector<float>>& matrix, int index);
  extern std::tuple<float, float dotProduct(std::vector<float> vector1, std::vector<float> vector2);
    extern float power(float num, float exponent);
    extern void scalarTimesVector(std::vector<float>& vector, float scalar);
    extern std::vector<std::vector<float>> outerProduct(std::vector<float>& vec1, std::vector<float>& vec2);
    extern std::tuple<int, std::vector<std::vector<float>> multiplyMatrix(
	    std::vector<std::vector<float>> matrix1, std::vector<std::vector<float>> matrix2);
}
#endif
