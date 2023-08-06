#include<bits/stdc++.h>
using namespace std;

int count(int idx, int sum, int K, int arr[], int n){
    if(sum>K){
    // to optimise the time complexity(O(2^n)) we can add this line
    // but it holds if the array strictly contains positive elements only
        return 0;
    }
    if(idx==n){
        if(sum==K){
            // condition satisfied
            return 1;
        }
        else{
            // condition not satisfied
            return 0;
        }
    }

//  Pick the element
    sum += arr[idx];
    int take = count(idx+1, sum, K, arr, n);
    sum-=arr[idx];

// Not pick
    int notTake = count(idx+1, sum, K, arr, n);

    return take + notTake;
}

int main()
{
    int arr[] = {1, 2, 1};
    int n = 3;
    int K = 2;
    int ans = count(0, 0, K, arr, n);
    cout<<ans;
    return 0;
}