419. Battleships in a Board

class Solution {
public:
    void helper(vector<vector<char>>& board, int i, int j,vector<vector<int>> &vis, int &count)
    {
        if(i<0 || j<0 || i>=board.size() || j>=board[0].size() || vis[i][j]==1 || board[i][j] == '.')
            return;
        vis[i][j] = 1;
        helper(board, i+1,j,vis, count);
        helper(board, i-1,j,vis, count);
        helper(board, i,j+1,vis, count);
        helper(board, i,j-1,vis, count);
    }
    int countBattleships(vector<vector<char>>& board) {
        vector<vector<int>> vis(board.size(),vector<int>(board[0].size(),0));
        int count = 0;
        for(int i = 0;i<board.size();i++)
        {
            for(int j = 0; j<board[0].size();j++)
            {
                if(board[i][j] == 'X' and vis[i][j]==0)
                    {
                        helper(board, i, j, vis, count);
                        count++;
                    }
            }
        }
        return count;
    }
};