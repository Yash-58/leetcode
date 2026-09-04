class Solution {
public:
    bool dfs(vector<vector<char>>& board,int i,int j,string word,int idx){
        if(idx==word.size()) return true;
        if(i<0||i>=board.size()||j<0||j>=board[0].size()||word[idx]!=board[i][j]){
            return false;
        }
        char temp=board[i][j];
        board[i][j]='#';

        bool found=dfs(board,i+1,j,word,idx+1)||dfs(board,i-1,j,word,idx+1)||dfs(board,i,j+1,word,idx+1)||dfs(board,i,j-1,word,idx+1);

        board[i][j]=temp;
        return found;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(dfs(board,i,j,word,0)){
                    return true;
                }
            }
        }
       return false; 
    }
};