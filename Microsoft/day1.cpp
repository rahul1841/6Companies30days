661. Image Smoother

class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int m = img.size(), n = img[0].size();
        vector<vector<int>> result(m, vector<int>(n));
        
        for (int r = 0; r < m; r++) 
        {
            for (int c = 0; c < n; c++) 
            {
                int sum = 0, count = 0;
                for (int dr = -1; dr <= 1; dr++) 
                {
                    for (int dc = -1; dc <= 1; dc++) 
                    {
                        int nr = r + dr;
                        int nc = c + dc;

                        if ((nr >= 0) && (nr < m) && (nc >= 0) && (nc < n)) 
                        {
                            sum += img[nr][nc];
                            count++;
                        }
                    }
                }
                result[r][c] = (sum / count);
            }
        }

        return result;
    }
};


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


299. Bulls and Cows

class Solution {
public:
    string getHint(string secret, string guess) {
        int count = 0;
        int mount = 0; 
        string ans = "";
        int hash[256] = {};
        for(int i = 0; i<secret.length();i++) {
            if(secret[i] == guess[i]) {
                count++;
            }
        }
        
        for(int i = 0; i < secret.length();i++) {
            hash[secret[i]]++;
        }
        for(int i = 0; i < guess.length();i++) {
            if(hash[guess[i]] > 0) { 
                mount++; 
                hash[guess[i]]--; 
            }
        }
        mount -= count;
        ans += to_string(count) + 'A' + to_string(mount) + 'B'; 
        return ans;
    }
};


2559. Count Vowel Strings in Ranges

class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        const unsigned isVowel=1+(1<<('e'-'a'))+(1<<('i'-'a'))+(1<<('o'-'a'))+(1<<('u'-'a'));
        const int n=words.size(), qz=queries.size();
        vector<int> cnt(n+1, 0);
        for(int i=0; i<n; i++){
            string& w=words[i];
            cnt[i+1]=cnt[i]+(((1<<(w[0]-'a'))& isVowel) && ((1<<(w.back()-'a'))& isVowel));
        }
        vector<int> ans(qz, 0);
        int i=0;
        for(auto& q: queries){
            ans[i++]=cnt[q[1]+1]-cnt[q[0]];
        }
        return ans;
    }
};