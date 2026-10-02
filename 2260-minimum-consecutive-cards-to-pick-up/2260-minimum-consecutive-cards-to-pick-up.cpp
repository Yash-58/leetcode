class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        int n=cards.size();
        unordered_map<int,int>mp;
        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            if(mp.find(cards[i]) !=mp.end()){
                int length=i-mp[cards[i]]+1;
                ans=min(ans,length);
            }
            mp[cards[i]]=i;
        }
        if(ans==INT_MAX) return -1;
        else return ans;
    }
};