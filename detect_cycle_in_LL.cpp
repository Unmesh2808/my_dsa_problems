//Write a program to detect a cycle in a linked list and remove it
#include<iostream>
using namespace std;

struct Node
{
    int x;
    Node* next;
    Node(int val){
        x = val;
        next = nullptr;
    }
};

Node* detect_cycle_send_node(Node* header){
    Node* slow = header;
    Node* fast = header;
    bool cycle=false;
// Detecting the loop
    while(fast!=nullptr && fast->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast){
            cout<<"there is aa loop detected $ "<<endl;
            cycle = true;
            break;
        }
    }
    if(!cycle) return nullptr;
// finding where the loop exactly starts again.
    slow = header;
    Node* prev = nullptr;// to store the previous of the fast pointer
    while(slow!=fast){
        slow = slow->next;
        prev = fast;
        fast = fast->next;
    }
    prev->next = nullptr; // remove the cycle by assigning null to the previous value of fast.
    return slow;
}

int main(){
    Node* head = new Node(5);
    Node* node1 = new Node(6);
    Node* node2 = new Node(7);
    Node* node3 = new Node(8);
    Node* node4 = new Node(9);
    Node* node5 = new Node(10);
    head->next=node1;
    node1->next=node2;
    node2->next=node3;
    node3->next=node4;
    node4->next=node5;
    node5->next=node2;

    Node* ans = detect_cycle_send_node(head);

    cout<<"the point at which the cycle starts is at node that points to value : "<<ans->x<<endl;

    delete head;
    delete node1;
    delete node2;
    delete node3;
    delete node4;
    delete node5;

    return 0;
}


