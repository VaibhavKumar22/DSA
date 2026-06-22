class Solution {
public:
    int mostFrequent(vector<int>& nums, int key){
        unordered_map<int,int> freq;
        int result=-1;
        int maxfreq=0;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]==key){ freq[nums[i+1]]++;
            if(freq[nums[i+1]]>maxfreq){
                maxfreq=freq[nums[i+1]];
                result=nums[i+1];
            }}
        }
        return result;


    }
};
