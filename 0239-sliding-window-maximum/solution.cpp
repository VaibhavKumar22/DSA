class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;   // stores indices
        vector<int> ans;

        for (int i = 0; i < nums.size(); i++) {

            // 1. Remove elements out of current window
            if (!dq.empty() && dq.front() == i - k)
                dq.pop_front();

            // 2. Remove smaller elements (they'll never be max)
            while (!dq.empty() && nums[dq.back()] < nums[i])
                dq.pop_back();

            // 3. Add current element index
            dq.push_back(i);

            // 4. Window ready → store max
            if (i >= k - 1)
                ans.push_back(nums[dq.front()]);
        }

        return ans;
    }
};

