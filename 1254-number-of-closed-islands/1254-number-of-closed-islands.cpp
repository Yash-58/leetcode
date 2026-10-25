class Solution {
public:
    bool dfs(vector<vector<int>>& grid,int i,int j){
        int m=grid.size();
        int n=grid[0].size();

        if(i<0 || i>=m || j<0||j>=n){
            return false;
        }
        if(grid[i][j]){
            return true;
        }
        grid[i][j]=1;

        bool closed=(i > 0 && j > 0 && i < m - 1 && j < n - 1);

        bool up=dfs(grid,i-1,j);
        bool down=dfs(grid,i+1,j);
        bool left=dfs(grid,i,j-1);
        bool right=dfs(grid,i,j+1);

        return closed && up && down && left && right;
    }
    int closedIsland(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int count=0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0 && dfs(grid,i,j))
                     count++;
            }
        }
      return count;  
    }
};