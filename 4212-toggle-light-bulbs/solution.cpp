class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {
        map<int,int>mp;
        for(int i:bulbs){
            
                mp[i]++;
               
            
           
        }
        vector<int> ans;
        for(auto [a,b]:mp){
            if(b%2==1)
            ans.push_back(a);}
        sort(ans.begin(),ans.end());
        return ans;
        
        
    }
};
