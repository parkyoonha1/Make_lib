#include <vector>
#include "Inverse.h"

std::vector<std::vector<double>> InverseMatrix(std::vector<std::vector<double>> matrix){
	int n = matrix.size();

	std::vector<std::vector<double>> inverse(n, std::vector<double>(n, 0));
	for (int i{ 0 }; i < n; i++) { //역행렬 초기화
		inverse[i][i] = 1;
	}

	for (int i{ 0 }; i < n; i++) { //역행렬 계산
		double pivot = matrix[i][i];
		if (pivot == 0) {
			ERO1(matrix, inverse, i);
		}
		if (pivot != 1) { //피봇이 1이 아니라 실수배를 곱해줘야 할 떄
			ERO2(matrix[i], inverse[i], pivot);
		}
		//pivot이 1이고 다른 행을 0으로 만들어줌
		ERO3(matrix, inverse, i);

	}
	return inverse;
}

void ERO1(std::vector<std::vector<double>>& matrix, std::vector<std::vector<double>>& inverse, int row){ //pivot이 0일떄 순서 바꾸기
	for (int i{ row+1 }; i < matrix.size(); i++) {
		if (matrix[i][row] != 0) {
			swapRows(matrix[row], matrix[i]);
			swapRows(inverse[row], inverse[i]);
		}
	}
}

void ERO2(std::vector<double>& matrix_row, std::vector<double>& inverse_row, double div){
	if (div == 0.0) return;
	for (int j{ 0 }; j < matrix_row.size(); j++) {
		matrix_row[j] /= div;
		inverse_row[j] /= div;
	}
}


void ERO3(std::vector<std::vector<double>>& matrix, std::vector<std::vector<double>>& inverse, int pivot_row){
	for (int i{ 0 }; i < matrix.size(); i++) {
		if (i == pivot_row) continue;
		double mul = matrix[i][pivot_row] / matrix[pivot_row][pivot_row];
		if (mul != 0) {
			SubtractRows(matrix[i], matrix[pivot_row], mul);
			SubtractRows(inverse[i], inverse[pivot_row], mul);
		}
	}
}
void SubtractRows(std::vector<double>& target_row, const std::vector<double>& source_row, double mul){
	for (int i{ 0 }; i < target_row.size(); i++) {
		target_row[i] -= source_row[i] * mul;
	}
}
void swapRows(std::vector<double>& row1, std::vector<double>& row2){ //row swap
	std::vector<double> temp;
	temp = row1;
	row1 = row2;
	row2 = temp;
}
