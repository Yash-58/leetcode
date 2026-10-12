
class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int maxLen = 0;
        int i = 0;
        int mask = 0;

        for (int j = 0; j < nums.size(); j++) {
            while ((mask & nums[j]) != 0) {
                mask ^= nums[i];
                i++;
            }

            mask |= nums[j];
            maxLen = max(maxLen, j - i + 1);
        }

        return maxLen;
    }
};