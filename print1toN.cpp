#include<bits/stdc++.h>
using namespace std;

// Parameterised recursion:
void print1(int i, int n){
    if(i>n){
        return;
    }
    cout<<i<<endl;
    print1(i+1, n);
}

// Using backtracking:
void print2(int i, int n){
    if(i<1){
        return;
    }

    print2(i-1, n);
    cout<<i<<endl;

}

// Functional Recursion:
void print3(int n){
    if(n<1){
        return;
    }
    print3(n-1);
    cout<<n<<endl;
}

// T.C = No. of recursion calls = O(n)
// S.C = O(n)

int main()
{
    print1(1, 4);
    print2(4, 4);
    print3(4);
    return 0;
}