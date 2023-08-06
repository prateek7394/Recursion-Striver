// Fibonacci series = 1 1 2 3 5 8 13 21 .....

#include<bits/stdc++.h>
using namespace std;

int fib(int n){
    if(n<=1){
        return n;
    }
    int last = fib(n-1);
    int seclast = fib(n-2);
    return last + seclast;
}

// T.C = O(2^n)[exponential] because for every call we are making 2 subcalls => 2*2*2*... n-times = O(2^n)

int main()
{
    cout<<fib(8);
    return 0;
}