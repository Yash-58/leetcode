class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int sum=0;
        int j=0;
        double maxAvg=INT_MIN,avg=0;
        for(int i=0;i<k;i++){
            sum+=nums[i];
        }
        maxAvg=(double)sum/k;
        for(int i=k;i<nums.size();i++){
            sum+=nums[i]-nums[j];
            j++;
            avg=(double)sum/k;
            maxAvg=max(maxAvg,avg);
        }        
        return maxAvg;
    }
};