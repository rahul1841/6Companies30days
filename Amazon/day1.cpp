188. Best Time to Buy and Sell Stock IV

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if (n == 0) return 0;
        
        int t[n + 1][2][k + 1];
        memset(t, 0, sizeof(t));

        for(int idx = n-1; idx>=0; idx -- ){
            for(int buy = 0; buy <=1; buy++){
                for(int cap = 1; cap<=k; cap++){
                    if(buy){
                        t[idx][buy][cap] = max(-prices[idx] + t[idx+1][0][cap], 0 + t[idx+1][1][cap]);
                    }
                    else{
                        t[idx][buy][cap] = max(prices[idx] + t[idx+1][1][cap-1], 0 + t[idx+1][0][cap]);
                    }
                }
            }
        }
        // idx == 0, buy can be done i.e buy = 1, and cap should be max i.e cap = k;
        return t[0][1][k];
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


