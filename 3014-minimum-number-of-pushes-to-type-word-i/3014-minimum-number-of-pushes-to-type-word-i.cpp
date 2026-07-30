class Solution {
public:
    int minimumPushes(string word) {
        int n=word.size();
        int rem=n%8;
        int total8=n/8;
        int x=1;
        int ans=0;
        while(total8--){
            ans+=8*x;
            x++;
        }
        ans+=rem*x;
        return ans;

        

        
    }
};