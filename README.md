# Matrix Operation Library
A custom C++ utility library for fundamental **Matrix Operations**.  
이 라이브러리는 **nxn 행렬의 행렬식(Determinant)을 계산**하며, 행렬식이 0이 아닐 경우 **역행렬(Inverse Matrix)을 계산**하는 기능을 제공합니다.  
본 프로젝트는 정적/동적 링킹 및 런타임 로딩(dlopen) 시연을 목적으로 합니다.
---
🧠 코드 라이브러리 설명
라이브러리는 **Determinant.cpp**와 Inverse.cpp 파일로 구성되어 있으며, nxn 행렬을 인자로 받아 행렬 관련 연산을 수행합니다.

행렬식 (Determinant) 계산:
1x1 또는 2x2 행렬: 간단한 공식을 이용하여 행렬식을 즉시 계산합니다.
3x3 이상의 행렬: 백트래킹(Back-tracking) 기법을 사용하여 행렬식을 재귀적으로 계산합니다.

역행렬 (Inverse Matrix) 계산:
행렬식이 0인 경우에는 역행렬이 존재하지 않으므로 계산을 수행하지 않습니다.
행렬식이 0이 아닐 경우에만 역행렬을 계산하여 리턴합니다.

---
### 레포지토리 구조  
```
Make_lib/  
│  
├── src/  
│   ├── Determinant.h  
│   ├── Determinant.cpp  
│   ├── Inverse.h  
│   ├── Inverse.cpp  
│  
├── lib/  
│   ├── libmatrix.a        # Static Library  
│   ├── libmatrix.so       # Shared Library (Dynamic)  
│  
├── test/  
│   ├── main.cpp           # Statically linked example  
│   ├── main_runtime.cpp   # Dynamically linked example (runtime load)  
│  
└── README.md  
```
### 코드 설명  

### Instructions to build and test the library. 
1. 동적 라이브러리를 위해 -fpic옵션을 줘서 object파일 생성
 - g++ -c -fPIC src/Determinant.cpp -o Determinant.o
 - g++ -c -fPIC src/Inverse.cpp -o Inverse.o
2. 아카이브 파일 생성 (정적 라이브러리)  
- ar rcs lib/libmatrix.a Determinant.o Inverse.o
3. so파일 생성 (동적 라이브러리)
   - g++ -shared -o lib/libmatrix.so Determinant.o Inverse.o
4. 정적 링킹하여 실행 파일 생성 후 실행
- g++ test/main.cpp -Llib -lmatrix -I./src -o main_static
- ./main_static
5. 동적 링킹하여 실행 파일 생성 후 실행    
- g++ test/main_runtime.cpp -Llib -lmatrix -I./src -o main_dynamic
- LD_LIBRARY_PATH=./lib ./main_dynamic
6. Run-Time 링킹하여 실행 파일 생성 후 실행
  - g++ test/main_runtime.cpp -o main_runtime -ldl -I./src
  - ./main_runtime

 <p>
  <img width=70% height="815" alt="Image" src="https://github.com/user-attachments/assets/0c1bbb2a-1901-4058-b221-4c02ff23fc13" />
 </p>
