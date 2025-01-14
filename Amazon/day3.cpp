GFG Phone directory

class Solution{
public:
    vector<vector<string>> displayContacts(int n, string contact[], string s) {
        const int m = s.size();
        vector<vector<string>> ans(m, vector<string>());
        sort(contact, contact + n);
        
        for(int i=0; i<n; ++i) {
            string word = contact[i];
            if(i > 0 and word == contact[i-1])
                continue;
            int j=0;
            while(j < m and j < word.size() and s[j] == word[j]) 
                ans[j++].push_back(word);
        }
        for(int j=0; j<m; ++j) {
            if(ans[j].empty())
                ans[j].push_back("0");
        }
        return ans; 
    }
};

GFG K Sized Subarray Maximum

int findMax(vector<int> arr,int l,int r){
    int ans = INT_MIN;
    for(int i{l};i<=r;i++){
        ans = max(ans,arr[i]);
    }
    return ans;
}
class Solution {
  public:
    // Function to find maximum of each subarray of size k.
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        vector<int> ans;
        int l =0;
        int r = k-1;
        int maxElement =INT_MIN;
        for(int i{0};i<k;i++){
            maxElement = max(maxElement,arr[i]);
        }
        ans.push_back(maxElement);
        while(r<n-1){}
            if(arr[l]==maxElement)
                maxElement = findMax(arr,l+1,r);
            l++;
            r++;
            maxElement = max(maxElement,arr[r]);
            ans.push_back(maxElement);
        }
        return ans;
    }


387. First Unique Character in a String

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> mp;

        for(char ch : s){
            mp[ch]++;
        }

        for(int i = 0; i<s.size(); i++){
            if(mp[s[i]] == 1){
                return i;
            }
        }
        return -1;
    }
};


3154. Find Number of Ways to Reach the K-th Stair

class Solution {
public:
    unsigned long long C(int n, int k) {
        if (k > n) return 0;
        if (k == 0 || k == n) return 1;
        if (k > n - k) k = n - k;

        unsigned long long result = 1;
        for (int i = 0; i < k; ++i) {
            result *= (n - i);
            result /= (i + 1);
        }
        return result;
    }
    int waysToReachStair(int k) {
        if(k == 0 || k == 4) return 2;
        if(k == 1 || k == 2) return 4;
        int i = 0;
        while((1<<i) < k) ++i;
        k = (1<<i)-k;
        return C(i+1, k);
    }
};


36. Valid Sudoku

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<char,int> eachBox;
        unordered_map<char,int> row;
        unordered_map<char,int> column ;
        int j= 0 ;
        int i=0 ;
        for( i =0 ; i < 9 ;i++){
            for( j=0 ; j< 9 ;j++){
                if(board[i][j] != '.'){
                    row[board[i][j]]++;
                }
                if(board[j][i]!='.'){
                    column[board[j][i]]++;
                }
                if(row[board[i][j]]>1) return false;
                if(column[board[j][i]]>1) return false ;
            }
            row.clear();
            column.clear();
        }
        for(i=0 ; i < 9 ;i+=3){
            for(j=0 ; j <9 ;j+=3){
                eachBox.clear();
                for(int x = i ; x < i+3 ; x++){
                    for(int y = j ; y < j+3; y++){
                        if(board[x][y]!='.'){
                            eachBox[board[x][y]]++;
                        }
                        if(eachBox[board[x][y]]>1) return false ;
                    }
                }
            }
        }
        return true;
    }
};


GFG Nuts and Bolts Problem

   void matchPairs(int n, char nuts[], char bolts[]) {
        if(n == 1) return;
        map<char, int> mpp;
        for(int i = 0; i < n; i++){
            mpp[nuts[i]]++;
        }
        int i = 0;
        for(auto it = mpp.begin(); it != mpp.end(); it++){
            nuts[i] = it->first;
            bolts[i] = it->first;
            i++;
        }
    }
