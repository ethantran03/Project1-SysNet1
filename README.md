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

#### Some command to use to test the shell
- Can use the command "ls -1" to look at the files inside of the shell
- Use the command "ls -1 > outputfile.txt" to create a file in the shell call "outputfile.txt"
- Can use the command "./slow &" to run process in the background and return the pid of the process
- Can use the function "cat" following "<" and a file you want to show to shows the .cpp file in the shell
- If you run the command "./myshell -Debug" you can run it in debuging mode and next push the command "ls -1" it'll show you the argument amount and to see if there is a background running
