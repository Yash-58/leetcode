class Solution {
public:
    vector<int> zigzagTraversal(vector<vector<int>>& grid) {
        vector<int> ans;
        int row=grid.size();
        int col=grid[0].size();

        bool take=true;
        for(int i=0;i<row;i++){
            if(i%2==0){
                for(int j=0;j<col;j++){
                    if(take) ans.push_back(grid[i][j]);
                        take=!take;
                }
            }
            else{
                for(int j=col-1;j>=0;j--){
                    if(take) ans.push_back(grid[i][j]);
                        take=!take;
                }
            }
        }
        return ans;
    }
};