class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n=nums.size();
        int ans=0;

        for(int i=0;i<n;i++){
            unordered_set<int>s;
            int odd=0,even=0;

            for(int j=i;j<n;j++){
                if(s.insert(nums[j]).second){
                    if(nums[j]%2==0)
                        even++;
                    else
                        odd++;
                }
                    if(even==odd){
                        ans=max(ans,j-i+1);
                    }
            }
        }
       return ans; 
    }
};