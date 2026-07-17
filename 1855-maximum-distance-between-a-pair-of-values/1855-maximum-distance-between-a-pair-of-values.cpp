class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int mx = 0;

        for(int i = 0; i < nums1.size(); i++) {
            int low = i, high = nums2.size() - 1;

            while(low <= high) {
                int mid = low + (high - low) / 2;

                if(nums2[mid] >= nums1[i]) {
                    mx = max(mx, mid - i); // valid pair
                    low = mid + 1; // try further right
                } else {
                    high = mid - 1;
                }
            }
        }
        return mx;
    }
};
