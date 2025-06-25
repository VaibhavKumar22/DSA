class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        vector<int> a(60,0);
        for(int n:time){
            a[n%60]++;
        }
        long long int count=0;
        count+=1LL*a[0]*(a[0]-1)/2;
        for(int i=1;i<=60/2;++i){
            if(i!=60-i){
                count+=a[i]*a[60-i];
            }
            else{
                count+=a[i]*(a[i]-1)/2;
            }
        }
        return count;
    }
};
