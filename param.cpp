#include "param.hpp"
#include <iostream>
#include <cstring>

Param::Param() {
    inputRedirect = nullptr;
    outputRedirect = nullptr;
    background = 0;
    argumentCount = 0;
    // Initialize argumentVector to nullptr to avoid garbage values
    for (int i = 0; i < MAXARGS; ++i) {
        argumentVector[i] = nullptr;
    }
}

Param::~Param() {
    // Free dynamically allocated memory
    for (int i = 0; i < argumentCount; ++i) {
        delete[] argumentVector[i];
    }
    if (inputRedirect) {
        delete[] inputRedirect;
    }
    if (outputRedirect) {
        delete[] outputRedirect;
    }
}

void Param::setInputRedirect(const char* input) {
    if (inputRedirect) {
        delete[] inputRedirect;
    }
    inputRedirect = new char[strlen(input) + 1];
    strcpy(inputRedirect, input);
}

void Param::setOutputRedirect(const char* output) {
    if (outputRedirect) {
        delete[] outputRedirect;
    }
    outputRedirect = new char[strlen(output) + 1];
    strcpy(outputRedirect, output);
}

void Param::setBackground(bool bg) {
    background = bg ? 1 : 0;
}

void Param::addArgument(const char* arg) {
    if (argumentCount < MAXARGS) {
        argumentVector[argumentCount] = new char[strlen(arg) + 1];
        strcpy(argumentVector[argumentCount], arg);
        ++argumentCount;
    } else {
        std::cerr << "Error: Too many arguments (max " << MAXARGS << ")\n";
    }
}

char* Param::getInputRedirect() const {
    return inputRedirect;
}

char* Param::getOutputRedirect() const {
    return outputRedirect;
}

int Param::isBackground() const {
    return background;
}

int Param::getArgumentCount() const {
    return argumentCount;
}

char** Param::getArgumentVector() {
    return argumentVector;
}

void Param::clear() {
    for (int i = 0; i < argumentCount; ++i) {
        delete[] argumentVector[i];
        argumentVector[i] = nullptr;
    }
    argumentCount = 0;

    if (inputRedirect) {
        delete[] inputRedirect;
        inputRedirect = nullptr;
    }
    if (outputRedirect) {
        delete[] outputRedirect;
        outputRedirect = nullptr;
    }

    background = 0;
}

void Param::printParams() const {
    std::cout << "Arguments (" << argumentCount << "):\n";
    for (int i = 0; i < argumentCount; ++i) {
        std::cout << "arg[" << i << "] = " << argumentVector[i] << std::endl;
    }

    if (inputRedirect) {
        std::cout << "Input redirect: " << inputRedirect << std::endl;
    }
    if (outputRedirect) {
        std::cout << "Output redirect: " << outputRedirect << std::endl;
    }
    std::cout << "Background: " << (background ? "true" : "false") << std::endl;
}
