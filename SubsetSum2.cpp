// PROBLEM:
// Given an integer array nums that may contain duplicates, return all possible subsets(the power set).

// The solution set must not contain duplicate subsets. Return the solution in any order.

#include<bits/stdc++.h>
using namespace std;

// ******************************* M1: Using Set ******************
// T = O(2^n) + O(m*logm) where, m = 2^n

void helper(int idx, vector<int> &ds, set<vector<int>> &st, vector<int> &nums){
    if(idx==nums.size()){
        st.insert(ds);
        return;
    }

    // pick
    ds.push_back(nums[idx]);
    helper(idx+1, ds, st, nums);
    ds.pop_back();

    // not pick
    helper(idx+1, ds, st, nums);
}
vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    set<vector<int>> st;
    vector<int> ds;
    helper(0, ds, st, nums);

    vector<vector<int>>ans(st.begin(), st.end());
    return ans;
}

// ******************************* M1: Using Backtracking without Using Set ******************

void helper(int idx, vector<int> &ds, vector<vector<int>> &ans, vector<int> &nums){
    ans.push_back(ds);
    if(idx==nums.size()){
        return;
    }

    for(int i=idx; i<nums.size(); i++){
        if(i>idx && nums[i]==nums[i-1]) continue; //we can pick an element only for its first occurrence and ignore further occurrences
        ds.push_back(nums[i]);
        helper(i+1, ds, ans, nums);
        ds.pop_back();
    }
}
vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>>ans;
    vector<int> ds;
    helper(0, ds, ans, nums);

    return ans;
}
int main()
{
    return 0;
}