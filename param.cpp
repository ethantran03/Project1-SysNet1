#include "param.hpp"
#include <iostream>
#include <cstring>
#include <cstdlib>

Param::Param() : inputRedirect(nullptr), outputRedirect(nullptr), background(0), argumentCount(0) {
    for (int i = 0; i < MAXARGS; ++i) {
        argumentVector[i] = nullptr;
    }
}

Param::~Param() {
    delete[] inputRedirect;
    delete[] outputRedirect;
    for (int i = 0; i < argumentCount; ++i) {
        delete[] argumentVector[i];
    }
}

void Param::setInputRedirect(const char *filename) {
    delete[] inputRedirect;
    inputRedirect = strdup(filename);
}

void Param::setOutputRedirect(const char *filename) {
    delete[] outputRedirect;
    outputRedirect = strdup(filename);
}

void Param::setBackground(int flag) {
    background = flag;
}

void Param::addArgument(const char *arg) {
    if (argumentCount < MAXARGS) {
        argumentVector[argumentCount++] = strdup(arg);
    }
}

void Param::printParams() const {
    std::cout << "Input Redirect: " << (inputRedirect ? inputRedirect : "None") << std::endl;
    std::cout << "Output Redirect: " << (outputRedirect ? outputRedirect : "None") << std::endl;
    std::cout << "Background: " << (background ? "Yes" : "No") << std::endl;
    std::cout << "Arguments:" << std::endl;
    for (int i = 0; i < argumentCount; ++i) {
        std::cout << "  " << argumentVector[i] << std::endl;
    }
}
