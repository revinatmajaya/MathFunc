// mathFunc.cpp header file
#include <iostream>
#include "./../linkedList.cpp"

// variable used in the function
// may be used over and over again in more than one function.
class DummyVar{
    public:
    char name;
    // static List<char>* availableNames;

    DummyVar();
    DummyVar(const char name);
    void setName(const char name){ this->name = name; }
};

// one variable function
class MathFunc{
    public:
    List<MathFunc*>* mathFunctions;
    int coefficient;
    int power;
    char name;
    /*
    0 = +
    1 = -
    2 = *
    3 = /
    */
    int operat;
    DummyVar* var;

    // static List<char>* availableNames;

    MathFunc();
    MathFunc(const char name, DummyVar* var);
    MathFunc(const char name, DummyVar* var, const int coefficient);
    MathFunc(const char name, DummyVar* var, const int coefficient, const int power);

    int evaluate(const int x);
    void print();

    // setter

    void setFuncList(List<MathFunc*> *list){ this->mathFunctions = list; }
    void setName(const char name){ this->name = name; }
    void setVar(DummyVar* var){ this->var = var; }
    void setCoefficient(const int coefficient){ this->coefficient = coefficient; }
    void setPower(const int power){ this->power = power; }
    void setOperator(const int o){ this->operat = o; }

    // template yang bisa generic jumlah
    // void addFunctions()

    // operators
    
    MathFunc operator+(MathFunc* const g);
    MathFunc operator-(MathFunc* const g);
    MathFunc operator*(MathFunc* const g);
    MathFunc operator/(MathFunc* const g);
};
