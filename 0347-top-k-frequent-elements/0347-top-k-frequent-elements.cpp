class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        vector<int>ans;
        for(int x:nums){
           mp[x]++;
        }
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>minHeap;
        for(auto x:mp){
            minHeap.push({x.second,x.first});
            if(minHeap.size()>k){
                minHeap.pop();
            }
        }
            while(!minHeap.empty()){
                ans.push_back(minHeap.top()[1]);
                minHeap.pop();
        }
       return ans;
    }
};