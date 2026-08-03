class Solution {
public:
    int solve(int i,int size,vector<int>& arr,vector<int>& dp){
        if(i>=size) return 0;
        if(dp[i]!=-1) return dp[i];

        int result=arr[i]-solve(i+1,size,arr,dp);
        if(i+1<size)
        result=max(result,arr[i]+arr[i+1]-solve(i+2,size,arr,dp));
        if(i+2<size)
        result=max(result,arr[i]+arr[i+1]+arr[i+2]-solve(i+3,size,arr,dp));
        return dp[i]=result;
    }
    string stoneGameIII(vector<int>& stone) {
        int n=stone.size();
        vector<int> dp(n+1,-1);

        int diff=solve(0,n,stone,dp);

        if(diff<0) return "Bob";
        else if(diff>0) return "Alice";
        else return "Tie";
        
    }
};