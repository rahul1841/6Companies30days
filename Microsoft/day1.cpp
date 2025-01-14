1401. Circle and Rectangle Overlapping
class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {

        // Note  - 
        // Circle Equation: Any point (x,y) lies within or on the boundary of the circle if:
        //                  (x−xCenter)^2 + (y−yCenter)^2 <= (radius)^2 
        // Rectangle Boundaries: A point (x,y) lies inside or on the boundary of the rectangle if:
                            // x1 <= x <= x2 and y1 <= y <= y2


        int r = radius * radius;
        for(int i = x1; i<=x2; i++){
            for(int j = y1; j<=y2; j++){
                double distance = (i - xCenter) * (i - xCenter) + (j - yCenter) * (j - yCenter);
                if(distance <= r){
                    return true;
                }
            }
        }
        return false;
    }
};


1823. Find the Winner of the Circular Game

class Solution {
public:
    int findTheWinner(int n, int k) {
        int winner = 0;
        for(int i = 2; i<=n; i++){
            winner = (winner + k) % i;
        }
        return winner + 1;
    }
};


354. Russian Doll Envelopes

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& E) {
        sort(E.begin(), E.end(), [](vector<int>& a, vector<int>& b) 
             -> bool {return a[0] == b[0] ? b[1] < a[1] : a[0] < b[0];});
        vector<int> dp;
        for (auto& env : E) {
            int height = env[1];
            int left = lower_bound(dp.begin(), dp.end(), height) - dp.begin();
            if (left == dp.size()) dp.push_back(height);
            dp[left] = height;
        }
        return dp.size();
    }
};


661. Image Smoother

class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int m = img.size(), n = img[0].size();
        vector<vector<int>> result(m, vector<int>(n));
        
        for (int r = 0; r < m; r++) 
        {
            for (int c = 0; c < n; c++) 
            {
                int sum = 0, count = 0;
                for (int dr = -1; dr <= 1; dr++) 
                {
                    for (int dc = -1; dc <= 1; dc++) 
                    {
                        int nr = r + dr;
                        int nc = c + dc;

                        if ((nr >= 0) && (nr < m) && (nc >= 0) && (nc < n)) 
                        {
                            sum += img[nr][nc];
                            count++;
                        }
                    }
                }
                result[r][c] = (sum / count);
            }
        }

        return result;
    }
};