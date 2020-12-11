// created by @umer
#include<iostream>
#include<stdio.h>
#include<string.h>

using namespace std;
// ###  implementiung stack using Linklist ###

struct Node{

        int value;
        struct Node* next;
};
class Stack{
    public:

    // struct for making node of linklist
    
    struct Node *top=NULL;

    // push function to add elements in stack
    void push(int num){
        struct Node * node=new Node();
        node->value=num;
        node->next=top;
    }
    // pop function to remove element from stack

    void pop(){
        if(top==NULL){
            cout<<" No elements in stack "<<endl;
        }
        else{
            cout<<" Popped element is : "<<top->value<<endl;
            top=top->next;
        }
    }
    // functon to display elements in stack
    void display(){
        struct Node* ptr;
        if(top==NULL){
            cout<<" No element to display"<<endl;
        }

        else{
            ptr=top;
            while(ptr!=NULL){
                cout<<"Elements are : "<<ptr->value<<endl;
                ptr=ptr->next;
        }

        }
    }
};

int main() {
    Stack s1;
   int ch, val;
   cout<<"1) Push in stack"<<endl;
   cout<<"2) Pop from stack"<<endl;
   cout<<"3) Display stack"<<endl;
   cout<<"4) Exit"<<endl;
   do {
      cout<<"Enter choice: "<<endl;
      cin>>ch;
      switch(ch) {
         case 1: {
            cout<<"Enter value to be pushed:"<<endl;
            cin>>val;
            s1.push(val);
            break;
         }
         case 2: {
            s1.pop();
            break;
         }
         case 3: {
            s1.display();
            break;
         }
         case 4: {
            cout<<"Exit"<<endl;
            break;
         }
         default: {
            cout<<"Invalid Choice"<<endl;
         }
      }
   }while(ch!=4);
   return 0;
}