class Solution {
public:
    string convertDateToBinary(string s) {
        int year=0;
        int month=0;
        int date=0;
        for(int i=0;i<4;i++){
            year=year*10+(s[i] - '0');
        }
        for(int i=5;i<7;i++){
            month=month*10+(s[i] - '0');
        }
        for(int i=8;i<10;i++){
            date=date*10+(s[i] - '0');
        }
        string ans="";
        while(date){
            ans+=(date%2+'0');
            date/=2;
        }
        ans+="-";
        while(month){
            ans+=(month%2+'0');
            month/=2;
        }
        ans+="-";
        while(year){
            ans+=(year%2+'0');
            year/=2;
        }
        reverse(ans.begin(), ans.end());
        return ans;

    }
};
