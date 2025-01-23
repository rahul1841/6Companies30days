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


