1617. Count Subtrees With Max Distance Between Cities


class Solution {
public:
    int max_depth = 0, farthest_node = 0;

    bool isConnected(int &nodes, unordered_map<int, vector<int>> &adj, int curr, int depth  ){
        nodes = nodes^(1<<curr);
        if( depth>max_depth )
            max_depth = depth, farthest_node = curr;  
        max_depth = max( max_depth, depth );
        if( !nodes ) return true;
        int ans = false;
        for( auto num: adj[curr] )
            if( nodes & 1<<num )
                ans |= isConnected( nodes, adj, num, depth+1 );
        return ans;
    }
    
    vector<int> countSubgraphsForEachDiameter(int n, vector<vector<int>>& edges) {
        map<int,int> mp; unordered_map<int, vector<int>> adj;
        for( int i=0; i<edges.size(); i++ ){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        for( int num=1; num<pow(2,n+1); num++ ){
            if(!(num%2)){
                int curr = 1, temp = num/2;
                while( !(temp%2) )
                    curr++, temp /= 2;
                temp = num, max_depth = 0, farthest_node = curr;
                if(isConnected(temp, adj, curr, 0)){
                    temp = num;
                    isConnected(temp, adj, farthest_node, 0);
                    mp[max_depth]++;
                }
            } 
        }
        vector<int> ans(n-1,0);
        for( int i=1; i<n; i++ )
            if(mp[i]) ans[i-1]=mp[i];

        return ans;
    }
};


1568. Minimum Number of Days to Disconnect Island

class Solution {
public:
    void dfs(vector<vector<int>>& mat, int i, int j) {
        if (i < 0 || i >= mat.size() || j < 0 || j >= mat[0].size() ||
            mat[i][j] == 0)
            return;
        mat[i][j] = 0;
        dfs(mat, i + 1, j);
        dfs(mat, i - 1, j);
        dfs(mat, i, j + 1);
        dfs(mat, i, j - 1);
    }
    int countIslands(vector<vector<int>> grid) {
        int isl = 0;
        for(int i=0; i<grid.size(); i++) {
            for(int j=0; j<grid[0].size(); j++) {
                if(grid[i][j] == 1) {
                    isl++;
                    dfs(grid, i, j);
                }
            }
        }
        return isl;
    }
    int minDays(vector<vector<int>>& grid) {
        int n = countIslands(grid);
        if(n > 1 || n == 0) return 0;
        for(int i=0; i<grid.size(); i++) {
            for(int j=0; j<grid[0].size(); j++) {
                if(grid[i][j] == 1) {
                    grid[i][j] = 0;
                    int isl = countIslands(grid);
                    if(isl>1 || isl==0) return 1;
                    grid[i][j] = 1;
                }
            }
        }
        return 2;
    }
};


211. Design Add and Search Words Data Structure

class WordDictionary {
public:
    vector<string> v;
    WordDictionary() {
        
    }
    
    void addWord(string word) {
        v.push_back(word);
    }
    
    bool search(string word) {
        int count=0;
        int n=word.size();
        for(int i=0; i<v.size(); i++){
            if(n==v[i].size()){
                for(int j=0; j<n; j++){
                    if(v[i][j]==word[j]||word[j]=='.'){
                        count++;
                    }
                    else{
                        count=0;
                        break;
                    }
                }
                if(count==n) return true;
            }
        }
        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */


1530. Number of Good Leaf Nodes Pairs

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
 
class Solution {
public:
    int countPairs(TreeNode* root, int distance) {
        int result = 0;
        dfs(root, result, distance);
        return result;
    }

private:
    vector<int> dfs(TreeNode* node, int& result, int distance) {
        if (!node) return {};

        if (!node->left && !node->right) return {1};

        vector<int> leftDistances = dfs(node->left, result, distance);
        vector<int> rightDistances = dfs(node->right, result, distance);

        for (int l : leftDistances) {
            for (int r : rightDistances) {
                if (l + r <= distance) {
                    result++;
                }
            }
        }
        vector<int> currentDistances;
        for (int l : leftDistances) {
            if (l + 1 < distance) currentDistances.push_back(l + 1);
        }
        for (int r : rightDistances) {
            if (r + 1 < distance) currentDistances.push_back(r + 1);
        }

        return currentDistances;
    }
};
