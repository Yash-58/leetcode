class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        int n=arr.size();
        unordered_map<int,int >mp;
        for(auto ele:arr){
            mp[ele]++;
        }
        unordered_set<int>s;
        for(auto x:mp){
            int freq=x.second;
            if(s.find(freq)!=s.end()) return false;
            else s.insert(freq);
        }
        return true;
    }
};