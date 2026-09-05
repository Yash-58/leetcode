class Solution {
public:
    void sum(int start,int k,int n,vector<int> &curr,vector<vector<int>> &ans){
        if(curr.size()==k){
            if(n==0){
                ans.push_back(curr);
            }
            return;
        }
        for(int i=start;i<=9;i++){
            if(i>n) break;
            curr.push_back(i);
            sum(i+1,k,n-i,curr,ans);
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>ans;
        vector<int>curr;
         sum(1,k,n,curr,ans);
         return ans;
        
    }
};