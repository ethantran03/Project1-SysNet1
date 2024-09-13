// param.cpp
#include "param.hpp"
#include <iostream>
#include <cstring>
#include <cstdlib>

Param::Param() : inputRedirect(NULL), outputRedirect(NULL), background(0), argumentCount(0) {
    memset(argumentVector, 0, sizeof(argumentVector));
}

Param::~Param() {
    if (inputRedirect) free(inputRedirect);
    if (outputRedirect) free(outputRedirect);
    for (int i = 0; i < argumentCount; ++i) {
        free(argumentVector[i]);
    }
}

void Param::printParams() const {
    std::cout << "Input Redirect: " << (inputRedirect ? inputRedirect : "None") << std::endl;
    std::cout << "Output Redirect: " << (outputRedirect ? outputRedirect : "None") << std::endl;
    std::cout << "Background: " << background << std::endl;
    std::cout << "Arguments: ";
    for (int i = 0; i < argumentCount; ++i) {
        std::cout << argumentVector[i] << " ";
    }
    std::cout << std::endl;
}
