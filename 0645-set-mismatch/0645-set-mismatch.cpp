class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(auto x:nums) mp[x]++;
        
        int dup=-1,miss=-1;
        for(auto x:mp){
          if(x.second==2) dup=x.first;
        }
        for(int i=1;i<=nums.size();i++){
            if(mp.find(i)==mp.end()){
                miss=i;
                break;
            }
        }
        return {dup,miss};
    }
};