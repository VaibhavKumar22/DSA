class Solution {
public:
    bool isFascinating(int n) {
        if(n%10==0){
            return false;
        }
        string a=to_string(n)+to_string(2*n)+to_string(3*n);
        char t='0';
        for(int i=0;i<a.length();i++){
            if(a[i]==t){
                return false;
            }
            char a1=a[i];
            for(int j=i+1;j<a.length();j++ ){
                if(a1==a[j]){
                    return false;
                }
            }
        }
        return true;
        
    }
};
