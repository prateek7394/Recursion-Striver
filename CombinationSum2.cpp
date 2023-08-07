// PROBLEM:
// Given a collection of candidate numbers (candidates) and a target number (target), 
// find all unique combinations in candidates where the candidate numbers sum to target.
// Each number in candidates may only be used once in the combination.

// Note: The solution set must not contain duplicate combinations.


#include<bits/stdc++.h>
using namespace std;

    set<vector<int>> st;
    void helper(int idx, vector<int> &ds,int target, vector<int> &arr, vector<vector<int>> &ans){
        if(target==0){
            ans.push_back(ds);
            return;
        }

        for(int i=idx; i<arr.size(); i++){
            if(arr[i]>target) break; // Since array is sorted, so any element at the right of i will be greater than arr[i] so no need to
            // run loop for that i
            if(i>idx && arr[i]==arr[i-1]) continue; // combination starting with same element has been already formed
            // so don't take it to avoid duplicates

            ds.push_back(arr[i]);
            helper(i+1, ds, target-arr[i], arr, ans); //
            ds.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> ds;
        vector<vector<int>> ans;
        helper(0, ds, target, candidates, ans);
        return ans;
    }

int main()
{
    return 0;
}