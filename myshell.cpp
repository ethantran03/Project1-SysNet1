// myshell.cpp
#include "param.hpp"
#include "parse.hpp"
#include <iostream>
#include <cstring>

bool debugMode = false;

int main(int argc, char* argv[]) {
    // Check for -Debug flag
    if (argc > 1 && std::strcmp(argv[1], "-Debug") == 0) {
        debugMode = true;
    }

    while (true) {
        // Display prompt
        std::cout << "$$$ ";

        // Read input
        std::string input;
        std::getline(std::cin, input);

        // Exit on "exit"
        if (input == "exit") break;

        // Parse the input
        Param param;
        parseInput(input.c_str(), param);

        // Print parameters if in debug mode
        if (debugMode) {
            param.printParams();
        }
    }

    return 0;
}
