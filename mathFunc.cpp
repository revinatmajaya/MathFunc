#include "./headers/mathFunc.h"

// List<char>* DummyVar::availableNames = new List<char>();
// List<char>* MathFunc::availableNames = new List<char>();

// DummyVar('x') will make an x variable to be used in the MathFunc class constructor
DummyVar::DummyVar(){
    this->name = 0;
}

DummyVar::DummyVar(const char name){
    this->name = name;
    // DummyVar::availableNames->add(name);
}

MathFunc::MathFunc(){
    this->mathFunctions = nullptr;
    this->name = 0;
    this->coefficient = 0;
    this->power = 0;
    this->var = nullptr;
}

MathFunc::MathFunc(const char name, DummyVar* var){
    this->mathFunctions = nullptr;
    this->name = name;
    this->coefficient = 1;
    this->power = 1;
    this->var = var;
}

MathFunc::MathFunc(const char name, DummyVar* var, const int coefficient){
    this->mathFunctions = nullptr;
    this->name = name;
    this->coefficient = coefficient;
    this->power = 1;
    this->var = var;
}

MathFunc::MathFunc(const char name, DummyVar* var, const int coefficient, const int power){
    this->mathFunctions = nullptr;
    this->name = name;
    this->coefficient = coefficient;
    this->power = power;
    this->var = var;
}

int MathFunc::evaluate(const int x){

    int result;

    if (mathFunctions != nullptr){
        Node<MathFunc*>* curr = mathFunctions->head;
        
        // use divide and conquer strategy
        while(curr){
            switch(curr->value->operat){
                case 0:  // plus
                    result += curr->value->evaluate(x);
                    break;

                case 1: // minus
                    result -= curr->value->evaluate(x);
                    break;

                case 2: // multiply
                    if (result == 0){
                        result = 1;
                    }
                    result *= curr->value->evaluate(x);
                    break;

                case 3: // division
                    if (result == 0) result = 1;
                    result /= curr->value->evaluate(x);
                    break;

                default: // no operator usually the first function in the list
                    result = curr->value->evaluate(x);
            }
            curr = curr->next;
        }
    }

    // root method when curr is null
    else{
        result = 1;
        for(int i = this->power; i > 0; i--){
            result *= x;
        }

        result *= this->coefficient;
    }

    return result;
}

void MathFunc::print(){
    std::cout << this->name << "(" << this->var->name << ") = " << this->coefficient << this->var->name << "^" << this->power << std::endl; 
}

// operator overloads

MathFunc MathFunc::operator+(MathFunc* const g){

    // setups
    MathFunc func = MathFunc('h', this->var, 1, 1);
    func.setFuncList(new List<MathFunc*>);
    g->setOperator(0);

    // add functions to list
    func.mathFunctions->add(this);
    func.mathFunctions->add(g);

    return func;
}

MathFunc MathFunc::operator-(MathFunc* const g){

    // setups
    MathFunc func = MathFunc('h', this->var, 1, 1);
    func.setFuncList(new List<MathFunc*>);
    g->setOperator(1);

    // add functions to list
    func.mathFunctions->add(this);
    func.mathFunctions->add(g);

    return func;
}

MathFunc MathFunc::operator*(MathFunc* const g){
    // setups
    MathFunc func = MathFunc('h', this->var, 1, 1);
    func.setFuncList(new List<MathFunc*>);
    g->setOperator(2);

    // add functions to list
    func.mathFunctions->add(this);
    func.mathFunctions->add(g);

    return func;
}

MathFunc MathFunc::operator/(MathFunc* const g){
    // setups
    MathFunc func = MathFunc('h', this->var, 1, 1);
    func.setFuncList(new List<MathFunc*>);
    g->setOperator(3);

    // add functions to list
    func.mathFunctions->add(this);
    func.mathFunctions->add(g);

    return func;
}
