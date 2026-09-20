class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if(nums.size()==1) return 0;
        sort(nums.begin(),nums.end());
        int maxdiff=0;
        for(int i=1;i<nums.size();i++){
            int val=abs(nums[i]-nums[i-1]);
            maxdiff=max(maxdiff,val);
        }
        return maxdiff;
    }
};