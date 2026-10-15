class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        mp[0]=1;
        int ans=0;
        int prefix=0;

        for(int right=0;right<nums.size();right++){
              if(nums[right]%2!=0){
                prefix++;
              }

             if(mp.count(prefix-k)){
                ans+=mp[prefix-k];
             }
             mp[prefix]++;
        }
      return ans;  
    }
};