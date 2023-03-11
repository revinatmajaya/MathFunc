#include <iostream>
#include "./headers/mathFunc.h"

int main(){
    DummyVar x('x');
    DummyVar y('y');

    std::cout << "available variables are: " << std::endl;
    // DummyVar::availableNames->print();

    MathFunc f('f', &x);
    std::cout << "evaluate f for a given x: " << f.evaluate(5) << std::endl;
    f.print();

    MathFunc g('g', &x, 5);
    g.print();

    MathFunc h = g / &f;
    std::cout << "evaulate h for a given x: " << h.evaluate(5) << std::endl;

    

    return 0;
}
