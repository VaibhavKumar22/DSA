class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> value(candies.size());
        int maximum=0;
        for(int a:candies){
            maximum=max(maximum,a);
        }
        for(int i=0;i<candies.size();i++){
            if((candies[i]+extraCandies)>=maximum){
                value[i]=true;}
            else {
                value[i]=false;}

        }
        return value;
        
    }
};
