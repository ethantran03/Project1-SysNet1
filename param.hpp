#ifndef PARAM_HPP
#define PARAM_HPP

#define MAXARGS 32

class Param {
private:
    char *inputRedirect;  // file name or NULL
    char *outputRedirect; // file name or NULL
    int background;       // either 0 (false) or 1 (true)
    int argumentCount;    // number of tokens in argument vector
    char *argumentVector[MAXARGS]; // array of strings

public:
    Param();
    ~Param();

    void setInputRedirect(const char *filename);
    void setOutputRedirect(const char *filename);
    void setBackground(int flag);
    void addArgument(const char *arg);
    void printParams() const;
};

#endif // PARAM_HPP
