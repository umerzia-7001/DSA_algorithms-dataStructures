#include "stack"
#include <iostream>
#include <string>
#include "list"
#include <chrono>

using namespace std::chrono;
using namespace std;
high_resolution_clock::time_point startTime;
class count_sort{

public:
    void countSort(long data[],const long n ){

        long i;
        long largest = data[0];
        long *temp = new long[n];

        for(i=1;i<n;i++){
            if(largest < data[i]){
                largest = data[i];
            }
        }
        unsigned long *count = new unsigned long[largest+1];

        for(i=0;i<=largest;i++){
            count[i]=0;
        }
        for(i=0;i<n;i++){
            count [data[i]] ++;
        }
        for(i=0;i<=largest;i++){
            count[i] = count[i-1] + count[i];
        }
        for(i=n-1;i>=0;i--){
            temp[count[data[i]]-1] = data[i];
            count[data[i]]--;
        }
        for(i=0;i<n;i++){
            data[i]=temp[i];
        }

    }
    void display(long array[], long size) {
        for(long i = 0; i<size; i++)
            cout << array[i] << " ";
        cout << endl;
    }

};

int main() {
    count_sort s;
    long n=5;
    long arr[5]= {534,3,4,63,23};

    cout << "Array before count Sorting: "<<endl;
    s.display(arr,n);
    startTime = high_resolution_clock::now();
    s.countSort(arr, n);
    cout << "Time for count Sorting: "<<endl;
    cout <<duration_cast<microseconds>(high_resolution_clock::now() - startTime).count() << "us\n";
    cout << "Array after count Sorting: "<<endl;
    s.display(arr,n);

    return 0;
}
