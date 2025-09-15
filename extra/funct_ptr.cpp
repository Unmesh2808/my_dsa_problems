#include <iostream>

using namespace std;

class Abc {
public:
    int multiply(int a, int b){
        return a*b;
    }

};

//declare func ptr
int (Abc::*funcptr)(int, int);

Abc obj;
//initialize func ptr
funcptr = &Abc::multiply;
int results = (obj.*funcptr)(3,5);