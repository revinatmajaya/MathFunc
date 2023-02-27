#include "./headers/mathFunc.h"

// DummyVar('x') will make a 1x^1 object
DummyVar::DummyVar(const char name){
    this->name = name;
    this->coefficient = 1;
    this->power = 1;
    DummyVar::availableNames->add(name);
}

DummyVar::DummyVar(const char name, const int coefficient, const int power){
    this->name = name;
    this->coefficient = coefficient;
    this->power = power;
    DummyVar::availableNames->add(name);
}

int DummyVar::evaluate(const int x){
    int result = 1;
    while(this->power--){
        result *= x;
    }
    result *= this->coefficient;
    return result;
}

void DummyVar::print(){
    std::cout << "the variable is ";
    if (this->coefficient == 0){
        std::cout << 0 << std::endl;
    } else {
        std::cout << this->coefficient;
        if (this->power != 0){
            std::cout << "*(" << this->name;
            if (this->power != 1){
                std::cout << "^" << this->power;
            }
        }
        std::cout << ")" << std::endl;
    }
}

int main(){
    DummyVar x('x');
    x.print();
    std::cout << x.evaluate(2) << std::endl;

    DummyVar y('y', 2, 3);
    y.print();
    std::cout << y.evaluate(2) << std::endl;

    DummyVar z('z', 0, 1);
    z.print();
    std::cout << z.evaluate(567231) << std::endl;

    DummyVar::availableNames->print();

    return 0;
}
