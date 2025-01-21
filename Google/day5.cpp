2223. Sum of Scores of Built Strings

class Solution {
public:
    template<typename T> 
    vector<int> suffix_array(const T &S) {
        int n = S.size();
        vector<int> sa;
        for (int i = n - 1; i >= 0; --i) {
            sa.push_back(i);
        }
        stable_sort(sa.begin(), sa.end(), [&](int a, int b) { return S[a] < S[b]; });
    
        vector<int> classes(n);
        for (int i = 0; i < n; ++i) {
            classes[i] = S[i];
        }
        for (int len = 1; len < n; len *= 2) {
            vector<int> c = classes;
            for (int i = 0; i < n; i++) {
                classes[sa[i]] =
                    i > 0 && c[sa[i - 1]] == c[sa[i]] && sa[i - 1] + len < n && c[sa[i - 1] + len / 2] == c[sa[i] + len / 2]
                        ? classes[sa[i - 1]]
                        : i;
            }
            vector<int> cnt(n);
            iota(cnt.begin(), cnt.end(), 0);
            vector<int> s = sa;
            for (int i = 0; i < n; i++) {
                int s1 = s[i] - len;
                if (s1 >= 0)
                    sa[cnt[classes[s1]]++] = s1;
            }
        }
        return sa;
    }
    template<typename T>
    vector<int> lcp_array(const T &s, vector<int> &rank)
{
    int n=s.size(),k=0;
    vector<int> sa = suffix_array(s);
    vector<int> lcp(n,0);

    for(int i=0; i<n; i++) rank[sa[i]]=i;

    for(int i=0; i<n; i++, k?k--:0)
    {
        if(rank[i]==n-1) {k=0; continue;}
        int j=sa[rank[i]+1];
        while(i+k<n && j+k<n && s[i+k]==s[j+k]) k++;
        lcp[rank[i]]=k;
    }
    return lcp;
}
    long long sumScores(string s) 
    {
        int n = s.size();
        long long res = n;
        vector<int> rank(n);
        vector<int> lcp = lcp_array(s, rank), sfx = suffix_array(s);
        int first = rank[0];
        int tmp = first;
        int bound = INT_MAX;
        while (tmp)
        {
            tmp -= 1;
            if ( lcp[tmp] == 0 ) break;
            if ( lcp[tmp] < bound ) bound = lcp[tmp];
            res += bound;
        }
        tmp = first;
        bound = INT_MAX;
        while (tmp<n-1)
        {
            if ( lcp[tmp] == 0 ) break;
            if ( lcp[tmp] < bound ) bound = lcp[tmp];
            res += bound;
            tmp ++;
        }
        return res;
    }
};