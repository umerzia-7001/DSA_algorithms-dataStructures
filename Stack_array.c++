// created by @umer
#include<iostream>
#include<stdio.h>
#include<string.h>

using namespace std;
// ###  implementiung stack using array  ###

class Stack{
    public:
    
    // making a  stack of size 50 
    int stack[50];
    int n=50;
    // top reference for initialization
    int top=-1;

    // push function to insert element into stack
    void push(int num){

        if(top>=n-1){
            cout<<"stack is empty! "<<endl;
        }
        else{
            top++;
            stack[top]=num;
        }
    }
    // pop function to remove element from stack
    void pop(){

        if(top<=-1){
            cout<<"stack is empty ! "<<endl;
        }
        else{
            cout<<" The popped element is "<< stack[top] <<endl;
            top--;
        }
    }
    // display function to view elements in stack
    void display(){
        if(top>=0){
            int i;
            cout<<"elements are : "<<endl;
            for(i=0;i<=top;i++){
                cout<<stack[i]<<endl;
            }
        }
        else{
            cout<<" Stack is empty! "<<endl;
        }
    }
};


int main() {
    Stack s;
   int ch, val;
   cout<<"  --- STACK ---  "<<endl;
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
            s.push(val);
            break;
         }
         case 2: {
            s.pop();
            break;
         }
         case 3: {
            s.display();
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
};









