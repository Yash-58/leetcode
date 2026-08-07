class Solution {
public:
    bool isSafe(vector<string>& board,int row,int col){
        int n=board.size();
        for(int i=0;i<n;i++){
            if(board[i][col]=='Q') return false;
        }
         for(int j=0;j<n;j++){
            if(board[row][j]=='Q') return false;
        }
        int i=row;
        int j=col;
        while(i>=0 && j<n){
            if(board[i][j]=='Q') return false;
            i--,j++;
        }
         i=row;
         j=col;
        while(i<n && j<n){
            if(board[i][j]=='Q') return false;
            i++,j++;
        }
         i=row;
         j=col;
        while(i<n && j>=0){
            if(board[i][j]=='Q') return false;
            i++,j--;
        }
         i=row;
         j=col;
        while(i>=0 && j>=0){
            if(board[i][j]=='Q') return false;
            i--,j--;
        }
        return true;
    }
    void nqueens(vector<string>& board,int row,vector<vector<string>>& ans,int n){
        if(row==n){
            ans.push_back(board);
            return;
        }
        for(int j=0;j<n;j++){
            if(isSafe(board,row,j)){
                board[row][j]='Q';
                nqueens(board,row+1,ans,n);
                board[row][j]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n,string(n,'.'));

        nqueens(board,0,ans,n);
        return ans;
        
    }
};