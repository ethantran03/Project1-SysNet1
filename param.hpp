// param.hpp
#ifndef PARAM_HPP
#define PARAM_HPP

#define MAXARGS 32

class Param
{
private:
    char *inputRedirect;    // File name for input redirection or NULL
    char *outputRedirect;   // File name for output redirection or NULL
    int background;         // 0 for foreground, 1 for background
    int argumentCount;      // Number of tokens in argument vector
    char *argumentVector[MAXARGS]; // Array of tokens (arguments)

public:
    // Constructor
    Param();

    // Destructor
    ~Param();

    // Print the parameters for debugging
    void printParams() const;

    // Getters and setters
    const char* getInputRedirect() const;
    void setInputRedirect(const char* input);

    const char* getOutputRedirect() const;
    void setOutputRedirect(const char* output);

    int getBackground() const;
    void setBackground(int bg);

    int getArgumentCount() const;
    void setArgumentCount(int count);

    const char* getArgument(int index) const;
    void setArgument(int index, const char* arg);
};

#endif // PARAM_HPP
