// PROBLEM
// Given an array of distinct integers candidates and a target integer target, 
// return a list of all unique combinations of candidates where the chosen numbers sum to target.
// You may return the combinations in any order.

// The same number may be chosen from candidates an unlimited number of times. 

#include<bits/stdc++.h>
using namespace std;

void helper(int idx, vector<int> &ds, vector<vector<int>> &ans, vector<int>& candidates, int target){
    if(idx == candidates.size()){
        if(target==0){
            ans.push_back(ds);
        }
        return;
    }

    if(candidates[idx]<=target){
        // In this case, we have both options of pick or not pick the element

        // pick
        ds.push_back(candidates[idx]);
        helper(idx, ds, ans, candidates, target-candidates[idx]);
        ds.pop_back();

        // not pick
        helper(idx+1, ds, ans, candidates, target);
    }
    else{
        // not pick
        helper(idx+1, ds, ans, candidates, target);
    }
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<int> ds;
    vector<vector<int>> ans;
    helper(0, ds, ans, candidates, target);
    return ans;
}

int main()
{
    return 0;
}