class Solution {
public:
    int digitSum(int x) {
        int sum = 0;
        while (x > 0) {
            sum += x % 10;
            x /= 10;
        }
        return sum;
    }
    int minSwaps(vector<int>& nums) {
        int n=nums.size();

        vector<pair<pair<int,int>,int>>arr;

        for(int i=0;i<n;i++){
            arr.push_back({{digitSum(nums[i]),nums[i]},i});
        }
        sort(arr.begin(),arr.end());

        vector<bool>visited(n,false);
        int swap=0;

        for(int i=0;i<n;i++){
            if(visited[i] || arr[i].second==i) continue;

            int j=i; 
            int size=0;   //for calculate cycle size
            while(!visited[j]){
                visited[j]=true;
                j=arr[j].second;
                size++;
            }
            swap+=size-1;
        }
        return swap;
    } 
};