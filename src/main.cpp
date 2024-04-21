// Copyright 2022 UNN-IASR
#include <iostream>
#include "fun.h"

int main() {
    const char* cstr = "Hello, world!";
    std::cout << "faStr1: " << faStr1(cstr) << std::endl<< std::endl;
    std::cout << "faStr2: " << faStr2(cstr) << std::endl<< std::endl;
    std::cout << "faStr3: " << faStr3(cstr) << std::endl<< std::endl;
    return 0;
}
