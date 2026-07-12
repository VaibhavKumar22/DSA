class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int>ans;
        ans=arr;
        sort(ans.begin(),ans.end());
        unordered_map<int,int>mp;
        int a=1;
        for(int i=0;i<arr.size();i++){
            if(!mp[ans[i]]){
                mp[ans[i]]=a;
                a++;

            }
            
        }
        for(int i=0;i<arr.size();i++){
            arr[i]=mp[arr[i]];
        }
        return arr;
        
    }
};