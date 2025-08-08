#include<iostream>

using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val){
        data = val;
        next = nullptr;
    }
};

Node* reverse_ll(Node* header){
    Node* prev = nullptr;
    Node* curr = header;
    Node* nextnode = nullptr;
    while(curr!=nullptr){
        nextnode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextnode; 
    }
    // cout<<prev->data;
    return prev;
    // while (prev!=nullptr){
    //     cout<<prev->data<<endl;
    //     prev = prev->next;
    // }
    
}

int main(){
    Node* head = new Node(3);
    Node* node1 = new Node(4);
    Node* node2 = new Node(5);
    head->next = node1;
    node1->next = node2;
    node2->next =nullptr;
    // while (head!=nullptr){
    //     cout<<head->data<<endl;
    //     head = head->next;
    // }
    Node* ans = reverse_ll(head);
    // cout<<ans->data;
    while (ans!=nullptr){
        cout<<ans->data<<endl;
        ans = ans->next;
    }
    return 0;
}