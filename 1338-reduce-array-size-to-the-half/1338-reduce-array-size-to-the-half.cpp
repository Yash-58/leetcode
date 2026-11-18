class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int,int>mp;

        for(int x:arr){
            mp[x]++;
        }
        priority_queue<int>pq;

        for(auto it:mp){
            pq.push(it.second);
        }
        int removed=0;
        int count=0;
        int n=arr.size();

        while(removed<n/2){
            removed+=pq.top();
            pq.pop();
            count++;
        }
       return count; 
    }
};