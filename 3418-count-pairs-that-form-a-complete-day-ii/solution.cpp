class Solution {
public:
    long long countCompleteDayPairs(vector<int>& hours) {
        vector<int>a(24,0);
        for(int i:hours){
            a[i%24]++;
        }
        long long int count=0;
        count+=1LL*a[0]*(a[0]-1)/2;
        for(int i=1;i<=24/2;++i){
            if(i!=24-i){
                count+=a[i]*a[24-i];
            }
            else{
                count+=a[i]*(a[i]-1)/2;
                }


        }
        return count;
        
    }
};
