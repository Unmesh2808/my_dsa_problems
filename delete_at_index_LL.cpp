#include<iostream>
using namespace std;

class Node{
public:
    int x;
    Node* next;
    Node(int val){
        x = val;
        next = nullptr;
    }    
};

class MyLinkedList {
public:
    Node* head;
    Node* tail;
    MyLinkedList() {
        head=tail=nullptr;
    }

    int get(int index) {
        if(index<0 || head==nullptr){return -1;}
    
        Node* temp = head;
        int count = 0;
        while(temp!=nullptr && count<index){
            temp = temp->next;
            count++;
        }
        if(temp==nullptr){return -1;}
        int n = temp->x;
        return n;
    }

    void addAtHead(int val) {
        Node* newnode = new Node(val);
        newnode->next =nullptr;

        if(head==nullptr){
            head=tail=newnode;
            return;
        }
        else{
            newnode->next = head;
            head = newnode;
        }
    }

    void addAtTail(int val) {
        Node* newnode = new Node(val);
        newnode->next =nullptr;
        if(head==nullptr){
            head=tail=newnode;
            return;
        }
        else{
            tail->next = newnode;
            tail = newnode;
        }
    }

    void addAtIndex(int index, int val) {
        if(index<0) return;

        if(index == 0){
            addAtHead(val);
            return;    
        }
        Node* temp = head;
        int count=0;
        while(temp!=nullptr && count<index-1){
            temp = temp->next;
            count++;
        }

        if(temp==nullptr){return;}

        Node* newnode = new Node(val);
        newnode->next=temp->next;
        temp->next = newnode;

        if(temp==tail){
            tail = newnode;
        }
    }

    void deleteAtIndex(int index) {
        if(index<0 || head ==nullptr) return;

        if(index == 0){
            Node* tobedeleted = head;
            head = head->next;
            
            if(head==nullptr)tail==nullptr;

            delete tobedeleted;
            return;    
        }
        int count=0;
        Node* temp = head;
        while(temp!=nullptr && count<index-1){
            temp = temp->next;
            count++;
        }
        if(temp==nullptr || temp->next==nullptr){return;}
        
        Node* min = temp->next;
        temp->next = temp->next->next;

        if(min==tail){
            tail=temp;
        }
        delete min;
    }

    void print(){
        Node* temp = head;
        while(temp!=nullptr){
            cout<<temp->x<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }
};

int main(){
//   Your MyLinkedList object will be instantiated and called as such:
/*["MyLinkedList","addAtHead","addAtHead","addAtHead","addAtIndex","deleteAtIndex",
"addAtHead","addAtTail","get","addAtHead","addAtIndex","addAtHead"]*/
  MyLinkedList* obj = new MyLinkedList();
  obj->addAtHead(7);
  obj->addAtHead(2);
  obj->addAtHead(1);
  obj->addAtIndex(3,0);
  obj->print();

  obj->deleteAtIndex(2);
  obj->print();

  obj->addAtHead(6);
  obj->print();

  obj->addAtTail(4);
  obj->print();
  int param_1 = obj->get(4);
  cout<<param_1<<endl;
  obj->addAtHead(4);
  obj->addAtIndex(5,0);
  obj->addAtHead(6);


}
 