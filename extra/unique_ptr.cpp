#include<iostream>
#include<memory>

class A{
public:
    void print(){
        std::cout << "Unmesh\n" << std::endl;
    }
};

int main(){
    std::unique_ptr<A> p1 = std::make_unique<A>();
    std::unique_ptr<A> p2 = std::move(p1);

    p1->print();
    p2->print();
    return 0;
}