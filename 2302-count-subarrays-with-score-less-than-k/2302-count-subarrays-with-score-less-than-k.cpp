class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        if(k<=1) return 0;
        int n=nums.size();
        int i=0,j=0;
        long long count=0;
        long long sum=0;

        while(j<n){
            sum +=(long long)(nums[j]);
            long long product=sum*(long long)(j-i+1);
            while(product>=k){
            sum -=(long long)(nums[i]);
            i++;
             product=sum*(long long)(j-i+1);
           }
            count +=(long long)(j-i+1);
           j++;
        }
           return count;
    }
};