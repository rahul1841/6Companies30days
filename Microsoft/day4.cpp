168. Excel Sheet Column Title

class Solution {
public:
    string convertToTitle(int columnNumber) {


        string s = "";
        while(columnNumber > 0){
            columnNumber--;

            int rem = columnNumber % 26;
            s += char('A' + rem);
            columnNumber /= 26;
        }

        reverse(s.begin(), s.end());
        return s;
    }
};


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