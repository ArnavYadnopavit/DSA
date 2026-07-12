class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ret;
        vector<string> board(n,string(n,'.'));
        backtrack(ret, board, n, 0);
        return ret;
    }
private:
    void backtrack(vector<vector<string>> &ret, vector<string> &board, const int &n, int r){
        if(r == n){
            ret.push_back(board);
            return;
        }
        for(int c = 0;c < n;c++){
            if(isSafe(r,c,board,n)){
                board[r][c]='Q';
                backtrack(ret,board,n,r+1);
                board[r][c]='.';
            }
        }
        return;
    }
    bool isSafe(int r,int c,vector<string> &board, int n){
        for(int i = r-1;i>=0;i--){
            if(board[i][c]=='Q') return false;
        }
        for(int i = r-1, j = c-1;i>=0 && j>=0;i--,j--){
            if(board[i][j]=='Q') return false;
        }
        for(int i = r-1, j = c+1;i>=0 && j<n;i--,j++){
            if(board[i][j]=='Q') return false;
        }
        return true;

    }
};
