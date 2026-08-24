class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& arr) {
        vector<vector<int>> ans;
        sort(arr.begin(),arr.end());
        for(auto x: arr){
            int start=x[0];
            int end=x[1];

            if(ans.empty() || start>ans.back()[1]){
                ans.push_back({start,end});
            }
            else{
                ans.back()[1]=max(ans.back()[1],end);
            }
        }
        return ans;
    }
};