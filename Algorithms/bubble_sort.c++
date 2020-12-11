
#include "stack" 
#include <iostream>
#include <string>
#include "list"

using namespace std;

class Bubble_sort{
    public:
    void swap(int *x, int *y){
        int value= *x;
        *x= *y;
        *y=value;
    }

    void sort(int array[],int n){

        int i,j;
        // first loop for each element to assign largest one
        for(i=0;i<n-1;i++){

            //second loop for each pass through array
            for(j=0;j<n-i-1;j++){
                if (array[j]>array[j+1]){
                    swap(&array[j],&array[j+1]);
                }
            }
        }
    }
    // function to display array
    void display(int array[], int size) {

        int i;  
        for (i = 0; i < size; i++)  
            cout << array[i] << " ";  
        cout << endl;  
    } 
};

int main(){
    int size;
    Bubble_sort bubble;
    
    cout << "Enter the number of elements: ";
    cin >> size;
    int array[size];    //create an array with given number of elements
    for(int i = 0; i<size; i++) {
        cout<<"enter element"<<endl;
        cin >> array[i];
    }
 
    bubble.sort(array,size);
    cout<<"Sorted Array is :\n";
    bubble.display(array,size);
    return 0;
};