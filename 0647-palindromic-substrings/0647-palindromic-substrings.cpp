class Solution {
public:
    bool ispalindrome(int i,int j,string &a,vector<vector<int>>& dp){
        if(i>=j) return true;
        if(dp[i][j]!=-1) dp[i][j];
        if(a[i]!=a[j]) return false;

        return ispalindrome(i+1,j-1,a,dp);
    }
    int countSubstrings(string s) {
        int n=s.size(),count=0;
        vector<vector<int>> dp(n,vector<int>(n,-1));

        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(ispalindrome(i,j,s,dp))
                count++;
            }
        }
        return count;
    }
};