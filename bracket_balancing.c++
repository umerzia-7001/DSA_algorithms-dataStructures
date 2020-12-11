// created by @umerzia
#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;

// ###  implementiung stack using array  ###

class Stack{
    public:
    // making a  stack of size 50 
    char stack[100];
    int n=100;
    // top reference for initialization
    int top= -1;

    // push function to insert element into stack
    void push(int num){

        if(isFull()==true){
            cout<<"stack is full! "<<endl;
        }
        else{
            top++;
            stack[top]=num;
        }
    }
    // pop function to remove element from stack
    void pop(){

        if(isEmpty()==true){
            //cout<<"stack is empty ! "<<endl;
        }
        else{
            //cout<<" The popped element is "<< stack[top] <<endl;
            top--;
        }
    }
    // funcion to see top element 
    char Peek(){ //see the top element without removing it
        if(isEmpty()){
            //cout<<"NONE at top,cant peek "<<endl;
        }
        else{
            //cout<<"op element : "<<endl;
            return (stack[top]);
        }
    }
     // fnction to check if stack is full
    bool isFull(){
        return top>=n-1;
    }
    // fnction to check if stack is empty
    bool isEmpty(){
        return top<=-1;
    }
    // display function to view elements in stack
    void display(){
        if(top>=0){
            cout<<"elements are : "<<endl;
            int i;
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
    
    string exp;
    char i,top;
    int valid=true;

    cout<<"Enter an expression "<<endl;

    cin>>exp;
    

    for(i=0;i<exp.length();i++){

        if (exp[i] == '(' || exp[i] == '['
            || exp[i] == '{')  
        { 
            // Push the element in the stack 
            s.push(exp[i]); 
            continue; 
        } 
  
        // IF current current character is not opening 
        // bracket, then it must be closing. So stack 
        // cannot be empty at this point. 
        else if (exp[i] != '(' || exp[i] != '['
            || exp[i] != '{') 
            continue;
        else {
                if (exp[i] == '}' || exp[i] == ')' || exp[i] == ']') {

            switch (exp[i]) {
                        case ')': {
                            top=s.Peek();
                            s.pop();
                            if (top == '{' || top== '[') {
                                valid = false;
                                break;                      
                            }                     
                        }
                        case '}': {
                            top=s.Peek();
                            s.pop();
                            if (top == '(' || top == '[') {
                                valid = false;
                                break;                     
                            }
                        }
                        case ']': {
                            top=s.Peek();
                            s.pop();
                            if (top == '{' || top == '(') {
                                valid = false;
                                break;
                            
                            }
                        }
                    }

                }
        }
        
        }
        if(valid==true){
            cout<<"Valid expression!"<<endl;
        }
            
        else if(valid==false){
            cout<<"invalid expression"<<endl;
        }

// alternate short way 
        /*
    for (char i : exp){
        if (i == '{' || i == '[' || i == '(' )
            s.push(i);
        else if (i == '}' || i == ']' || i == ')')
            s.pop();
        else
            continue;
    }
    if(s.isEmpty()==true){
        cout<<"valid expression"<<endl;
    }
        
    else{
        cout<<"Invalid expression"<<endl;
    }
    */
   return 0;
};