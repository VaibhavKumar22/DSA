class Solution {
public:
    int prefixConnected(vector<string>& words, int k) {
        map<string,int>mp;
        for(string a:words){
            if(a.size()<k)continue;
            string c=a.substr(0,k);
            mp[c]++;
        }
        int count=0;
        for(auto [a,freq]:mp){
            if(freq>=2)count++;
            
        }
        return count;
    }
};
