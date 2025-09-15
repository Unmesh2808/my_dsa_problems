#include <iostream>
#include <mutex>
#include <memory>

using namespace std;

class Abc{
    private:
    Abc(){}
    static Abc* ptr;
    static mutex m1;
    
    public:
    Abc(const Abc& obj1) = delete;
    static Abc* get_instance(){
        if(ptr=nullptr){
            lock_guard<mutex> lock(m1);
            ptr = new Abc();
        }
        return ptr;
    }

    void print(){
        std::cout<<"Always PRACTICE SYNTAX\n";
    }

};

Abc* Abc::ptr = nullptr; // initialize static member variables
mutex Abc::m1;


int main(){
    static Abc* pointer = Abc::get_instance();

    pointer->print();
    return 0;
}