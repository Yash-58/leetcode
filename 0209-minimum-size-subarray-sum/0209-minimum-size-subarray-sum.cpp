class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        int len=0,minlen=INT_MAX;
        int j=0,i=0,sum=0;
        while(j<n){
            sum +=nums[j];
            while(sum>=target){
                len=j-i+1;
                minlen=min(minlen,len);
                sum-=nums[i];
                i++;
            }
            j++;
        }
        if(minlen==INT_MAX) return 0;
        else return minlen;
    }
};