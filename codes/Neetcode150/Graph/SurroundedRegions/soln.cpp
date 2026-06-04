#include <iostream>
#include <unordered_set>
#include <stack>
#include <vector>
using namespace std;
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int rows = board.size();
        int cols = board[0].size();

        for(int i=0 ;i < rows; i ++){
            for(int j=0 ; j< cols ; j++){
                if(board[i][j]=='O'){
                    dfs(board, i, j, rows, cols);
                }
            }
        }
        return;
    }
private:
void dfs(vector<vector<char>> &board, int i,int j, int rows, int cols){
    if(i==0 || j==0 || i == rows-1 || j == cols -1) return;
    stack <pair<int,int>> st;
    vector<vector<bool>> visited(rows, vector<bool>(cols,false));
    st.push({i,j});
    visited[i][j]=true;
    vector<pair<int,int>> dir = {{-1,0},{1,0},
                                 {0,-1},{0,1}};
    vector<pair<int,int>> changes;
    changes.push_back({i,j});
    int status=1;
    while(st.size()>0){
        
        int i = st.top().first;
        int j = st.top().second;
        st.pop();
        for(auto p:dir){
            if(!status) break;
            status &= addhelper(board, st, visited,changes, i+p.first,j+p.second, rows, cols);
        }
    }
    cout << i << j<< status << endl;
    if(!status) return;
    else{
        for(auto p:changes){
            board[p.first][p.second] = 'X';
        }
    }
    return;

}
int addhelper(vector<vector<char>> &board, stack <pair<int,int>> &st, vector<vector<bool>> &v,vector<pair<int,int>> &c, int i, int j, int rows, int cols){
    if(i >= 0 && j >= 0 && i<rows && j<cols && !v[i][j] && board[i][j]=='O'){
        st.push({i,j});
        v[i][j]=true;
        if(i==0 || j==0 || i==rows-1 || j==cols-1){
            return 0;
        }
        else{
            c.push_back({i,j});
            return 1;
        }
    }
    return 1;
}
};
