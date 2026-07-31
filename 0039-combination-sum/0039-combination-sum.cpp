class Solution {
public:
    void solve(int i, vector<int>& arr, int target,
               vector<vector<int>>& ans, vector<int>& curr) {

        if (i == arr.size()) {
            if (target == 0) {
                ans.push_back(curr);
            }
            return;
        }

        // Skip
        solve(i + 1, arr, target, ans, curr);

        // Pick
        if (arr[i] <= target) {
            curr.push_back(arr[i]);
            solve(i, arr, target - arr[i], ans, curr);
            curr.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> curr;

        solve(0, nums, target, ans, curr);

        return ans;
    }
};