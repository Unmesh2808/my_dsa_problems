// declare a singke linked list with 3 nodes
// [H]->[N]->[N]

#include<iostream>
struct Node{
    int data;
    Node* next;
    Node(int val) : data(val),next(nullptr){}
};

int main(){
    Node* head = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);
    
    // link the nodes from the list
    head->next = second;
    second->next = third;
    third->next = nullptr;

    Node* current = head;
    while(current != nullptr){
        std::cout <<"Current data = "<<current->data<<"\n";
        current = current->next;
    }
    std::cout << "NULL\n";

    delete head;
    delete second;
    delete third;

    return 0;

}