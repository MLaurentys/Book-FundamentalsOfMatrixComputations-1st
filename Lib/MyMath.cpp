#include "MyMath.h"

namespace MyMath {
    void addIndentity(std::vector<std::vector<float>>& matrix, float scalar) {
        for (int i = 0; i < matrix.size(); i++) {
            matrix[i][i] += scalar;
        }
    }
    std::vector<float> getColumn(const std::vector<std::vector<float>>& matrix, int index) {
        std::vector<float> column;
        for (int i = 0; i < matrix.size(); ++i) {
            column.push_back(matrix[i][index]);
        }
        return column;
    }
  std::tuple<float,float> dotProduct(std::vector<float> vector1, std::vector<float> vector2) {
        //assume vector1.size() = vector2.size()
        float sum = 0;
	float flopCount = 0;
        for (int i = 0; i < vector1.size(); ++i) {
            sum += vector1[i] * vector2[i];
	    flopCount += 2; //1 multiplication + 1 sum
        }
        return std::make_tuple(sum,flopCount);
    }

    float power(float number, float exponent) {
        //TO DO: fast exponentiation function
        for (int i = 1; i < exponent; ++i){
            number *= number;
        }
        return number;
    }
    void scalarTimesVector(std::vector<float>& vector, float scalar) {
        for (int i = 0; i < vector.size(); ++i) {
            vector[i] *= scalar;
        }
    }
    std::vector<std::vector<float>> outerProduct(std::vector<float>& vec1, std::vector<float>& vec2) {
        std::vector<std::vector<float>> retMatrix;
        for (int i = 0; i < vec1.size(); i++)
        {
            retMatrix.push_back(std::vector<float>());
            for (int j = 0; j < vec2.size(); j++)
            {
                retMatrix[i].push_back(vec1[i] * vec2[j]);
            }
        }
        return retMatrix;
    }
	std::tuple<int, std::vector<std::vector<float>> multiplyMatrix(std::vector<std::vector<float>> matrix1, std::vector<std::vector<float>> matrix2){
	  std::vector<std::vector<float>> retMatrix;
	  int flopCount = 0;
	  float cellAux;
	  float flopAux;
	  for(int i = 0; i < matrix1.size(); ++i){
	    retMatrix.push_back(std::vector<float>);
	    for(int j = 0; j < matrix1[0].size(); ++j){
	      std::tie(cellAux, flopAux) =  MyMath::dotProduct(matrix1[i], MyMath::getColumn(matrix2, j));
	      retMatrix[i][j].push_back(cellAux);
	      flopCount += flopAux;
	    }
      }
    }
}
