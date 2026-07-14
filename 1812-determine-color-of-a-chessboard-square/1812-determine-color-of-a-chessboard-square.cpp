class Solution {
public:
    bool squareIsWhite(string c1) {
        int i=c1[0]-'a';
        int j=c1[1]-'1';
        return (i+j)%2==1;
    }
};