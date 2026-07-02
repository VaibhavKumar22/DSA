class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int sum=0;
        int i=0;
        int l=k;
        while(l--){
            sum+=nums[i++];
        }
        double maxa=(double)(sum)/k;
        int j=0;
        for(i;i<nums.size();i++){
            sum=sum+nums[i]-nums[j++];
            maxa=max(maxa,(double)(sum)/k);
        }
        return maxa;
        
    }
};