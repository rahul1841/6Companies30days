368. Largest Divisible Subset

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> groupSize(n, 1), prevElement(n, -1);
        int maxIndex = 0;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] % nums[j] == 0 && groupSize[i] < groupSize[j] + 1) {
                    groupSize[i] = groupSize[j] + 1;
                    prevElement[i] = j;
                }
            }
            if (groupSize[i] > groupSize[maxIndex]) {
                maxIndex = i;
            }
        }

        vector<int> result;
        for (int i = maxIndex; i != -1; i = prevElement[i]) {
            result.insert(result.begin(), nums[i]);
        }
        return result;
    }
};


2099. Find Subsequence of Length K With the Largest Sum


class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;// minheap 
        for(int i = 0; i < nums.size(); i++){
            q.push({nums[i], i});
            if (q.size() > k) {
                q.pop();
            }
        }
        map<int,int> m;
        while(!q.empty()){
            m.insert({q.top().second,q.top().first});
            q.pop();
        }
        vector<int>ans;
        for (auto&x : m){
            ans.push_back(x.second);
        }
        return ans;   
    }
};