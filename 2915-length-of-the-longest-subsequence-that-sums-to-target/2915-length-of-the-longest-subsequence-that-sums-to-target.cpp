class Solution {
public:
    int Longest(int i,vector<int>& arr,int target,vector<vector<int>>& dp){
        if(i==arr.size()){
            if(target==0) return 0;
            else return INT_MIN;
        }
        if(dp[i][target]!=-1) return dp[i][target];
        int skip=Longest(i+1,arr,target,dp);
        if (arr[i] > target)
        return dp[i][target]=skip;
        int pick= 1+Longest(i+1,arr,target-arr[i],dp);

        return dp[i][target]=max(skip,pick);
    }
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        int n=nums.size();
        vector<vector<int>> dp(n,vector(target+1,-1));
        int ans= Longest(0,nums,target,dp);
        if(ans<0) return -1;
        else return ans;
        
    }
};