class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        vector<int>ans=nums;
        int n=ans.size();
        deque<int>maxdq,mindq;

        long long result=0;
        int l=0;

        for(int i=0;i<n;i++){
            while(!maxdq.empty()&&ans[maxdq.back()]<=ans[i])
                maxdq.pop_back();
            maxdq.push_back(i);
            while(!mindq.empty()&&ans[mindq.back()]>=ans[i])
                mindq.pop_back();
            mindq.push_back(i);

            while(l<=i){
                long long mx=ans[maxdq.front()];
                long long mn=ans[mindq.front()];
                long long len=i-l+1;

                long long cost=(mx-mn)*len;
                if(cost<=k)break;

                if(maxdq.front()==l)maxdq.pop_front();
                if(mindq.front()==l)mindq.pop_front();
                l++;
                
            }
            result+=(i-l+1);
            
        }
        return result;
        
    }
};
