#include<mutex>
#include<iostream>

using namespace std;
class Abc {
private:
    // static Abc* instance_ptr;
    Abc(){}
    static Abc* instance_ptr;
    static mutex m1;
    // Abc& operator=(const Abc& obj) = 0;
public:
    Abc(const Abc& obj) = delete;
    int x = 10;
    static Abc* get_instance(){
        if(instance_ptr==nullptr){
            lock_guard<mutex> lock(m1);
            if(instance_ptr==nullptr){
                instance_ptr = new Abc();
            }
        }
        return instance_ptr;
    }
};

Abc* Abc::instance_ptr = nullptr;
mutex Abc::m1;

int main(){
    Abc* ptr = Abc::get_instance();
    cout << ptr->x;
    
    return 0;
}