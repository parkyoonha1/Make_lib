#include<iostream>
#include<vector>
#include"Determinant.h"
#include"Inverse.h"

using namespace std;

int main(){
  while(1){
    cout<<"Enter the size of square Matrix(0=exit): ";
    int n;
    cin>>n;
    vector<vector<double>> Matrix;
	Matrix.resize(n, vector<double>(n, 0));
    if(n==0) break;
    for(int i{0};i<n;i++){
        cout << i << " row: ";
      for(int j{0};j<n;j++){
        cin>>Matrix[i][j];
      }
    }
    double det = CalculateDeterminant(Matrix);
    cout<<"Determinant of Matrix : "<<det<<"\n";
    if(det!=0){
        vector<vector<double>> inverse = InverseMatrix(Matrix);
		cout << "Inverse Matrix : \n";
        for (int i{ 0 }; i < n; i++) {
            for (int j{ 0 }; j < n; j++) {
                cout << inverse[i][j] << " ";
            }
            cout << "\n";
        }

    }
  }
}
