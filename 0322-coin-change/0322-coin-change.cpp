class Solution {
public:
    long Coin(int i,int amount,vector<int>& arr,vector<vector<long long>>& dp){
        if(i==arr.size()){
            if(amount==0) return 0;
            else return INT_MAX;
        }
        if(dp[i][amount]!=-1) return dp[i][amount];
        long skip=Coin(i+1,amount,arr,dp);
        if(amount-arr[i]<0) return dp[i][amount]=skip;
        long pick=1+Coin(i,amount-arr[i],arr,dp);

        return dp[i][amount]=min(pick,skip);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<long long>> dp(n,vector<long long>(amount+1,-1));

        int ans=(int)Coin(0,amount,coins,dp);
        if(ans==INT_MAX) return -1;
        else return ans;      
    }
};