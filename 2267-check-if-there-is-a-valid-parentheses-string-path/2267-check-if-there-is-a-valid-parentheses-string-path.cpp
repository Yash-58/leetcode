class Solution {
public:
    int n,m;
    bool solve(vector<vector<char>>& grid,int row,int col,int balance,vector<vector<vector<int>>>&dp){
        if(balance<0){
            return false;
        }
        if(row==n-1 && col==m-1){
            return balance==0;
        }
        if(dp[row][col][balance]!=-1){
            return dp[row][col][balance];
        }

        if(row+1<n){
            int nb=balance+(grid[row+1][col]=='('?1:-1);
            if(solve(grid,row+1,col,nb,dp)){
               return dp[row][col][balance]=true;
            }
        }

        if(col+1<m){
            int nb=balance+(grid[row][col+1]=='('?1:-1);
            if(solve(grid,row,col+1,nb,dp)){
                return dp[row][col][balance]=true;
            }
        }
        return dp[row][col][balance]=false;
    }
    bool hasValidPath(vector<vector<char>>& grid) {
        n=grid.size();
        m=grid[0].size();

        if(grid[0][0]==')') return false;
        int len=m+n-1;

        if(len%2==1){
            return false;
        }
        vector<vector<vector<int>>>dp(
            n,vector<vector<int>>(
                m,vector<int>(
                    len+1,-1
                )
            )
        );
        return solve(grid,0,0,1,dp);
    }
};