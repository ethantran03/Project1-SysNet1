#include <iostream>
#include <unistd.h>    // for fork, execvp
#include <sys/wait.h>  // for wait, waitpid
#include <fcntl.h>     // for open
#include <cstring>     // for strtok, strcmp
#include "param.hpp"   // Param class and its methods
#include "parse.hpp"   // parseInput() function

#define MAX_INPUT_SIZE 1024

// Function to execute the parsed command
void executeCommand(Param& param) {
    pid_t pid = fork();  // Create a new process

    if (pid == 0) {  // Child process
        // Handle input redirection if needed
        if (param.getInputRedirect()) {
            int input_fd = open(param.getInputRedirect(), O_RDONLY);
            if (input_fd < 0) {
                std::cerr << "Error: Unable to open input file.\n";
                exit(1);
            }
            dup2(input_fd, STDIN_FILENO);  // Redirect stdin to the input file
            close(input_fd);
        }

        // Handle output redirection if needed
        if (param.getOutputRedirect()) {
            int output_fd = open(param.getOutputRedirect(), O_WRONLY | O_CREAT | O_TRUNC, 0644);
            if (output_fd < 0) {
                std::cerr << "Error: Unable to open output file.\n";
                exit(1);
            }
            dup2(output_fd, STDOUT_FILENO);  // Redirect stdout to the output file
            close(output_fd);
        }

        // Execute the command using execvp
        if (execvp(param.getArgumentVector()[0], param.getArgumentVector()) == -1) {
            perror("Error executing command");
            exit(1);  // Terminate child process if execvp fails
        }

    } else if (pid > 0) {  // Parent process
        if (!param.isBackground()) {
            // Foreground process: wait for it to finish
            waitpid(pid, NULL, 0);
        } else {
            // Background process: print PID and continue without waiting
            std::cout << "Process running in background with PID: " << pid << std::endl;
        }

    } else {
        // Fork failed
        perror("Fork failed");
    }
}

int main(int argc, char* argv[]) {
    bool debug = false;

    // Check if debug mode is enabled
    if (argc > 1 && strcmp(argv[1], "-Debug") == 0) {
        debug = true;
    }

    std::string input;
    Param param;

    while (true) {
        // Periodically check for terminated background processes
        waitpid(-1, NULL, WNOHANG);

        // Display the shell prompt
        std::cout << "$$$ ";
        std::getline(std::cin, input);

        // If "exit" command is entered, exit the shell
        if (input == "exit") {
            // Ensure all background processes are terminated before exiting
            while (waitpid(-1, NULL, WNOHANG) > 0);
            break;
        }

        // Parse the input into the Param structure
        parseInput(input.c_str(), param);

        // If in debug mode, print the parsed parameters
        if (debug) {
            param.printParams();
        }

        // Execute the command if valid
        if (param.getArgumentCount() > 0) {
            executeCommand(param);
        }
    }

    return 0;
}
