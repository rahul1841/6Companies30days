2970. Count the Number of Incremovable Subarrays I

class Solution {
public:
    int incremovableSubarrayCount(vector<int>& nums) {
        int n = nums.size();
        int count = 0;

        if (n == 1) return 1;

        for (int i = 0; i < n; i++)
        {
            unordered_map<int, int> mp;

            for (int j = i; j < n; j++)
            {
                vector<int> temp;
                mp[j]++;
                bool helpme = false;

                for (int k = 0; k < n; k++) {
                    if (mp.find(k) == mp.end())
                    {
                        temp.push_back(nums[k]);
                    }
                }
                if (temp.size() == 1) count += 1;
                else if (temp.size() == 0) count += 1;
                else 
                {
                    for (int m = 0; m < temp.size() - 1; m++)
                    {
                        if (temp[m] >= temp[m + 1]) helpme = true;
                    }

                    if (helpme == false) count += 1;
                }
            }
        }
        return count;
    }
};


2002. Maximum Product of the Length of Two Palindromic Subsequences

class Solution {
public:
    int result = 0;
    bool isPalin(string& s){
        int i = 0;
        int j = s.length() - 1;
 
        while (i < j) {
            if (s[i] != s[j]) return false;
            i++;
            j--;
        }
 
        return true;
    }
    
    void dfs(string& s, int i, string& s1, string& s2){
        
        if(i >= s.length()){
            if(isPalin(s1) && isPalin(s2))
                result = max(result, (int)s1.length()*(int)s2.length());
            return;
        }
        
        s1.push_back(s[i]);
        dfs(s, i+1, s1, s2);
        s1.pop_back();
        
        s2.push_back(s[i]);
        dfs(s, i+1, s1, s2);
        s2.pop_back();
        
        dfs(s, i+1, s1, s2);
    }
    
    int maxProduct(string s) {
        string s1 = "", s2 = "";
        dfs(s, 0, s1, s2);
        
        return result;
    }
};


324. Wiggle Sort II

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        int mid = n/2;
        nth_element(nums.begin(), nums.begin() + mid, nums.end());
        threeWayPartition(nums, nums[mid]);
        vector<int> res(n);
        int largeStart = n-1;
        int smallStart = (n%2) ? mid : (mid-1);
        for (int i = 0; i < n; i+=2)
            res[i] = nums[smallStart--];
        for (int i = 1; i < n; i+=2)
            res[i] = nums[largeStart--];
        nums = res;
    }
    
    void threeWayPartition(vector<int> &nums, int val) {
        int i = 0, j = 0;
        int n = nums.size()-1;
        while (j <= n){
            if (nums[j] < val)
                swap(nums[i++], nums[j++]);
            else if (nums[j] > val)
                swap(nums[j], nums[n--]);
            else
                j++;
        }
    }
};


638. Shopping Offers

class Solution {
public:
    int solve(vector<int>& price, vector<vector<int>>& special, vector<int>& needs, int idx, int n){
        if(idx == special.size()){
            int temp = 0;
            for(int i=0; i<n; i++){
                temp += (needs[i] * price[i]);
            }
            return temp;
        }

        int flag = 0;
        for(int i=0; i<n; i++){
            if(special[idx][i] > needs[i]) flag = 1;
        }


        if(flag == 0){
            for(int i=0; i<n; i++){
                needs[i] -= special[idx][i];
            }
            int consider = special[idx][n] + solve(price, special,needs,idx,n);
            for(int i=0; i<n; i++){
                needs[i] += special[idx][i];
            }
            return min(consider, solve(price, special,needs,idx+1,n));
        }

        return solve(price, special,needs,idx+1,n);;
    }

    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        int n = price.size();
        int ans = solve(price,special,needs,0,n);
        return ans;
    }
};

2976. Minimum Cost to Convert String I

class Solution {
private:
    static constexpr int CHAR_COUNT = 26;
    static constexpr int INF = 1e9;

    std::vector<std::vector<int>> buildConversionGraph(const std::vector<char>& original, const std::vector<char>& changed, const std::vector<int>& cost) {
        std::vector<std::vector<int>> graph(CHAR_COUNT, std::vector<int>(CHAR_COUNT, INF));
        for (int i = 0; i < CHAR_COUNT; i++) {
            graph[i][i] = 0;
        }
        for (size_t i = 0; i < cost.size(); i++) {
            int from = original[i] - 'a';
            int to = changed[i] - 'a';
            graph[from][to] = std::min(graph[from][to], cost[i]);
        }
        return graph;
    }

    void optimizeConversionPaths(std::vector<std::vector<int>>& graph) {
        for (int k = 0; k < CHAR_COUNT; k++) {
            for (int i = 0; i < CHAR_COUNT; i++) {
                if (graph[i][k] < INF) {
                    for (int j = 0; j < CHAR_COUNT; j++) {
                        if (graph[k][j] < INF) {
                            graph[i][j] = std::min(graph[i][j], graph[i][k] + graph[k][j]);
                        }
                    }
                }
            }
        }
    }

    long long computeTotalConversionCost(const std::string& source, const std::string& target, const std::vector<std::vector<int>>& graph) {
        long long totalCost = 0;
        for (size_t i = 0; i < source.length(); i++) {
            int sourceChar = source[i] - 'a';
            int targetChar = target[i] - 'a';
            if (sourceChar != targetChar) {
                if (graph[sourceChar][targetChar] == INF) {
                    return -1;
                }
                totalCost += graph[sourceChar][targetChar];
            }
        }
        return totalCost;
    }

public:
    long long minimumCost(std::string source, std::string target, std::vector<char>& original, std::vector<char>& changed, std::vector<int>& cost) {
        auto conversionGraph = buildConversionGraph(original, changed, cost);
        optimizeConversionPaths(conversionGraph);
        return computeTotalConversionCost(source, target, conversionGraph);
    }
};
