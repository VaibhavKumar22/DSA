class Solution {
public:
    int minCost(vector<int>& startPos, vector<int>& homePos,
                vector<int>& rowCosts, vector<int>& colCosts) {

        int ans = 0;
        int i = startPos[0];
        int j = startPos[1];
        int i2 = homePos[0];
        int j2 = homePos[1];

        while(i < i2){
            i++;
            ans += rowCosts[i];
        }

        while(i > i2){
            i--;
            ans += rowCosts[i];
        }

        while(j < j2){
            j++;
            ans += colCosts[j];
        }

        while(j > j2){
            j--;
            ans += colCosts[j];
        }

        return ans;
    }
};