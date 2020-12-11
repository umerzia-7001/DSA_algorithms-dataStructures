// using STL for stack 
#include "stack" 
#include <iostream>
#include <string>
#include "list"

using namespace std;


int main(){
    // implmenting an stack from STL
    stack<int> s;
    string in;

    cout<<" ------ Stack ------"<<endl;
    cout<<" Enter input . S (shrink) or G (grow)"<<endl;

    cin>>in;

    //converting string to a char array

    // declaring character array : in_arr
    char in_arr[in.length()];

    int i;
    for (i = 0; i < sizeof(in_arr); i++) {
        in_arr[i] = in[i];
        cout<< in_arr[i];
    }
    //initialize a output array : out_arr
    list<int> out_arr={};

    // storing S G in char arrays

    char S='S';
    char G='G';

    int counter=0;
    while(counter<in.length()+1){

        s.push(counter);
        
        cout<<in_arr[counter]<<counter<<endl;

        if(in_arr[counter]==S){

            cout<<" Shrink"<<endl;
            while(!s.empty()){

        // Print info:
                //cout << "top() -> " << s.top() << endl;
                //cout<< "size() -> " << s.size() << endl;
                int t = s.top();
                out_arr.push_back(t+1);
        
        // Pop out the top element:
                s.pop();  
                }

        }
        else if(in_arr[counter]==G){

            if(counter==in.length()){
                for(int i=0; i<s.size();i++){

                    int q= s.top();
                    out_arr.push_back(q);

                    s.pop();

                }
            }
            //when for loop ends clear the stack && append to output in case of end G
        }
        counter++;
    }

    for( auto x = out_arr.begin( ); x != out_arr.end( ); ++x) {

        cout<<*x<<endl;

    } 
    return 0;
};
