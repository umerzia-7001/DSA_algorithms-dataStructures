
#include<iostream>
using namespace std;
#include<time.h> 

class time_complexity{

    public:
    long n;

    long factorial(long n){

        if(n==0){
            return 1;
        }
        else if(n==1){
            return 1;
        }
        else{
            long fact = n * factorial(n-1);
            return fact;
        }
    }
};
int main()
{
    long n;
    time_complexity time;
    cout << "Enter a positive integer: "<<endl;
    cin >> n;
   
    clock_t startTime = clock();
    cout << "Factorial of " << n << " = " << time.factorial(n)<<endl;;
    cout << "Time for factorial recursively is: "<<double(clock()-startTime)/CLOCKS_PER_SEC<<endl;

    long factorial = 1;


    for(int i = 1; i <=n; ++i)
    {
        factorial *= i;
    }
    cout << "Factorial of " << n << " = " << factorial<<endl;    
    cout << "Time for factorial iteratively is: "<< double(clock()-startTime)/CLOCKS_PER_SEC;
    return 0;
};