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

const char* Param::getInputRedirect() const { return inputRedirect; }
void Param::setInputRedirect(const char* input) { inputRedirect = strdup(input); }

const char* Param::getOutputRedirect() const { return outputRedirect; }
void Param::setOutputRedirect(const char* output) { outputRedirect = strdup(output); }

int Param::getBackground() const { return background; }
void Param::setBackground(int bg) { background = bg; }

int Param::getArgumentCount() const { return argumentCount; }
void Param::setArgumentCount(int count) { argumentCount = count; }

const char* Param::getArgument(int index) const { return argumentVector[index]; }
void Param::setArgument(int index, const char* arg) { argumentVector[index] = strdup(arg); }
