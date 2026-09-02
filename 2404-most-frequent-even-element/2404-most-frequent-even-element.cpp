class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(int x:nums){
            if(x%2==0){
                mp[x]++;
            }
        }
        int ans=-1;
        int maxfreq=0;
        for(auto x:mp){
            int num=x.first;
            int freq=x.second;

            if(freq>maxfreq || (freq==maxfreq && num<ans)){
                maxfreq=freq;
                ans=num;
            }
        }
        return ans;
    }
};