class Solution {
public:
    bool checkTwoChessboards(string c1, string c2) {
        int i1=c1[0]-'a';
        int j1=c1[1]-'1';
        int i2=c2[0]-'a';
        int j2=c2[1]-'1';
        return (i1 + j1) % 2 == (i2 + j2) % 2;
        
    }
};