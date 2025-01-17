2126. Destroying Asteroids

class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(), asteroids.end());
        int n = asteroids.size();
        long long weight = mass;
        for(int i=0; i<n; i++){
            if(weight >= asteroids[i]){
                weight += asteroids[i];
            }
            else{
                return false;
            }
        }

        return true;
    }
};


1334. Find the City With the Smallest Number of Neighbors at a Threshold Distance

class Solution {
public:
    int n, distanceThreshold;
    int dist[100][100];
    
    void FW(vector<vector<int>>& edges){
        fill(&dist[0][0], &dist[0][0]+100*100, 1e9);
        for (int i = 0; i < n; i++) 
            dist[i][i] = 0;
        for (auto& e : edges){
            int u=e[0], v = e[1], w = e[2];
            if (w <= distanceThreshold) 
                dist[u][v]=dist[v][u]=w;
        }

        for (int k = 0; k < n; k++)
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++) {
                    dist[i][j]=min(dist[i][j], dist[i][k]+dist[k][j]);
                }
    }

    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        this->n = n;
        this->distanceThreshold = distanceThreshold;
        FW(edges);
        
        int min_cnt = n, city = -1;
        for (int i = 0; i <n ; i++){
            int cnt = -1; 
            for (int j = 0; j < n; j++){
                if (dist[i][j] <= distanceThreshold) 
                    cnt++;
            }
            if (cnt <=min_cnt ){
                min_cnt=cnt;
                city=i;
            }
        }
        return city;
    }
};


273. Integer to English Words

#include <string>
using namespace std;

class Solution {
public:
    string ones[20] = {"", "One ", "Two ", "Three ", "Four ", "Five ", "Six ", "Seven ", "Eight ", "Nine ", "Ten ", "Eleven ", "Twelve ", "Thirteen ", "Fourteen ", "Fifteen ", "Sixteen ", "Seventeen ", "Eighteen ", "Nineteen "};
    string tens[10] = {"", "", "Twenty ", "Thirty ", "Forty ", "Fifty ", "Sixty ", "Seventy ", "Eighty ", "Ninety "};

    string numToWord(int n, string s) {
        string str = "";
        if (n > 19) {
            str += tens[n / 10] + ones[n % 10];
        } else {
            str += ones[n];
        }
        if (n) {
            str += s;
        }
        return str;
    }

    string numToWordTriple(int n, string s) {
        string str = "";
        if (n > 99) {
            str += ones[n / 100] + "Hundred ";
        }
        str += numToWord(n % 100, "");
        if (n) {
            str += s;
        }
        return str;
    }

    string numberToWords(int n) {
        if (n == 0) return "Zero";

        string ans = "";
        ans += numToWordTriple((n / 1000000000) % 1000, "Billion ");
        ans += numToWordTriple((n / 1000000) % 1000, "Million ");
        ans += numToWordTriple((n / 1000) % 1000, "Thousand ");
        ans += numToWordTriple((n / 100) % 10, "Hundred ");
        ans += numToWord(n % 100, "");

        // Trim any trailing spaces
        while (!ans.empty() && ans.back() == ' ') {
            ans.pop_back();
        }

        return ans;
    }
};


