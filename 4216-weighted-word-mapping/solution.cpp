class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans="";
        for(string c:words){
            int count=0;
            for(char a:c){
                count+=weights[a-'a'];
            }
            count=count%26;
            
            ans += char('z' - count); 
            
            
        }
        return ans;
    }
};
