Q1:
718. Maximum Length of Repeated Subarray

class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (nums1[i] == nums2[j]) {
                    if (i == 0 || j == 0) dp[i][j] = 1;
                    else dp[i][j] = dp[i-1][j-1] + 1;
                    ans = max(ans, dp[i][j]);
                }
            }
        }
        return ans;
    }
};

Q2:
331. Verify Preorder Serialization of a Binary Tree

class Solution {
public:
    bool isValidSerialization(string preorder) {
        istringstream iss(preorder);
        string node;
        int availableSlots = 1;
        while (getline(iss, node, ',')) {
            if (--availableSlots < 0) {
                return false;
            }
            if (node != "#") {
                availableSlots += 2;
            }
        }
        return availableSlots == 0;
    }
};

Q3:
692. Top K Frequent Words

class Solution {
public:
    struct Compare {
        bool operator() (pair<int, string> a, pair<int, string> b) {
            if(a.first == b.first)
                return a.second > b.second;
            else
                return a.first < b.first;
        }
    };
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int>mp;
        for(auto i : words){
            mp[i]++;
        }
        priority_queue<pair<int, string>, vector<pair<int, string>>, Compare> pq;
        for(auto i:mp){
            pq.push({i.second,i.first});
        }
        vector<string>ans;
        while(k--){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};