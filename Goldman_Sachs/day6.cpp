GFG - Run Length Encoding

class Solution {
  public:
    string encode(string s) {
        // code here
        int n = s.size();
        string encoded = "";
        
        for(int i=0;i<n;i++){
            int cnt = 1;
            while(i < n - 1 && s[i] == s[i+1]){
                cnt++;
                i++;
            }
            encoded += s[i];
            encoded += to_string(cnt);
        }
        return encoded;
    }
};



2400. Number of Ways to Reach a Position After Exactly k Steps

class Solution {
public:
    int dp[5001][1001];
    const int mod=1e9+7;
    int f(int i,int e,int k){
        if(k==0){
            return i==e?1:0;
        }
        if(dp[i+1000][k]!=-1){
            return dp[i+1000][k];
        }
        int ans=f(i+1,e,k-1);
        int ans2=f(i-1,e,k-1);
        return dp[i+1000][k]=(ans+ans2)%mod;
    }
    int numberOfWays(int startPos, int endPos, int k) {
        memset(dp,-1,sizeof(dp));
      return f(startPos,endPos,k);  
    }
};

