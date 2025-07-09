class Solution {
public:
    int twoEggDrop(int n) {
        int k=1;
        int result=(k*(k+1))/2;
        while(result<n){
            k++;
            result=(k*(k+1))/2;
            
        }
        return k;
        
    }
};
