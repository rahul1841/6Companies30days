2513. Minimize the Maximum of Two Arrays


class Solution {
    long gcd(long a, long b) {
        return b == 0 ? a : gcd(b, a % b);
    }
    long lcm(long a, long b) {
        return a / gcd(a, b) * b;
    }
    int solve(unsigned long d, unsigned long need) {
        return need * d / (d-1) - (need % (d-1) ? 0 : 1);
    }

public:
    int minimizeSet(int divisor1, int divisor2, int uniqueCnt1, int uniqueCnt2) {
        long l = lcm(divisor1, divisor2);
        int s = uniqueCnt1 + uniqueCnt2;
        return max({solve(l, s), solve(divisor1, uniqueCnt1), solve(divisor2, uniqueCnt2)});
    }
};


2933. High-Access Employees

class Solution {
public:
    vector<string> findHighAccessEmployees(vector<vector<string>>& access_times) {
        
        int n = access_times.size();
        sort(access_times.begin() , access_times.end());

        vector<string>ans;
        unordered_map<string , int>mp;
        for(int i = 0; i < n - 2; i++){
            if(mp.find(access_times[i][0]) == mp.end() &&
             access_times[i][0] == access_times[i + 2][0]){
                int t1 = stoi(access_times[i][1]);
                int t2 = stoi(access_times[i + 2][1]);

                if(t2 - t1 < 100){
                  i++;
                  ans.push_back(access_times[i][0]);
                  mp[access_times[i][0]]++;
                } 
            }
        }
       return ans;
    }
};



2343. Query Kth Smallest Trimmed Number

class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        vector<int>ans;
        for(int i=0;i<queries.size();i++){
            int k=queries[i][0];
            int trim=queries[i][1];
            priority_queue<pair<string,int>,vector<pair<string,int>>,greater<pair<string,int>>>pq;
            for(int j=0;j<nums.size();j++){
                string temp=nums[j];
                string res;
                for(int l=temp.size()-trim;l<temp.size();l++)
                    res+=temp[l];
                pq.push({res,j});
            }
            int top;
            while(!pq.empty() && k-- ){
                top=pq.top().second;
                pq.pop();
            }
            ans.push_back(top);  
        }
        return ans;
    }
};


216. Combination Sum III

class Solution {
public:
    vector<vector<int>> ans;
    void fun(vector<int>& v, int k, int sum, int i){
        if(sum==0 && k==0){
            ans.push_back(v);
            return;
        }
        if(i>9 || sum<0 || k<0){
            return ;
        }
        if(sum-i>=0){
            v.push_back(i);
            fun(v,k-1,sum-i,i+1);
            v.pop_back();
            fun(v,k,sum,i+1);
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        if(n>55)
            return ans;
        vector<int> v;
        fun(v,k,n,1);
        return ans;
    }
};