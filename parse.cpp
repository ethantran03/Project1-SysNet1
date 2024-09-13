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
            param.setInputRedirect(token.substr(1).c_str());
        } else if (token[0] == '>') {
            param.setOutputRedirect(token.substr(1).c_str());
        } else if (token == "&") {
            param.setBackground(1);
        } else {
            if (argCount < MAXARGS) {
                param.setArgument(argCount, token.c_str());
                argCount++;
            }
        }
    }

    param.setArgumentCount(argCount);
}
