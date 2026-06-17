#include <vector>
#include <iostream>
#include <unordered_set>
using namespace std;
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        int cols = board[0].size();
         
        for(int i = 0;i<rows;i++){
            for(int j = 0; j<cols;j++){
                unordered_set <int> s;
                if(dfs(board,word,s,rows,cols,i,j,0)) return true;
            }
        }
        return false;
    }
private:
    bool dfs(vector<vector<char>>& board, string word,unordered_set <int> &s,int rows, int cols, int i,int j,int idx){
        cout <<idx <<endl;
        if(word[idx]!=board[i][j]) return false;
        if(idx==word.size()-1)return true;
        s.insert(i*cols+j);
        vector<pair<int,int>> dir={{1,0},{-1,0},{0,1},{0,-1}};
        for(auto d:dir){
            int a=i+d.first;
            int b=j+d.second;
            if(a>=0 && a<rows &&
               b>=0 &&  b<cols &&
               !s.count(a*cols+b)){
                if(dfs(board,word,s,rows,cols,a,b,idx+1)) return true;
            }
        }
        s.erase(i*cols+j);
        return false;


    }
    
};
