class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        int maxi=-1;
        map<int,int>mp;
        int c=-1;
        for(int x:nums){
            if(x%2==0){
                mp[x]++;
                if(mp[x]>maxi){
                    maxi=mp[x];
                    c=x;
                }
                else if(mp[x]==maxi){
                    c=min(c,x);
                }
            }
        }
        return c;
        
        
        
    }
};
