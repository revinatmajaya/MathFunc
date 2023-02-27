// mathFunc.cpp header file
#include <iostream>
#include "./../linkedList.cpp"

// an abstract class for now, i don't know what to do with this
class MathObj{
    public:
    virtual int evaluate(const int x) = 0;
    virtual void print() = 0;
};

// this will only handle one variable for now
// class MathFunc : MathObj{
//     private:
//     List<MathFunc> mathFunctions;
//     int coefficient;
//     int power;

//     public:
//     MathFunc(DummyVar* var);
//     MathFunc(DummyVar* var, const int coefficient);
//     MathFunc(DummyVar* var, const int coefficient, const int power);
//     int evaluate(const int x);
// };

// variable used in the function
// may be used over and over again in more than one function.
class DummyVar : MathObj{
    private:
    int coefficient;
    int power;
    char name;

    public:
    // static List<char> usedNames;
    // DummyVar();
    static List<char>* availableNames;
    DummyVar(const char name);
    DummyVar(const char name, const int coefficient, const int power);
    
    int evaluate(const int x);
    void print();
};

List<char>* DummyVar::availableNames = new List<char>();