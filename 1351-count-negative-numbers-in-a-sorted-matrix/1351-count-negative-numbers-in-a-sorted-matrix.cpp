class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int row=grid.size();
        int col=grid[0].size()-1;

        int i=0;
        int ans=0;
        while(i<row && col>=0){
            if(grid[i][col]<0){
                ans+=row-i;
                col--;
            }
            else{
                i++;
            }
        }
       return ans; 
    }
};