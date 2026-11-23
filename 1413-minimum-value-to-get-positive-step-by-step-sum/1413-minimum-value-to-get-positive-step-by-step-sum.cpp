class Solution {
public:
    int minStartValue(vector<int>& nums) {
         int sum = 0, Min = 0;
        for(int num : nums){
            sum += num;
            Min =min(Min,sum);
        }
        return 1-Min;
    }
};