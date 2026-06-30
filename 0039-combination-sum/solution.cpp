class Solution {
public:
    void solve(int i,int n,int target,vector<int>&arr,vector<int>&curr,vector<vector<int>>&ans){
        if(target<0)return;
        if(i==n){
            if(target==0)ans.push_back(curr);
            return;
        }
        curr.push_back(arr[i]);
        solve(i,n,target-arr[i],arr,curr,ans);
        curr.pop_back();
        solve(i+1,n,target,arr,curr,ans);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>curr;
        vector<vector<int>>ans;
        solve(0,candidates.size(),target,candidates,curr,ans);
        return ans;
        
    }
};
