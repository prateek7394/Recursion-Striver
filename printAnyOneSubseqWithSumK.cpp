#include<bits/stdc++.h>
using namespace std;

bool print(int idx, vector<int> &temp, int sum, int K, int arr[], int n){
    if(idx==n){
        if(sum==K){
            // condition satisfied
            for(auto it: temp){
                cout<<it<<" ";
            }
            cout<<endl;
            return true;
        }
        else{
            // condition not satisfied
            return false;
        }
    }

//  Pick the element
    temp.push_back(arr[idx]);
    sum += arr[idx];

// NOTE: If any of the function calls return true, the code below that function call is not executed
    if(print(idx+1, temp, sum, K, arr, n)==true) return true;

    temp.pop_back();
    sum-=arr[idx];

// Not pick
    if(print(idx+1, temp, sum, K, arr, n)==true) return true;

    return false;
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