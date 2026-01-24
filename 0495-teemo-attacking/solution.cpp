class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int sum=0;
        for(int i=0;i<timeSeries.size()-1;i++){
            int a=duration;
            int b=timeSeries[i];
            while(b++!=timeSeries[i+1]&&a--)sum++;
        

        }

        return sum+duration;
        
    }
};
