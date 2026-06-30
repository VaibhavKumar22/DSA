class Solution {
public:
    void solve(int i,int n,int k,int target,vector<int>&arr,vector<int>&curr,vector<vector<int>>&ans){
        if(target<0)return ;
        if(i==n){
            if(target==0&&curr.size()==k)ans.push_back(curr);
            return ;
        }
        curr.push_back(arr[i]);
        solve(i+1,n,k,target-arr[i],arr,curr,ans);
        curr.pop_back();
        solve(i+1,n,k,target,arr,curr,ans);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
    vector<int>curr;
    vector<vector<int>>ans;
    int size=9;
    vector<int>numbers={1,2,3,4,5,6,7,8,9};
    solve(0,size,k,n,numbers,curr,ans);
    return ans;

    }

};
