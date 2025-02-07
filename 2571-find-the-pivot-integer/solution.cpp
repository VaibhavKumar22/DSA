class Solution {
public:
    int pivotInteger(int n) {
    
        for(int i=1;i<=n;i++){
            int sum =0;
            for(int j=1;j<=i;j++){
                sum=sum+j;
            }
            int sum2=0;
            for(int j=i;j<=n;j++){
                sum2+=j;
            }
            if (sum==sum2){
                return i;
                
            }
        }
        return -1;
        
        
    }
};
