#include "parse.hpp"
#include <cstring>
#include <iostream>

void parseInput(const char* input, Param& param) {
    param.clear();  // Reset the parameters before parsing

    const char* delim = " \t\n";  // Delimiters: spaces, tabs, newlines
    char* token = strtok(const_cast<char*>(input), delim);

    while (token != nullptr) {
        if (strcmp(token, "<") == 0) {
            // Input redirection
            token = strtok(nullptr, delim);
            if (token != nullptr) {
                param.setInputRedirect(token);
            } else {
                std::cerr << "Error: No input file specified.\n";
            }
        } else if (strcmp(token, ">") == 0) {
            // Output redirection
            token = strtok(nullptr, delim);
            if (token != nullptr) {
                param.setOutputRedirect(token);
            } else {
                std::cerr << "Error: No output file specified.\n";
            }
        } else if (strcmp(token, "&") == 0) {
            // Background execution
            param.setBackground(true);
        } else {
            // Regular argument
            param.addArgument(token);
        }

        // Get the next token
        token = strtok(nullptr, delim);
    }

    // Ensure the argument vector ends with a NULL pointer (required by execvp)
    param.getArgumentVector()[param.getArgumentCount()] = nullptr;
}
