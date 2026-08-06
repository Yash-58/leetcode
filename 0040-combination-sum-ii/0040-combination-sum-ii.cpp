class Solution {
public:
    void combination(vector<int>& nums, int target, int idx,
                     vector<int>& temp,
                     vector<vector<int>>& ans) {

        if (target == 0) {
            ans.push_back(temp);
            return;
        }

        for (int i = idx; i < nums.size(); i++) {

            // Skip duplicates
            if (i > idx && nums[i] == nums[i - 1])
                continue;

            // Since array is sorted
            if (nums[i] > target)
                break;

            temp.push_back(nums[i]);

            combination(nums, target - nums[i], i + 1, temp, ans);

            temp.pop_back(); // Backtrack
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {

        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;
        vector<int> temp;

        combination(nums, target, 0, temp, ans);

        return ans;
    }
};