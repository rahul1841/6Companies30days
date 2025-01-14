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

845. Longest Mountain in Array

class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n=arr.size(),res=0,answer=0;
        bool wasInc=false;
        bool wasIncAndNowDcr=false;
        for(int i=1;i<n;i++){
            if(arr[i] > arr[i-1]){
                if(wasIncAndNowDcr==true){
                    answer=0;
                    wasIncAndNowDcr=false;
                }
                answer++;
                wasInc=true;
            } 
            else if(arr[i] < arr[i-1] && (wasInc || wasIncAndNowDcr)){
                answer++;
                wasIncAndNowDcr=true;
                res=max(res,answer+1);
            }
            else if(arr[i]==arr[i-1]){
                answer=0;
                wasIncAndNowDcr=false;
                wasInc=false;
            }
        }
        return res;
    }
};

2461. Maximum Sum of Distinct Subarrays With Length K

class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long n = nums.size(), ws = 0, mx = 0;
        unordered_map<int, int> mp;

        for (int i = 0; i < n; i++) {
            mp[nums[i]]++;
            ws += nums[i];
            if (i >= k) {
                int le = nums[i - k];
                mp[le]--;
                ws -= le;
                if (mp[le] == 0) {
                    mp.erase(le);
                }
            }
            if (i >= k - 1 && mp.size() == k) {
                mx = max(mx, ws);
            }
        }
        return mx;
    }
};