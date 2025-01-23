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


