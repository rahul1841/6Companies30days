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

451. Sort Characters By Frequency


class Solution {
public:
    string frequencySort(string s) {
        map<char,int>mpp1;
        multimap<int,char,greater<int>>mpp2;

        for(int i = 0;i<s.length();i++){
            mpp1[s[i]]++;
        }
        for(auto it:mpp1){
            mpp2.insert({it.second,it.first});
        }
     string ans ="";
     for(auto it:mpp2){
        string s="";
        int a = it.first;
        while(a){
            s+=it.second;
            a--;
        }
        ans+=s;
        }
        return ans;
    }
};


139. Word Break

class Solution {
public:
    int t[301][301];
    bool solve(int i, int j, string s, map<string, bool>& mp){
        string str = s.substr(i, j-i+1);
        if(mp.find(str) != mp.end())return true;

        if(t[i][j] != -1)return t[i][j];

        bool ans = false;
        for(int k = i; k < j; k++){
            ans = ans || (solve(i, k, s, mp) && solve(k+1, j, s, mp));
        }

        return t[i][j] = ans;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        memset(t, -1, sizeof(t));
        map<string, bool> mp;
        for(auto s : wordDict)mp[s] = true;

        return solve(0, s.length()-1, s, mp);
    }
};