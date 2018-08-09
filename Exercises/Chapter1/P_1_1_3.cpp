#include "P_1_1_3.h"

// (x . yT) = matrix M
// However, M . M is O(n^3)
// Idea: (x . yT)^k = xyT . xyT .... = x(yT . x)^(k-1)yT ("yT . x" is an inner product) 
std::vector<std::vector<float>> P_1_1_3::Solution(std::vector<float>& vector1, std::vector<float>& vector2, int exponent) {
    float innerProduct = MyMath::power(MyMath::dotProduct(vector1, vector2), exponent - 1);
    MyMath::scalarTimesVector(vector1, exponent - 1);
    return MyMath::outerProduct(vector1, vector2);
}

bool P_1_1_3::Test1() {
    std::vector<float> vec1 = {1.0f, 0, -3};
    std::vector<float> vec2 = {2.5f, -1, 0};
    float exponent = 3;
    std::vector<std::vector<float>> answer = { {15.625f, -6.25, 0}, {0, 0, 0}, {-48.875f, 18.75f, 0} };

    return Solution(vec1, vec2, exponent) == answer;
}
bool P_1_1_3::RunTests() {
    return Test1();
}
