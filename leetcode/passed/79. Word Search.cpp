#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool dfs(vector<vector<char>>& board, const string& word, int i, int j, int word_index, vector<vector<bool>>& used){
        if(word_index == word.size()) return true;
        if(i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || used[i][j] || board[i][j] != word[word_index]){
            return false;
        }
        used[i][j] = true;
        bool found =dfs(board, word, i - 1, j, word_index + 1, used) ||
                    dfs(board, word, i + 1, j, word_index + 1, used) ||
                    dfs(board, word, i, j - 1, word_index + 1, used) ||
                    dfs(board, word, i, j + 1, word_index + 1, used);
        used[i][j] = false;
        return found;
    }

    bool exist(vector<vector<char>>& board, const string& word) {
        vector<vector<bool>> used(board.size(), vector<bool>(board[0].size(), false));
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++) {
                if(board[i][j] == word[0]){
                    if(dfs(board, word, i, j, 0, used)) return true;
                }
            }
        }
        return false;
    }
};
