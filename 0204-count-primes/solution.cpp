class Solution {
public:
    int countPrimes(int n) {
      vector<bool>a(n+1,true);
      a[0]=false;
      a[1]=false;
      int count=0;
      for(int i=2;i<n;i++){
        if(a[i]==false){
            continue;
        }
        count++;
        for(long long int j=1LL*i*i;j<=n;j=j+i){
            a[j]=false;
        }
      }
      return count;
        
        
    }
};
