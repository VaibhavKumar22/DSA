class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> n={};
        for(int i=left;i<=right;i++){
            int j=i;
            int count=0;
            while(j>0){
                int m=j%10;
                if(m==0||i%m!=0){
                    count++;
                    break;
                }
                j=j/10;

                }
            if(count==0){
                n.push_back(i);

            }
            }
            return n;
        }
        
    };

