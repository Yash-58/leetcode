class Solution {
public:
    bool solve(string &s,int start,unordered_set<string>&dict,vector<int>&dp){
        if(start==s.size()){
            return true;
        }
        if(dp[start]!=-1){
            return dp[start];
        }
        for(int i=start;i<s.size();i++){
            string word=s.substr(start,i-start+1);
            if(dict.count(word)){
                if(solve(s,i+1,dict,dp)){
                    return true;
                }
            }
        }
        return dp[start]=false;
    }
    bool wordBreak(string s, vector<string>& word) {
        unordered_set<string>dict(word.begin(),word.end());
        vector<int>dp(s.size(),-1);
        return solve(s,0,dict,dp);
        
    }
};