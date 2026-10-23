class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        int n=nums.size();
        vector<int>pre(n+1,0);

        for(int i=0;i<n;i++){
            pre[i+1]=pre[i]+nums[i];
        }
        int ans=0;
        int maxfirst=0;

        for(int i=firstLen+secondLen;i<=n;i++){
            int firstSum=pre[i-secondLen]-pre[i-secondLen-firstLen];

            maxfirst=max(maxfirst,firstSum);

            int secondSum=pre[i]-pre[i-secondLen];
            ans=max(ans,maxfirst+secondSum);
        }
        int maxSecond=0;

        for(int i=firstLen+secondLen;i<=n;i++){
            int secondSum=pre[i-firstLen]-pre[i-firstLen-secondLen];

            maxSecond=max(maxSecond,secondSum);

            int firstSum=pre[i]-pre[i-firstLen];
            ans=max(ans,maxSecond+firstSum);
        }
        return ans;
    }
};