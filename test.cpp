#include<bits/stdc++.h>
using namespace std;

set<vector<int>> st;
void helper(int idx, vector<int> &temp, int sum, int K, vector<int> &candidates){
    if(idx==candidates.size()){
        if(sum==K){
            st.insert(temp);
        }
        return;
    }

//  Pick the element
    temp.push_back(candidates[idx]);
    sum += candidates[idx];
    helper(idx+1, temp, sum, K, candidates);
    temp.pop_back();
    sum -= candidates[idx];

// Not pick
    helper(idx+1, temp, sum, K, candidates);
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    vector<int> ds;
    helper(0, ds, 0, target, candidates);
    vector<vector<int>>ans(st.begin(), st.end());
    return ans;
}

int main()
{
    vector<int> candidates = {2, 5, 2, 1, 2};
    int target = 5;
    sort(candidates.begin(), candidates.end());
    vector<vector<int>> ans = combinationSum2(candidates, target);
    for(int i=0; i<ans.size(); i++){
        for(int j=0; j<ans[i].size(); j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}