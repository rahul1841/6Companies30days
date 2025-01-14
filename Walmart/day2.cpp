2385. Amount of Time for Binary Tree to Be Infected

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
    unordered_map<int, vector<int>> graph;

    int amountOfTime(TreeNode* root, int start) {
        constructGraph(root);

        queue<int> q;
        q.push(start);

        unordered_set<int> visited;

        int minutesPassed = -1;

        while (!q.empty()) {
            ++minutesPassed;
            for (int levelSize = q.size(); levelSize > 0; --levelSize) {
                int currentNode = q.front();
                q.pop();
                visited.insert(currentNode);
                for (int adjacentNode : graph[currentNode]) {
                    if (!visited.count(adjacentNode)) {
                        q.push(adjacentNode);
                    }
                }
            }
        }

        return minutesPassed;
    }

    void constructGraph(TreeNode* root) {
        if (!root) return;

        if (root->left) {
            graph[root->val].push_back(root->left->val);
            graph[root->left->val].push_back(root->val);
        }

        if (root->right) {
            graph[root->val].push_back(root->right->val);
            graph[root->right->val].push_back(root->val);
        }

        constructGraph(root->left);
        constructGraph(root->right);
    }
};


532. K-diff Pairs in an Array

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int n= nums.size();
        int count=0;
        sort(nums.begin(), nums.end());
        set<vector<int>>res;
        
        for(int i=0; i<n-1; i++){
            for(int j=i+1; j<n; j++){
                if(abs(nums[i]-nums[j])==k)
                    res.insert({nums[i], nums[j]});
            }
        }
        count = res.size();
        return count;
    }
};

2572. Count the Number of Square-Free Subsets

#include <bits/stdc++.h>
using namespace std;

const int M = 1e9 + 7;
vector<int> p = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
class Solution
{
public:
    int Madd(int a, int b)
    {
        a += b;
        if (a >= M)
            a -= M;
        return a;
    }

    int squareFreeSubsets(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> f(n, vector<int>(10));
        for (int i = 0; i < n; i++)
        {
            int x = nums[i];
            for (int j = 0; j < 10; j++)
            {
                while (x % p[j] == 0)
                {
                    x /= p[j];
                    f[i][j]++;
                }
            }
        }

        vector<vector<int>> dp(n + 1, vector<int>(1 << 10));
        for (int i = 0; i < n; i++)
        {
            dp[i + 1] = dp[i];

            bool ok = true;
            int mask = 0;

            for (int j = 0; j < 10; j++)
            {
                if (f[i][j] > 1)
                {
                    ok = false;
                    break;
                }
                if (f[i][j] == 1)
                {
                    mask |= (1 << j);
                }
            }

            if (ok)
            {
                for (int j = 0; j < (1 << 10); j++)
                    if ((j & mask) == 0)
                        dp[i + 1][j | mask] = Madd(dp[i + 1][j | mask], dp[i][j]);

                dp[i + 1][mask] = Madd(dp[i + 1][mask], 1);
            }
        }

        int ans = 0;
        for (int i = 0; i < (1 << 10); i++)
            ans = Madd(ans, dp[n][i]);
        return ans;
    }
};


1208. Get Equal Substrings Within Budget

class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int l = 0, cost = 0, result = 0;

        for (int r = 0; r < s.length(); r++) {
            cost += abs(s[r] - t[r]);

            while (cost > maxCost) {
                cost -= abs(s[l] - t[l]);
                l++;
            }

            result = max(result, r - l + 1);
        }

        return result;
    }
};