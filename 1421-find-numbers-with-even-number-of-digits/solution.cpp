class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int count=0;
        for(int a:nums){
            int c=0;
            while(a>0){
                c++;
                a=a/10;
                }
            if(c%2==0){
                count++;
            }
        }
        return count;
        
    }
};
