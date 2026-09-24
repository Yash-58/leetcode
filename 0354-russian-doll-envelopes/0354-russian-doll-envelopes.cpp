class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
         sort(envelopes.begin(), envelopes.end(),
            [](vector<int>& a, vector<int>& b) {
                if (a[0] == b[0])
                    return a[1] > b[1];
                return a[0] < b[0];
            });
          vector<int>ans;
          for(auto num:envelopes){
            int height=num[1];
            if(ans.size()==0) ans.push_back(height);
            if(height>ans.back()){
                ans.push_back(height);
            }
            else{
                int index=lower_bound(ans.begin(),ans.end(),height)-ans.begin();
                ans[index]=num[1];
            }
          }
          return ans.size();  
    }
};