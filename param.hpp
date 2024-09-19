#ifndef PARAM_HPP
#define PARAM_HPP

#define MAXARGS 32

class Param {
private:
    char* inputRedirect;       // file name or NULL
    char* outputRedirect;      // file name or NULL
    int background;            // 0 (false) or 1 (true)
    int argumentCount;         // number of tokens in argument vector
    char* argumentVector[MAXARGS];  // array of argument strings

public:
    Param();                   // Constructor
    ~Param();                  // Destructor
    void printParams() const;  // Debug print method
    void setInputRedirect(const char* input);  // Set input redirection file
    void setOutputRedirect(const char* output);  // Set output redirection file
    void setBackground(bool bg);   // Set background flag
    void addArgument(const char* arg);  // Add argument to argumentVector
    void clear();                // Clear all parameters for next command

    char* getInputRedirect() const;
    char* getOutputRedirect() const;
    int isBackground() const;
    int getArgumentCount() const;
    char** getArgumentVector();
};

#endif
