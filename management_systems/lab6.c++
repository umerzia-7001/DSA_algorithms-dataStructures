
#include <iostream>
#include <string>
#include "list"

using namespace std;

class management{

    public:
    // making an array based queue
    int id;
    int patient[20];
    int first;
    int last;
    int no=20;
    //constuctor
    management(){
        id=0;
        first=-1;
        last=-1;
    }

    // declaring functions
    void Register(int id){

        if(last==no-1){
            cout<<"No space for morem patients! "<<endl;
        }
        else{
            if (first == -1){

            first = 0;
            }
            last++;
            patient[last]=id;
        
        }
        cout << "Patient Registered with id: "<<id<< endl;

    }
    void serve(){
        if (canDocGoHome()){
            cout << endl << "No Patient to be Served!" << endl;
            return;
    }
    else if (first == last){

        cout << "Patient Served with id: " << patient[first] << endl;
        first = -1;
        last = -1;
    }
    else{
        cout<< "Patient Served with id: " << patient[first] << endl;
        first++;
     }
    }
    void cancelAll(){

        if(canDocGoHome()){
            return;
        }
        else{
            for(int i=first;i<last;i++){
                serve();
            }
            return;
        }


    }
    bool canDocGoHome(){

        if((first==last)&&(last==-1)){
            return true;
        }
        else{
            return false;
        }
    }
    void showPatients(){

        if(canDocGoHome()){
            cout<<"No patients to be served"<<endl;
            return;
        }
        
        else{
            for(int i=first;i<=last;i++){
                cout<<"Patient with id : "<<patient[i]<<endl;
                    
            }
            return;
        }
    }
    // insertion sort
    void sort(int *patient,int size){
        size=3;
        int value, j;
   for(int i = 1; i<size; i++) {
      value = patient[i];//take value
      j = i;
      while(j > 0 && patient[j-1]>value) {
         patient[j] = patient[j-1];
         j--;
      }
      patient[j] = value;   //insert in right place
   }
    }

};

int main(){

    //making instance of class
    management m;
    cout<<" Wellcome to waiting room"<<endl;
    cout<<"--------------------------"<<endl;
    
    
    // Displaying functionality of program
    cout<<endl<<"--- Adding patients in waiting queue ---"<<endl;
    m.Register(1);
    m.Register(3);
    m.Register(2);
 
    cout <<endl<< "Can doctor go Home ? " << (m.canDocGoHome() ? "Yes" : "No" )<< endl;
    
    cout<<endl<<"--- Sorting patients on basis of id ---"<<endl;
    m.sort(m.patient,3);
    m.showPatients();
    cout<<endl<<"--- Serving patients from queue ---"<<endl;
    m.serve();
    m.serve(); 
    m.serve();
    m.showPatients();
    cout <<endl<< "Can doctor go Home ? " << (m.canDocGoHome() ? "Yes" : "No" )<< endl;
    
    return 0;
}