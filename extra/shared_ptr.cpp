//Simulate a scenario where multiple components share ownership of a resource using std::shared_ptr.
#include <iostream>
#include<memory>

class Cake : public std::enable_shared_from_this<Cake> {
public:
    int a1=32;
    void increment(){
        a1++;
    }
    std::shared_ptr<Cake> get_pointer(){ // returns a unique pointer
        return std::make_shared<Cake>();
    }

    void print(){
        std::cout << a1 << " "<< std::endl;
    }

};

int main(){
    Cake obj1;
    // std::shared_ptr<Cake> c1 = std::make_shared<Cake>();
    std::shared_ptr<Cake> c1 = obj1.get_pointer();
    // std::unique_ptr<Cake> c2 = c1->get_pointer();

    c1->increment();
    // c2->increment();
    c1->increment();
    // c2->increment();
    c1->increment();

    c1->print();
    return 0;

}