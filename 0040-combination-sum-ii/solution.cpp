class Solution {
public:
    void solve(int i,int n,int target,vector<int>&arr,vector<int>&curr,vector<vector<int>>&ans){
        if(target<0)return;
        if(i==n){
            if(target==0)ans.push_back(curr);
            return;
        }
        curr.push_back(arr[i]);
        solve(i+1,n,target-arr[i],arr,curr,ans);
        curr.pop_back();
        while (i + 1 < n && arr[i] == arr[i + 1])i++;
        solve(i + 1, n, target, arr, curr, ans);


    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int>curr;
        vector<vector<int>>ans;
        sort(candidates.begin(),candidates.end());
        int n=candidates.size();
        solve(0,n,target,candidates,curr,ans);
        return ans;


        
    }
};
