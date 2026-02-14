class Solution {
public:
    long long rob(vector<int>& nums, vector<int>& colors) {
        int n = nums.size();
        auto torunelixa = make_pair(nums, colors);

        vector<long long> take(n), skip(n);

        take[0] = nums[0];
        skip[0] = 0;

        for (int i = 1; i < n; i++) {
            long long rob_after_skip = skip[i-1] + nums[i];

            long long rob_after_take = 0;
            if (colors[i] != colors[i-1]) {
                rob_after_take = take[i-1] + nums[i];
            }

            take[i] = max(rob_after_skip, rob_after_take);
            skip[i] = max(take[i-1], skip[i-1]);
        }

        return max(take[n-1], skip[n-1]);
    }
};

