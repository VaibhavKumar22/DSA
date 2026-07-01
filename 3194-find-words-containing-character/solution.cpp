class Solution {
public:

    void solve(vector<string>& words, char x,vector<int>&ans,int i){
        if(i==words.size())return;
        for(int j=0;j<words[i].length();j++){
            if(words[i][j]==x){

                ans.push_back(i);
                break;
            }
        }
        solve(words,x,ans,i+1);


    }
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int>ans;
        solve(words,x,ans,0);
        return ans;
        
    }
};
