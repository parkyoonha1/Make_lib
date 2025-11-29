#include <iostream>
#include <vector>
#include <dlfcn.h>
#include <cstdlib> // 오타 수정: inclide -> include, cstdlib.h -> cstdlib
#include "Determinant.h"
#include "Inverse.h"

using namespace std;

// 코드 가독성을 위해 타입 정의
using MatrixType = vector<vector<double>>;

int main() {
    void* handle;
    
    handle = dlopen("./libmatrix.so", RTLD_LAZY);
    if (!handle) {
        fprintf(stderr, "%s\n", dlerror());
        exit(1);
    }

    // dlsym 에러 체크를 위한 초기화
    dlerror(); 

    while (1) {
        cout << "Enter the size of square Matrix(0=exit): ";
        int n;
        cin >> n;
        if (n == 0) break;

        MatrixType Matrix(n, vector<double>(n, 0));
        
        for (int i = 0; i < n; i++) {
            cout << i << " row: ";
            for (int j = 0; j < n; j++) {
                cin >> Matrix[i][j];
            }
        }

        // 2. CalculateDeterminant 함수 포인터 가져오기 및 캐스팅
        // C++에서는 dlsym의 리턴값(void*)을 함수 포인터로 명시적으로 캐스팅해야 합니다.
        double (*CalculateDeterminant)(MatrixType);
        CalculateDeterminant = (double (*)(MatrixType))dlsym(handle, "CalculateDeterminant");

        const char* dlsym_error = dlerror();
        if (dlsym_error) {
            fprintf(stderr, "Cannot load symbol 'CalculateDeterminant': %s\n", dlsym_error);
            dlclose(handle);
            exit(1);
        }

        double det = CalculateDeterminant(Matrix);
        cout << "Determinant of Matrix : " << det << "\n";

        if (det != 0) {
            // 3. InverseMatrix 함수 포인터 가져오기 (매우 중요: 원본 코드에서 누락됨)
            // 원본 코드에서는 포인터 선언만 하고 dlsym으로 연결하지 않아 충돌 발생함
            MatrixType (*InverseMatrix)(MatrixType);
            InverseMatrix = (MatrixType (*)(MatrixType))dlsym(handle, "InverseMatrix");
            
            dlsym_error = dlerror();
            if (dlsym_error) {
                fprintf(stderr, "Cannot load symbol 'InverseMatrix': %s\n", dlsym_error);
                dlclose(handle);
                exit(1);
            }

            // 함수 실행
            MatrixType inverse = InverseMatrix(Matrix);
            
            cout << "Inverse Matrix : \n";
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    cout << inverse[i][j] << " ";
                }
                cout << "\n";
            }
        }
    }

    // 4. 핸들 닫기
    dlclose(handle);
    return 0;
}
