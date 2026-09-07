class Solution {
public:
    int ways(int i,string &s,vector<int> &dp){
        int n=s.size();
        if(i==n) return 1;
        if(s[i]=='0') return 0;
        if(dp[i]!=-1) return dp[i];
        int way=ways(i+1,s,dp);

        if(i+1<n){
             int num = (s[i] -'0') * 10 + (s[i + 1] - '0');
            if(num>=10 && num<=26){
                way+=ways(i+2,s,dp);
            }
        }
        return dp[i]= way;
    }
    int numDecodings(string s) {
        int n=s.size();
        vector<int>dp(n,-1);
       return ways(0,s,dp); 
        
    }
};