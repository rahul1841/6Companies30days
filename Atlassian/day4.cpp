1385. Find the Distance Value Between Two Arrays

class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        sort(arr2.begin(), arr2.end());
        int count = 0;
        for(auto&num : arr1){
            auto it = lower_bound(arr2.begin(), arr2.end(), num);
            bool valid = true;
            if(it != arr2.end() && abs(*it - num) <= d){
                valid = false;
            }
            if(it != arr2.begin() && abs(*(it - 1) - num) <= d) {
                valid = false;
            }
            if(valid==true){
                count++;
            }
        }
        return count;
    }
};


2958. Length of Longest Subarray With at Most K Frequency

class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int ans=0;
        unordered_map<int,int>mp;
        int n=size(nums);

        for(int l=0,r=0;r<n;r++){
            mp[nums[r]]++;  
            if(mp[nums[r]]>k){
                while(nums[l]!=nums[r]){
                    mp[nums[l]]--;
                    l++;
                }
                mp[nums[l]]--;
                l++;
            }
            ans=max(ans,r-l+1);
        }
        return ans;
    }
};

2745. Construct the Longest New String

class Solution {
public: 
    int longestString(int x, int y, int z) {
        int mini = min(x, y);
        int extra = (x > y ? x-y : y-x) > 0 ? 1 : 0;
        int ans  = 2*(2*mini + extra + z);
        return ans;
    }
};

