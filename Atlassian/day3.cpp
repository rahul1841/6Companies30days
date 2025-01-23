2135. Count Words Obtained After Adding a Letter

class Solution {
public:
    int wordCount(vector<string>& startWords, vector<string>& targetWords) {
        unordered_set<string>w;
        for(int i=0;i<startWords.size();i++)
        {
            sort(startWords[i].begin(),startWords[i].end());
            w.insert(startWords[i]);
        }
        int c=0;string tmp="",x="";
        for(int i=0;i<targetWords.size();i++)
        {
            tmp=targetWords[i];
            sort(tmp.begin(),tmp.end());           
            for(int j=0;j<tmp.length();j++)
            {
                x=tmp.substr(0,j)+tmp.substr(j+1);
                if(w.find(x)!=w.end())
                {
                    c++;
                    break;
                }
            }
        }
        return c;
    }
};


1969. Minimum Non-Zero Product of the Array Elements

class Solution {
private:
    const int MOD = 1000000007;

    long long power(long long x, long long y)
    {
        if (y == 0)
            return 1;
        long long ans = power(x, y / 2);
        if (y % 2 == 0)
            return (ans * ans) % MOD;
        else
            return (((ans * ans) % MOD) * (x % MOD)) % MOD;
    }

public:
    int minNonZeroProduct(int p) {
        long long max_i = pow(2, p);
        long long max = max_i - 1;
        long long result = power((max - 1), ((max - 1) / 2));
        return (result * (max % MOD)) % MOD;
    }
};


1994. The Number of Good Subsets

class Solution {
public:
    int mod=1e9+7;
    vector<int>prime;
    int mp[45];
    long long dp[31][1<<12];
    int find(int n)
    {
        for(int i=2;i<=sqrt(n);i++)
        {
            if(n%i==0)
            {
                return false;
            }
        }
        return true;
    }
    long long find(int value,int mask)
    {
        if(value>30)
        {
            return (mask>0);
        }
        if(dp[value][mask]!=-1)
        {
            return dp[value][mask]%mod;
        }
        int new_mask=0;
        long long product=1;
        for(int i=0;i<prime.size();i++)
        {
            if((value%prime[i])==0)
            {
                product*=prime[i];
                new_mask|=(1<<i);
            }
        }
        long long ans=find(value+1,mask);
        if(product==value&&mp[value]&&((mask&new_mask)==0))
        {
            ans+=(find(value+1,mask|new_mask)*mp[value]);
        }
        return dp[value][mask]=ans%mod;
    }
    int numberOfGoodSubsets(vector<int>& nums) 
    {
        memset(dp,-1,sizeof(dp));
        for(int i=2;i<=30;i++)
        {
            if(find(i))
            {
                prime.push_back(i);
            }
        }
        for(auto it:nums)
        {
            mp[it]++;
        }
        long long val=find(2,0)%mod;
        long one=1;
        for(int i=0;i<mp[1];i++)
        {
            one=(one*2)%mod;
        }
        val=(val*one)%mod;
        return val;
    }
};


2211. Count Collisions on a Road

class Solution {
public:
    int countCollisions(string D) {
        int n = D.size(), ans = 0;
		int i = 0 , j = n-1;
        while(i<=j and D[i] == 'L') i++;    
		while(i<=j and D[j] == 'R') j--;    
        for( ; i<=j ; i++) ans += (D[i] != 'S');  
        return ans;
        }
};