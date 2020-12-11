
#include<iostream>
using namespace std;
#include<time.h> 

class Fibonacci_complexity{

    public:
    int n;
    int fibonacci(int n){
    if((n==1)||(n==0))
    {
        return(n);
    }
    else
    {
        return(fibonacci(n-1)+fibonacci(n-2));
    }
}
};   

int main()
{
    Fibonacci_complexity f;

    clock_t startTime = clock();

    int t1 = 0, t2 = 1, nextTerm = 0, n;

    cout << "Enter a positive number: ";
    cin >> n;

    // displays the first two terms which is always 0 and 1
    cout << "Fibonacci Series: " << t1 << ", " << t2 << ", ";

    nextTerm = t1 + t2;

    while(nextTerm <= n)
    {
        cout << nextTerm << ", ";
        t1 = t2;
        t2 = nextTerm;
        nextTerm = t1 + t2;
    }
    cout<<endl;
    cout << "Time for Fibonacci Series Iteratively is: "<<double(clock()-startTime)/CLOCKS_PER_SEC<<endl;
    int x;
    while(x)
    {
        cout<<" "<<f.fibonacci(x);
        x++;
    }
    cout << "Time for Fibonacci Series Recursively is: "<<double(clock()-startTime)/CLOCKS_PER_SEC;
    return 0;
}