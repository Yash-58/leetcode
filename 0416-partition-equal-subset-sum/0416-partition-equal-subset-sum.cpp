class Solution {
public:
    bool subset(int i,int target,vector<int>& arr,vector<vector<int>> &dp){
        if(i==arr.size()){
            if(target==0) return true;
            else return false;
        }
        if(dp[i][target]!=-1) return dp[i][target];
        bool skip=subset(i+1,target,arr,dp);
        if(target<0) return skip;
        bool pick = false;
        if (arr[i] <= target)
        pick = subset(i + 1, target - arr[i], arr, dp);

        return dp[i][target]=skip || pick;
   }
    bool canPartition(vector<int>& nums) {
        int sum=0,n=nums.size();
        for(int ele:nums) sum+=ele;
        if(sum%2!=0) return false;

        int target=sum/2;
        vector<vector<int>> dp(n,vector<int>(target+1,-1));
        return subset(0,target,nums,dp);
        
    }
};