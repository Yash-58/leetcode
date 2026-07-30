class Solution {
public:
    int sum;
    int Ways(int i,vector<int>& arr,int res,int target,vector<vector<int>>& dp){
        if(i==arr.size()){
            if(res==target) return 1;
            else return 0;
        }
        if(dp[i][res+sum]!=-1) return dp[i][res+sum];
        int add=Ways(i+1,arr,res+arr[i],target,dp);
        int sub=Ways(i+1,arr,res-arr[i],target,dp);

        return dp[i][res+sum]=add+sub;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        sum=0;
        int n=nums.size();
        for(int ele:nums) sum+=ele;
        vector<vector<int>> dp(n,vector<int>(2*sum+1,-1));
        return Ways(0,nums,0,target,dp);
    }
};