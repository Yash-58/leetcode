class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>ans;
        unordered_map<string,vector<string>>mp;
        for(auto x:strs){
            string lexo=x;
            sort(lexo.begin(),lexo.end());
            if(mp.find(lexo)==mp.end()){
                vector<string>v;
                v.push_back(x);
                mp[lexo]=v;
            }
            else{
                mp[lexo].push_back(x);
            }
        }
        for(auto x:mp){
            vector<string>v=x.second;
            ans.push_back(v);
        }
        return ans;
    }
};