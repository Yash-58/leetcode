class Solution {
public:
    int sum;
    int Ways(int i,vector<int>& arr,int res,int target){
        if(i==arr.size()){
            if(res==target) return 1;
            else return 0;
        }
        int add=Ways(i+1,arr,res+arr[i],target);
        int sub=Ways(i+1,arr,res-arr[i],target);

        return add+sub;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        sum=0;
        int n=nums.size();
        for(int ele:nums) sum+=ele;
        return Ways(0,nums,0,target);
    }
};