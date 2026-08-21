class Solution {
public:
    int subarraySum(vector<int>& pre, int k) {
        int n=pre.size();
        for(int i=1;i<pre.size();i++){
            pre[i]=pre[i]+pre[i-1];
        }
        unordered_map<int,int>mp;
        int count=0;
        for(int i=0;i<n;i++){
             if(pre[i]==k){
                count++;
             } 
             int rem=pre[i]-k;
             if(mp.find(rem)!=mp.end()) count +=mp[rem];
             mp[pre[i]]++;
        }
        return count;
    }
};