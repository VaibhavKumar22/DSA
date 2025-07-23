class Solution {
public:
    int b1(int n){
        double a1=1;
        for(int i=1;i<=2;i++){
            a1=a1*(n-2+i)/i;
        }
        return (int)a1;

    }
    
    int numIdenticalPairs(vector<int>& nums) {
        vector<int> a(100+1,0);
        for(int i:nums){
            a[i]++;
        }
        int sum=0;
        for(int i:a){
            if(i>1){
                sum+=b1(i);
            }
        }
        return sum;

        
    }
};
