class Solution {
public:
    int LPS(int i,int j,string &a,string &b,vector<vector<int>>& dp){
        if(i<0 || j<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(a[i]==b[j]){
            return dp[i][j]= 1+ LPS(i-1,j-1,a,b,dp);
        }
        else return dp[i][j]=max(LPS(i-1,j,a,b,dp),LPS(i,j-1,a,b,dp));
    }
    int minInsertions(string s) {
        int n=s.size();
        string rev=s;
        reverse(rev.begin(),rev.end());
        vector<vector<int>> dp(n,vector<int>(n,-1));
        
        return n-LPS(n-1,n-1,s,rev,dp);
        
    }
};