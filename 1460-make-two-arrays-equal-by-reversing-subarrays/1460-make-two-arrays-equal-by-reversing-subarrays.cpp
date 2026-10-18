class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        if(target.size()!=arr.size()) return false;
        unordered_map<int,int>mp;

        for(int x:target){
            mp[x]++;
        }
        for(int ele:arr){
            if(mp.find(ele)!=mp.end()){
                mp[ele]--;
                if(mp[ele]==0) mp.erase(ele);
            }
            else{
                return false;
            }
        }
        return true;
    }
};