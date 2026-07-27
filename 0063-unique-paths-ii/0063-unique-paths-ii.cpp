class Solution {
public:

    int solve(int i,int j,vector<vector<int>>& grid,vector<vector<int>>& dp){
        if(i<0 || j<0) return 0;
        if(grid[i][j]) return 0;
        if (i==0 && j==0) return 1;
        if(dp[i][j] !=-1) return dp[i][j];
        int right=solve(i,j-1,grid,dp);
        int down=solve(i-1,j,grid,dp);
        return dp[i][j]=right+down;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        
        vector<vector<int>> dp(n,vector<int>(m,-1));
        
       return solve(n-1,m-1,grid,dp);
    }
};