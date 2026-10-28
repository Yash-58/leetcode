class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int>st;
        unordered_map<int,int>mp;

        for(int i=nums2.size()-1;i>=0;i--){
            int curr=nums2[i];

            while(!st.empty() && curr>=st.top()){
                st.pop();
            }
            if(!st.empty()){
                mp[curr]=st.top();
            }
            else{
                mp[curr]=-1;
            }
            st.push(curr);
        }
        vector<int>ans;
        for(int x:nums1){
            ans.push_back(mp[x]);
        }
        return ans;
    }
};