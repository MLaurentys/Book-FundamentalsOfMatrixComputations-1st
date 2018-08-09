#include "P_1_1_1.h"

// A = n by n matrix, x = real belonging to list, I identity
//  ( | a_11 a_12 | _ | x_1  0  | ) . ( | a_11 a_12 | _ | x_2  0  | ) .  (...) . ( | a_11 a_12 | _ | x_r  0  | )
//  ( | a_21 a_22 |   |  0  x_1 | )   ( | a_21 a_22 |   |  0  x_2 | )            ( | a_21 a_22 |   |  0  x_r | )
//HINT: Multiply from right to left (M_1 . (M_2 . (M_3 . M_4)))

std::vector<float> P_1_1_1::Solution(std::vector<std::vector<float>>& matrix, const std::vector<float>& list) {
    //assume matrix[i].lenght() = matrix[j].lenght()  { for any i,j in [0, length] }
    std::vector<float> column;
    std::vector<float> auxColumn;

    int n = matrix.size();
    int r = list.size();

    column = MyMath::getColumn(matrix, 0);
    column[0] -= list[r - 1]; // gets first column of (right most matrix - x_r.I)
    auxColumn = column;

    for (int j = r - 2; j >= 0; --j) {  // amount of times to multiply
        MyMath::addIndentity(matrix, -list[j]);
        for (int i = 0; i < n; ++i) {  // how many rows in the column
            auxColumn[i] = MyMath::dotProduct(column, matrix[i]);
        }
        MyMath::addIndentity(matrix, +list[j]);
        column = auxColumn;
    }
    return column;
}
bool P_1_1_1::Test1() {
    std::vector<std::vector<float>> testMatrix = { { 1, 2, 3 },{ 4, 5, 6 },{ 7, 8, 9 } };
    std::vector<float> testArray = { 3, 4, 5, -6, -7, -8 };
    std::vector<float> answer = { 2418936, 5531856, 8624616 };
    return Solution(testMatrix, testArray) == answer;
}

bool P_1_1_1::Test2() {
    std::vector<std::vector<float>> testMatrix = { { 1,0 },{ 0,1 } };
    std::vector<float> testArray = { 1, 2, -3 };
    std::vector<float> answer = { 0, 0 };
    return Solution(testMatrix, testArray) == answer;
}

bool P_1_1_1::RunTests() {
    return Test1() && Test2();
}
