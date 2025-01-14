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
        while(r<n-1){
            if(arr[l]==maxElement)
                maxElement = findMax(arr,l+1,r);
            l++;
            r++;
            maxElement = max(maxElement,arr[r]);
            ans.push_back(maxElement);
        }
        return ans;
    }

    