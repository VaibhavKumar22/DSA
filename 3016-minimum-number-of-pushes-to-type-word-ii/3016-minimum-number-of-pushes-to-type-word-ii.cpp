class Solution {
public:
    int minimumPushes(string word) {
        // unordered_map<char, int> freq;
        // for (char c : word) freq[c]++;
        // vector<pair<char, int>> v(freq.begin(), freq.end());
        // sort(v.begin(), v.end(), [](auto &a, auto &b) {
        // if (a.second == b.second)
        //     return a.first < b.first;
        // return a.second > b.second;
        // });
        // string ans;
        // for (auto &[ch, cnt] : v)ans += string(cnt, ch);
        unordered_map<char,int> mp;
        for(char c:word) mp[c]++;

        sort(word.begin(),word.end(),[&](char a,char b){
            return mp[a]==mp[b] ? a<b : mp[a]>mp[b];
        });
        mp.clear();
        int push=1;
        int ans=0;
        int inmp=0;
        for(char c:word){
            if(!mp[c]){
                mp[c]=push;
                inmp++;
                if(inmp==8)push++;
                if(inmp==16)push++;
                if(inmp==24)push++;

            }
            ans+=mp[c];
        }
        return ans;
        
    }
};