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
    int arr[] = {2,5,2,1,2};
    int n = 5;
    int K = 5;
    vector<int> ds;
    print(0, ds, 0, K, arr, n);
    return 0;
}