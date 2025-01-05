1248. Count Number of Nice Subarrays

Extension of 930. Binary Subarrays With Sum
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


187. Repeated DNA Sequences

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        // sliding window approach
       int i = 0, j = 9;
       unordered_map<string, int> storeSubstrings;
       vector<string> repeatingSequences;

       while(j < s.size()){
        storeSubstrings[s.substr(i, j- i + 1)]++;
        i++;
        j++;
       }

       for(auto it : storeSubstrings){
        if(it.second > 1){
            repeatingSequences.push_back(it.first);
        }
       }
       return repeatingSequences;
    }
};


