### 개발환경

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
