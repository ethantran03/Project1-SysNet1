// parse.cpp
#include "parse.hpp"
#include "param.hpp"
#include <cstring>
#include <cctype>
#include <sstream>

void parseInput(const char* input, Param& param) {
    // Tokenize input string
    std::istringstream iss(input);
    std::string token;
    int argCount = 0;

    while (iss >> token) {
        if (token[0] == '<') {
            param.inputRedirect = strdup(token.substr(1).c_str());
        } else if (token[0] == '>') {
            param.outputRedirect = strdup(token.substr(1).c_str());
        } else if (token == "&") {
            param.background = 1;
        } else {
            if (argCount < MAXARGS) {
                param.argumentVector[argCount] = strdup(token.c_str());
                argCount++;
            }
        }
    }

    param.argumentCount = argCount;
}
