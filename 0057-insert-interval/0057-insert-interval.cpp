class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& in, vector<int>& newIn) {
        vector<vector<int>> ans;
        int i=0;
        int n=in.size();
        while(i<n && in[i][1]<newIn[0]){
            ans.push_back(in[i]);
            i++;
        }
        while(i<n && in[i][0]<=newIn[1]){
            newIn[0]=min(newIn[0],in[i][0]);
            newIn[1]=max(newIn[1],in[i][1]);
            i++;
        }
        ans.push_back(newIn);

        while(i<n){
            ans.push_back(in[i]);
            i++;
        }
        return ans;
    }
};