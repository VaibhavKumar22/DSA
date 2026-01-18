class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int count=0;
        for(int i=0;i<sentences.size();i++){
            int count1=0;
            for(char a:sentences[i]){
                if(a==' '){
                count1++;
            }
            count=max(count,count1);

        }}
        return count+1;
        
        
    }
};
