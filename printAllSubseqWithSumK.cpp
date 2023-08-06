#include<bits/stdc++.h>
using namespace std;

void print(int idx, vector<int> &temp, int sum, int K, int arr[], int n){
    if(idx==n){
        if(sum==K){
            for(auto it: temp){
                cout<<it<<" ";
            }
            cout<<endl;
        }
        return;
    }

//  Pick the element
    temp.push_back(arr[idx]);
    sum += arr[idx];
    print(idx+1, temp, sum, K, arr, n);
    temp.pop_back();
    sum-=arr[idx];

// Not pick
    print(idx+1, temp, sum, K, arr, n);
}

int main()
{
    int arr[] = {1, 2, 1};
    int n = 3;
    int K = 2;
    vector<int> ds;
    print(0, ds, 0, K, arr, n);
    return 0;
}