
class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int maxi = nums[0];
        int mini = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            maxi = max(maxi, nums[i]);
            mini = min(mini, nums[i]);
        }

        return 1LL * (maxi - mini) * k;
    }
};