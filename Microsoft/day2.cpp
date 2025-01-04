1823. Find the Winner of the Circular Game

approach 1:
class Solution {
public:
    int findTheWinner(int n, int k) {
        queue<int> q;
        for(int i = 1; i<=n; i++){
            q.push(i);
        }
        
        while(q.size() > 1){
            for(int i = 1; i<k; i++){
                q.push(q.front());
                q.pop();
            }
            q.pop();
        }
        return q.front();
    }
};

follow up sc- 0(1)
class Solution {
public:
    int findTheWinner(int n, int k) {
        int winner = 0; 
        for (int i = 2; i <= n; i++) {
            winner = (winner + k) % i; 
        }
        return winner + 1;
    }
};


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


462. Minimum Moves to Equal Array Elements II

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int mid = nums[n/2];
        int minimumMovesNeeded = 0;
    
        for(int i = 0; i<n; i++){
            minimumMovesNeeded += abs(nums[i] - mid);
        }
        return minimumMovesNeeded;
    }
};


497. Random Point in Non-overlapping Rectangles

class Solution {
public:
    
    map<int,vector<int>> mp ;
    int total_sum=0 ; 
    
    Solution(vector<vector<int>>& rects) {
   
        for(auto rect:rects){
                 
            int area=(rect[3]-rect[1]+1)*(rect[2]-rect[0]+1);
            total_sum+=area; 
            mp[total_sum]=rect ;
        }
    }
    
    vector<int> pick() {
        
        int r=rand()%total_sum ;
        auto temp=mp.upper_bound(r);
        
        vector z=temp->second;
            
        int x=z[0]+rand()%(z[2]-z[0]+1);
        int y=z[1]+rand()%(z[3]-z[1]+1) ;
        
        return {x,y} ;
        
        
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */

Reference for this question :   https://youtu.be/8kwPXbTMSnk?si=wIzXhFF7Ni2UTHt7


