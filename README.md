레포지토리 구조
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

