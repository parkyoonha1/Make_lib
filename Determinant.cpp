#include <vector>
#include"Determinant.h"

int CalculateDeterminant(const std::vector<std::vector<double>>& matrix){
	int size = matrix.size();
	if(size == 1){
		return matrix[0][0];
	}
	if(size == 2){
		return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
	}
	int determinant = 0;
	for(int p = 0; p < size; p++){
		std::vector<std::vector<double>> subMatrix;
		for(int i = 1; i < size; i++){
			std::vector<double> row;
			for(int j = 0; j < size; j++){
				if(j != p){
					row.push_back(matrix[i][j]);
				}
			}
			subMatrix.push_back(row);
		}
		determinant += matrix[0][p] * CalculateDeterminant(subMatrix) * (p % 2 == 0 ? 1 : -1);
	}
	return determinant;
}
