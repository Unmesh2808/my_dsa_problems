/*You are given two non-empty linked lists representing two non-negative integers. 
The digits are stored in reverse order, and each of their nodes contains a single digit. 
Add the two numbers and return the sum as a linked list.*/
/*Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807*/
#include<iostream>
#include<vector>
struct Node1
{
    int data;
    Node1* next;

    Node1(int val) : data(val),next(nullptr){}
};
// struct Node2
// {
//     int data2;
//     Node2* next;

//     Node2(int val) : data2(val),next(nullptr){}
// };

int reverse_num(int n){
    int rev_num, num1 = 0;
    for (int i = n; i!=0;i/=10){
        num1 = i%10;
        rev_num = rev_num*10 + num1;
    }
    return rev_num;
}

Node1* add_two_num(Node1* H1, Node1* H2){
    std::vector<int> h1, h2;
    Node1* header1 = H1;
    Node1* header2 = H2;
    int num1=0,num2=0,sum=0;
    // num1=num1*10 + data;
    while(header1!=nullptr){
        h1.push_back(header1->data);
        header1 = header1->next;
    }
    while(header2!=nullptr){
        h2.push_back(header2->data);
        header2 = header2->next;
    }
    for(auto i = h1.rbegin();i!=h1.rend();i++){
        num1 = num1*10 + *i;
        // std::cout<<*i<<"\n";
    }
    for(auto i = h2.rbegin();i!=h2.rend();i++){
        num2 = num2*10 + *i;
        // std::cout<<*i<<"\n";
    }
    // for(int j : h1){
    //     std::cout<<j<<"\n";
    // }
    sum = num1+num2;
    int rev_sum = reverse_num(sum);
    Node1* head = nullptr;
    Node1* curr = nullptr;
    while (rev_sum!=0)
    {
        Node1* new_h = new Node1(rev_sum%10);
        rev_sum/=10;
        if (head==nullptr){
            head = new_h;
            curr = new_h;
        }
        else{
            curr->next = new_h;
            curr = new_h;
        }
    }
    return head;
    
}

int main(){
    // initialize node 1
    Node1* h1 = new Node1(2);
    Node1* n1 = new Node1(4);
    Node1* l1 = new Node1(3);
    h1->next = n1;
    n1->next = l1;
    l1->next = nullptr;

    //initialize node 2
    Node1* h2 = new Node1(5);
    Node1* n2 = new Node1(6);
    Node1* l2 = new Node1(4);
    h2->next = n2;
    n2->next = l2;
    l2->next = nullptr;

    Node1* ans = add_two_num(h1, h2);
    while(ans!=nullptr){
        std::cout<<"Sum = "<<ans->data<<"\n";
        ans = ans->next;
    }

    delete h1;
    delete n1;
    delete l1;
    delete h2;
    delete n2;
    delete l2;
    delete ans;

    return 0;    
}

