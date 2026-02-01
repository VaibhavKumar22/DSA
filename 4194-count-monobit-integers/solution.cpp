class Solution {
public:
    int s(int n){
        int a=-1;
        while(n){
            int c=n%2;
            if(a!=-1){
                if(c!=a)
                    return 0;
            }
            a=c;
            n/=2;
        }
        return 1;
    }
    int countMonobit(int n) {
        int count=0;
        for(int i=0;i<=n;i++){
             count+=s(i);
        }
        return count;
        
    }
};
