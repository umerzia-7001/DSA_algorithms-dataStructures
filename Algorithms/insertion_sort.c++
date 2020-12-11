
#include<iostream>
using namespace std;

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
void display(int *array, int size) {
   for(int i = 0; i<size; i++)
      cout << array[i] << " ";
   cout << endl;
}
int main() {
   int n;
   cout << "Enter the number of elements: ";
   cin >> n;
   int arr[n];    //create an array with given number of elements
   cout << "Enter elements:" << endl;
   for(int i = 0; i<n; i++) {
      cin >> arr[i];
   }
   insertionSort(arr, n);
   cout << "Array after Sorting: ";
   display(arr, n);
   return 0;
}
