class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int> ans;
        ans.push_back(nums[0]);
        vector<int>v;
        v.push_back(nums[1]);
        for(int i=2;i<nums.size();i++){
            if(ans[ans.size()-1]>v[v.size()-1]){
                 ans.push_back(nums[i]);
            }
            else {
                v.push_back(nums[i]);
            }
        }
        ans.insert(ans.end(),v.begin(),v.end());
        return ans;
    }
};