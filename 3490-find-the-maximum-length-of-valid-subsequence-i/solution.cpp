

class Solution {
public:
    int maximumLength(std::vector<int>& nums) {
        int count_evens = 0; 
        int count_odds = 0;

        int dp_ends_with_even = 0;
        int dp_ends_with_odd = 0;

        for (int num : nums) {
            if (num % 2 == 0) { 
                count_evens++;
                dp_ends_with_even = dp_ends_with_odd + 1;
            } else { 
                count_odds++;
                dp_ends_with_odd = dp_ends_with_even + 1;
            }
        }

        int max_len_same_parity = std::max(count_evens, count_odds);
        int max_len_alternating_parity = std::max(dp_ends_with_even, dp_ends_with_odd);

        return std::max(max_len_same_parity, max_len_alternating_parity);
    }
};
