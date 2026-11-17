class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        priority_queue<pair<int,int>>q;
        int n=score.size();
        for(int i=0;i<n;i++){
            q.push({score[i],i});
        }
        vector<string>ans(n);
        int rank=1;

        while(!q.empty()){
            int idx=q.top().second;
            q.pop();

            if(rank == 1)
                ans[idx] = "Gold Medal";
            else if(rank == 2)
                ans[idx] = "Silver Medal";
            else if(rank == 3)
                ans[idx] = "Bronze Medal";
            else
                ans[idx] = to_string(rank);

            rank++;
        }
        return ans;
    }
};