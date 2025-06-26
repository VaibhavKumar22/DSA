class Solution {
public:
    int valueAfterKSeconds(int n, int k) {
        vector<int>a(n,1);
        for(int i=1;i<=k;i++){
            for(int j=1;j<n;j++){
                a[j]=(a[j]+a[j-1])%1000000007;
            }
            // for(int j=0;j<n;j++){
            //     cout<<a[j]<<" ";
            // }
            // cout<<"\n";
        }
        return (a[n-1]);
        // return 0;
        // return a[n-1]% (pow(10,9)+7);
        
    }
};
