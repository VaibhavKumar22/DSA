class Solution {
public:
    int maxDigitRange(vector<int>& nums) {
        unordered_map<int,int>mp;
        int largest=0;
        for(int a1:nums){
            int mnd=INT_MAX;
            int mxd=INT_MIN;
            int c=a1;
            while(c){
                int a=c%10;
                c/=10;
                mnd=min(mnd,a);
                mxd=max(mxd,a);
            }
            largest=max(largest,mxd-mnd);
            mp[mxd-mnd]+=a1;
        }
        return mp[largest];
        
    }
};
