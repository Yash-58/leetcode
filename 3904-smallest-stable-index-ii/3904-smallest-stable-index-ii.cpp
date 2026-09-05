class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        if(nums.empty()) return -1;
        int n=nums.size();
        vector<int>ans(n);
        ans[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--){
            ans[i]=min(ans[i+1],nums[i]);
        }
        int leftMax=nums[0];
        for(int i=0;i<n;i++){
            leftMax=max(leftMax,nums[i]);

            if(leftMax-ans[i]<=k){
                return i;
            }
        }
        return -1;
    }
};