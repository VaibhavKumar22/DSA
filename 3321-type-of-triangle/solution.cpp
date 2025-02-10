class Solution {
public:
    string triangleType(vector<int>& num) {
        if(num[0]==num[1]&&num[1]==num[2]){
            return "equilateral";
        }
        else if(num[0]==num[1]||num[1]==num[2]||num[0]==num[2]){
            if(num[0]+num[1]>num[2]&&num[0]+num[2]>num[1]&&num[1]+num[2]>num[0]){
                return "isosceles";
            }
        }else{
            if(num[0]+num[1]>num[2]&&num[0]+num[2]>num[1]&&num[1]+num[2]>num[0]){
                return "scalene";
            }

        }

        return "none";
    }
};
