17. Letter Combinations of a Phone Number

class Solution {
    private:
    void solve(string digits,vector<string>& ans,string output,int index,string mapping[]){
        //base case
        if(index>=digits.length()){
            ans.push_back(output);
            return;
        }
        
        int number = digits[index]-'0';
        string value = mapping[number];
        
        for(int i=0;i<value.length();i++){
            output.push_back(value[i]);
            solve(digits,ans,output,index+1,mapping);
            output.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string>  ans;
        string output="";
        if(digits.length()==0){
            return ans;
        }
        int index = 0;
        string mapping[10] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        solve(digits,ans,output,index,mapping);
        return ans;
    }
};


Q: Missing And Repeating

vector<int> findTwoElement(vector<int>& arr) {
        vector<int> ans(2); // To store the repeated and missing numbers
        int n = arr.size();
        int i = 0;
    
        while (i < n) {
            if (arr[i] != arr[arr[i] - 1]) {
                swap(arr[i], arr[arr[i] - 1]);
            } else {
                i++;
            }
        }
    
        for (int i = 0; i < n; i++) {
            if (arr[i] != i + 1) {
                ans[0] = arr[i];    
                ans[1] = i + 1;    
            }
        }
        return ans;
    }


519. Random Flip Matrix

class Solution {
public:
    int totalRow,totalCol;
    int row,col;
    Solution(int m, int n) {
        totalRow=m;
        totalCol=n;
        row=0;
        col=0;
    }
    
    vector<int> flip() {
        col++;
        if (col==totalCol)
        {
            col=0;
            row++;
        }
        if (row==totalRow)
        {
            row=0;
            col=0;
        }
        return {row,col};
    }
    
    void reset() {
        
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(m, n);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
 */

