Q1:
825. Friends Of Appropriate Ages

class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        int n = ages.size();
        vector<int> v(121,0);
        for(int i=0;i<n;i++){
            v[ages[i]]++;
        }
        int ans = 0;
        for(int x = 1; x <= 120; x++){
            int n1 = v[x];
            for(int y = 1; y <= 120; y++){
                int n2 = v[y];
                if(!(y <= (0.5 * x + 7) || y > x || ( y > 100 && x < 100))){
                    ans += n1*n2;
                    if(x==y){
                        ans -= n1;
                    }
                }
            }
        }
        return ans; 
    }
};



718. Maximum Length of Repeated Subarray

class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (nums1[i] == nums2[j]) {
                    if (i == 0 || j == 0) dp[i][j] = 1;
                    else dp[i][j] = dp[i-1][j-1] + 1;
                    ans = max(ans, dp[i][j]);
                }
            }
        }
        return ans;
    }
};


396. Rotate Function
class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        vector<int> rev=nums;
        reverse(rev.begin(),rev.end());
        int res=0, pre=0, sum=0;
        for(int i=0; i<n; i++){
            res+= (i*nums[i]);
            sum+= nums[i];
        }
        pre=res;
        int rotate=1,j=0;
        while(rotate<n){
            int temp=pre;
            temp = pre+sum-(n*rev[j]);
            j++;
            res=max(res,temp);
            pre=temp;
            rotate++;
        }
        return res;
    }
};
