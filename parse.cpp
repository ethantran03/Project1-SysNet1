#include "parse.hpp"
#include <cstring>
#include <cctype>
#include <cstdlib>
#include <iostream>

void parseInput(const char *input, Param &param) {
    char buffer[1024];
    strcpy(buffer, input);

    char *token = strtok(buffer, " \t\n");
    while (token != nullptr) {
        if (strcmp(token, "<") == 0) {
            token = strtok(nullptr, " \t\n");
            if (token) {
                param.setInputRedirect(token);
            }
        } else if (strcmp(token, ">") == 0) {
            token = strtok(nullptr, " \t\n");
            if (token) {
                param.setOutputRedirect(token);
            }
        } else if (strcmp(token, "&") == 0) {
            param.setBackground(1);
        } else {
            param.addArgument(token);
        }
        token = strtok(nullptr, " \t\n");
    }
}
