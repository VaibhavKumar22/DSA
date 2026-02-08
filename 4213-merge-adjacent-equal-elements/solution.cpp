class Solution {
public:
    vector<long long> mergeAdjacent(vector<int>& nums) {
    vector<long long>ans;
        for(int i:nums){
            ans.push_back(i);
            while(ans.size()>=2&& ans.back()==ans[ans.size()-2]){
                long long v=ans.back();
                ans.pop_back();
                ans.back()+=v;
            }
        }
        return ans;
}};
