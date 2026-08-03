class Solution {
public:
    int solve(int i,int j,vector<int>& arr,vector<vector<int>>& dp){
        if(i==j) return arr[i];
        if(dp[i][j]!=-1) return dp[i][j];
        int left=arr[i]-solve(i+1,j,arr,dp);
        int right=arr[j]-solve(i,j-1,arr,dp);

        return dp[i][j]=max(left,right);
    }
    bool stoneGame(vector<int>& piles) {
        int n=piles.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));

        return solve(0,n-1,piles,dp)>0;
        
    }
};