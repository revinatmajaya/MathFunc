// mathFunc.cpp header file
#include <iostream>
#include "./linkedList.h"

// as per name, this is a math object
class MathObj {
    public:
    
};

class MathFunc : public MathObj{
    public:
    List<MathObj> mathObjects;
    int coefficient = 1;

    int evaluate(const int x);
    void print();

};
