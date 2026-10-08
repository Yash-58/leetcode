class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int ans=2;
        int curr=2;

        for(int i=2;i<nums.size();i++){
            if(nums[i]==nums[i-1]+nums[i-2]){
                curr++;
                ans=max(ans,curr);
            }
            else{
                curr=2;
            }
        }
        return ans;
    }
};