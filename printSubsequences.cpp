#include<bits/stdc++.h>
using namespace std;

void printSubsequences(int idx, int arr[], int size, vector<int> &temp){
    if(idx==size){
        if(temp.size()==0){
            cout<<"{}";
        }
        else{
            for(auto it: temp){
                cout<<it<<" ";
            }
        }
        cout<<endl;
        return;
    }


// not take
    printSubsequences(idx+1, arr, size, temp);

// take
    temp.push_back(arr[idx]);
    printSubsequences(idx+1, arr, size, temp);
    temp.pop_back();
}

// T.C = O(2^n * n) since we have 2 choices for each index and for every subsequence we run a for loop to print it.
// S.C = O(n) since we have at max n recursion calls in stack space

int main()
{
    int arr[] = {-1, 0, 1};
    int n = sizeof(arr)/sizeof(arr[0]);
    vector<int> temp;
    printSubsequences(0,arr,n, temp);
    return 0;
}