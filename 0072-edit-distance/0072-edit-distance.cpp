class Solution {
public:
    int minstep(int i,int j,string &a,string &b,vector<vector<int>>& dp){
        if(i==-1) return j+1;
        if(j==-1) return i+1;
        if(dp[i][j]!=-1) return dp[i][j];
        if(a[i]==b[j]){
            return dp[i][j]=minstep(i-1,j-1,a,b,dp);
        }
        else{
            int del=minstep(i-1,j,a,b,dp);
            int ins=minstep(i,j-1,a,b,dp);
            int rep=minstep(i-1,j-1,a,b,dp);
            return dp[i][j]=1+min(del,min(ins,rep));
        }
    }
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));

        return minstep(n-1,m-1,word1,word2,dp);
    }
};