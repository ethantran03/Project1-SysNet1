# Project1-SysNet1

## Purpose

A project that implement a shell with basic abilites to parse user commands, command execution, input/output redirection, and background exection.

### Features
- Supports commands like "ls", "cat", and etc.
- Handles input redirection with "<" and output redirection with ">"
- Can run processes in the backgroun ending a line with "&"
- Runs debug mode to print parsed commands "myshell -Debug"

#### How to run the file
- Type "make" in the terminal to startup the shell
- Can run debug mode in the shell with "./myshell -Debug"
- Run the shell without debug with "./myshell"
- Can exit the shell by typing "exit" (will wait for background processes to finish before exiting)
