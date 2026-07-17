class Solution {
public:
    void todo(int i,int val,vector<int>&arr,int&evensum,vector<int>&ans){
        if(arr[i]%2==0)evensum-=arr[i];
        arr[i]+=val;
        if(arr[i]%2==0)evensum+=arr[i];
        ans.push_back(evensum);
    }
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int evensum=0;
        int n=nums.size();
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(nums[i]%2==0)evensum+=nums[i];
        }
        // ans.push_back(evensum);
        for(auto e:queries){
            int i=e[1];
            int val=e[0];
            todo(i,val,nums,evensum,ans);
        }
        return ans;

    }
};