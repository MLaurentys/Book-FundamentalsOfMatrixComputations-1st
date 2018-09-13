#include <vector>
#include <cmath>
#include <iostream>

#define MINIMUN_VALUE 0.00001

using std::cout;

void printMatrix(std::vector<std::vector<float>> matrix){
std::cout << "_\n";
  for(int i = 0; i < matrix.size(); ++i){
    std::cout << "|";
    for(int j = 0; j < matrix[0].size(); ++j){
      std::cout << matrix[i][j] << " ";
    }
    std::cout << "|";
    std::cout << "\n";
  }
std::cout << "-\n";
}

//matrix is a NxN matrix
//rowInterchanges is a R^N vector initialized with -1
int gaussianWithPartialPivotting(std::vector<std::vector<float>>& matrix, std::vector<int>& rowInterchanges){
  int columnLen = rowInterchanges.size();
  int rowLen = matrix.size();
  cout << "Columns: " << columnLen << '\n';
  for(int i = 0; i< rowLen; ++i){
    //find pivot
    float biggestAbsolute = 0;
    float contender;
    int indexToUse = -1;
    for (int k = i; k < rowLen; ++k){
        if((contender = abs(matrix[k][i])) > biggestAbsolute){
	  biggestAbsolute = contender;
	  indexToUse = k;
      }
    }
    //check if reasonable pivot was found
    if(biggestAbsolute < MINIMUN_VALUE){
      return 1;
    }
    //make row swap and save information
    else{
      //std::cout << "Pivot: M[" << i << "][" << indexToUse << "] = " << biggestAbsolute << "\n";
      rowInterchanges[i] = indexToUse;
      matrix[i].swap(matrix[indexToUse]);
      std::cout << "After row swap: \n";
      printMatrix(matrix);
    }
    //calculate coefficient
    float auxiliary = matrix[i][i];
    
    for(int k = (i + 1); k < columnLen; ++k){
      float multiple = -1*(matrix[k][i]/auxiliary);//-1 to maintain equality \
      //cout << "I + 1 = " << (i+1) <<'\n';
      cout << "Coefficient: " << multiple << '\n';
      matrix[k][i] = multiple; //saves coefficient (matrix L)
      //make the row adjustments
      for(int j = i + 1; j < rowLen; ++j){
	matrix[k][j] += multiple * matrix[i][j];
      }
    }
    printMatrix(matrix);
  }
  return 0;
}
int main(){
  std::vector<std::vector<float>> matrix =
    {
      {2.0f, 10.0f, 8.0f, 8.0f, 6.0f},
      {1.0f, 4.0f, -2.0f, 4.0f, -1.0f},
      {0.0f, 2.0f, 3.0f, 2.0f, 1.0f},
      {3.0f, 8.0f, 3.0f, 10.0f, 9.0f},
      {1.0f, 4.0f, 1.0f, 2.0f, 1.0f}
    };
  std::vector<int> rows(5, -1);
  printMatrix(matrix);
  gaussianWithPartialPivotting(matrix, rows);
  printMatrix(matrix);
  return 0;
}
