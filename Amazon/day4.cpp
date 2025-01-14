297. Serialize and Deserialize Binary Tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == NULL) return "";
        string str;
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            if(node == NULL){
                str.append("#,");
            }
            else{
                str.append(to_string(node->val)+",");
            }
            if(node != NULL){
                q.push(node->left);
                q.push(node->right);
            }
        }
        return str;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size() == 0) return NULL;
        stringstream s(data);
        string str;
        getline(s,str,',');
        TreeNode* root = new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            getline(s,str,',');
            if(str == "#"){
                node->left = NULL;
            }
            else{
                TreeNode* leftNode = new TreeNode(stoi(str));
                node->left = leftNode;
                q.push(leftNode);
            }
            getline(s,str,',');
            if(str == "#"){
                node->right = NULL;
            }
            else{
                TreeNode* rightNode = new TreeNode(stoi(str));
                node->right = rightNode;
                q.push(rightNode);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));


168. Excel Sheet Column Title


class Solution {
public:
    string convertToTitle(int columnNumber) {


        string s = "";
        while(columnNumber > 0){
            columnNumber--;

            int rem = columnNumber % 26;
            s += char('A' + rem);
            columnNumber /= 26;
        }

        reverse(s.begin(), s.end());
        return s;
    }
};


994. Rotting Oranges


class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        int time = 0;
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));

        // r, c, t
        queue<pair<pair<int, int>, int> > q; 

        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j] == 2){
                    vis[i][j] = 2;
                    q.push({{i, j}, 0});
                }
            }
        }

        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int t = q.front().second;
            q.pop();

            time = max(time, t);

            int delr[] = {-1, 0, 1, 0};
            int delc[] = {0, 1, 0, -1};

            for(int i = 0; i<4; i++){
                int nrow = row + delr[i];
                int ncol = col + delc[i];

                if((nrow >= 0 && nrow < n) && (ncol >= 0 && ncol < m) && (vis[nrow][ncol] != 2) 
                    && (grid[nrow][ncol] == 1)){
                        vis[nrow][ncol] = 2;
                        q.push({{nrow, ncol}, t + 1});
                    }
            }
        }

        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j] == 1 && vis[i][j] != 2) return -1;
            }
        }
        return time;
    }
};