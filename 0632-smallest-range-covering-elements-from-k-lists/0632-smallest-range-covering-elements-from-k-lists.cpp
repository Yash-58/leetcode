class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int k=nums.size();

        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>minHeap;
        int currMax=INT_MIN;
        for(int i=0;i<k;i++){
             minHeap.push({nums[i][0],i,0});
             currMax=max(currMax,nums[i][0]);
        }
        int ranStart=minHeap.top()[0];
        int ranEnd=currMax;
        while(minHeap.size()==k){
            auto top=minHeap.top();
            minHeap.pop();

            int currele=top[0];
            int currlist=top[1];
            int currIdx=top[2];

            if(currMax-currele<ranEnd-ranStart){
                ranStart=currele;
                ranEnd=currMax;
            }
            int nextIdx=currIdx+1;
            if (nextIdx == nums[currlist].size()) {
                break;
            }
            int nextVal=nums[currlist][nextIdx];
            minHeap.push({nextVal,currlist,nextIdx});
            currMax=max(currMax,nextVal);
        }
       return {ranStart,ranEnd}; 
    }
};