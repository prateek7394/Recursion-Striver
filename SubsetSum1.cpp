// PROBLEM:
// Given a list arr of N integers, print sums of all subsets in it.


#include<bits/stdc++.h>
using namespace std;

void helper(int idx, int sum, vector<int> &arr, vector<int> &ans){
    if(idx==arr.size()){
        ans.push_back(sum);
        return;
    }
    
    // pick
    helper(idx+1, sum+arr[idx], arr, ans);
    
    // not pick
    helper(idx+1, sum, arr, ans);
}

vector<int> subsetSums(vector<int> arr, int N)
{
    vector<int>ans;
    helper(0, 0, arr, ans);
    return ans;
}

int main()
{
    return 0;
}