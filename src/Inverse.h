#ifndef INVERSE_H
#define INVERSE_H

std::vector<std::vector<double>> InverseMatrix(std::vector<std::vector<double>> matrix);

void ERO1(std::vector<std::vector<double>>& matrix, std::vector<std::vector<double>>& inverse, int row1);
void ERO2(std::vector<double>& matrix, std::vector<double>& inverse, double div);
void ERO3(std::vector<std::vector<double>>& matrix, std::vector<std::vector<double>>& inverse, int pivot_row);
void SubtractRows(std::vector<double>& target_row, const std::vector<double>& source_row, double mul);
void swapRows(std::vector<double>& row1, std::vector<double>& row2);
#endif
