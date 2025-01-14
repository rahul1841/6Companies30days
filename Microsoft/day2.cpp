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


299. Bulls and Cows

class Solution {
public:
    string getHint(string secret, string guess) {
        int count = 0;
        int mount = 0; 
        string ans = "";
        int hash[256] = {};
        for(int i = 0; i<secret.length();i++) {
            if(secret[i] == guess[i]) {
                count++;
            }
        }
        
        for(int i = 0; i < secret.length();i++) {
            hash[secret[i]]++;
        }
        for(int i = 0; i < guess.length();i++) {
            if(hash[guess[i]] > 0) { 
                mount++; 
                hash[guess[i]]--; 
            }
        }
        mount -= count;
        ans += to_string(count) + 'A' + to_string(mount) + 'B'; 
        return ans;
    }
};


1248. Count Number of Nice Subarrays

class Solution {
public:
    //  Instead of checking if a subarray has exactly k odd numbers, treat odd numbers as 1 and even numbers as 0 using nums[j] % 2.
    //  the problem then becomes equivalent to finding subarrays with a sum of k.
    int helper(vector<int> &nums, int goal){
        if(goal < 0) return 0;
        int n = nums.size();
        int i = 0, j = 0, sum = 0, count = 0;

        while(j < n){
            sum += nums[j] % 2;
            while(sum > goal){
                sum -= nums[i] % 2;
                i++;
            }
            count += (j - i + 1); // because 0 based indexing
            j++;
        }
        return count;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        return helper(nums, k) - helper(nums, k-1);
        // explanation eg:1
        // cnt subarrays with sum <= 3 - count subarrays with sum <=2  ==> cnt subarrays with sum = 3
    }
};