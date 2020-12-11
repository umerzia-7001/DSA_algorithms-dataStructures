#include "stack" 
#include <iostream>
#include <string>
#include "list"

using namespace std;

class selection_sort{
    public:
    void swap(int *x, int *y){
        int value= *x;
        *x= *y;
        *y=value;
    }

    void selectionSort(int arr[], int n)  
{  
    int i, j, min_idx;  
  
    // One by one move boundary of unsorted subarray  
    for (i = 0; i < n-1; i++)  
    {  
        // Find the minimum element in unsorted array  
        min_idx = i;  
        for (j = i+1; j < n; j++)  
        if (arr[j] < arr[min_idx])  
            min_idx = j;  
  
        // Swap the found minimum element with the first element  
        swap(&arr[min_idx], &arr[i]);  
    }  
}  
    void bubble_sort(int array[],int n){

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
    selection_sort selection;
    
    cout << "Enter the number of elements: ";
    cin >> size;
    int array[size];    //create an array with given number of elements
    for(int i = 0; i<size; i++) {
        cout<<"enter element"<<endl;
        cin >> array[i];
    }
 
    selection.selectionSort(array,size);
    cout<<"Sorted Array is :\n";
    selection.display(array,size);
    return 0;
};