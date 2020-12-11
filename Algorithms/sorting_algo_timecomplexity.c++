#include "stack" 
#include <iostream>
#include <string>
#include "list"

using namespace std;

class sort_algos{

    public:
    // function for swapping elements
    void swap(int *x, int *y){
        int value= *x;
        *x= *y;
        *y=value;
    }
// selection sort
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
// bubble sort
    void bubblesort(int array[],int n){
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
// insertion sort
    void insertionSort(int *array, int size) {

        int value, j;
        for(int i = 1; i<size; i++) {

            value = array[i];//take value
            j = i;
            while(j > 0 && array[j-1]>value) {
                array[j] = array[j-1];
                j--;
            }
            array[j] = value;   //insert in right place
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

    sort_algos s;
    int size;
    cout<<"Enter the size of array::";
    cin>>size;
    int rand_Array[size];
    for(int i=0;i<size;i++){
        rand_Array[i]=rand()%100;  //Generate number between 0 to 99
    }
    clock_t startTime = clock();  // start timer
    s.bubblesort(rand_Array,size);
    //s.display(rand_Array,size);
    cout << "Time for Bubble sort is: "<<double(clock()-startTime)/CLOCKS_PER_SEC<<endl;
   
   
    s.selectionSort(rand_Array,size);
  
    cout << "Time for Selection sort is: "<<double(clock()-startTime)/CLOCKS_PER_SEC<<endl;
   
   
    s.insertionSort(rand_Array,size);
   
    cout << "Time for Insertion sort is: "<<double(clock()-startTime)/CLOCKS_PER_SEC<<endl;
   
  
    /* displaying elements of array
    cout<<"\nElements of the array::"<<endl;
   for(int i=0;i<size;i++){
      cout<<"Elements no "<<i+1<<"::"<<rand_Array[i]<<endl;
   }
    */
    return 0;
};