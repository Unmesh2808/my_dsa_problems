#include<iostream>
int main(){

    // int* to char*
    int val = 100;
    int* intPtr = &val;
    char* charptr = reinterpret_cast<char*>(intPtr);

    std::cout<< intPtr << std::endl;
    std::cout<< *charptr << std::endl;

    std::cout << static_cast<int>(*charptr);

    //char* to int

}