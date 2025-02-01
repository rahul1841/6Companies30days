2261. K Divisible Elements Subarrays

class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        set<vector<int>> s;
        for(int i=0;i<nums.size();i++)
        {
            int count=0;
            vector<int> temp;
            for(int j=i;j<nums.size();j++)
            {
                if(count<k)
                {
                    temp.push_back(nums[j]);
                    s.insert(temp);

                    if(nums[j]%p==0)
                    count++;
                }
                else if(count==k)
                {
                    if(nums[j]%p!=0)
                    {
                        temp.push_back(nums[j]);
                        s.insert(temp);
                    }
                    else
                    break;
                }
            }
            temp.clear();
        }
        return s.size();
    }
};


1765. Map of Highest Peak

class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int n = isWater.size(), m = isWater[0].size();
        vector<vector<int>>result(n, vector<int>(m, INT_MAX));
        vector<pair<int, int>>level_cells;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (isWater[i][j] == 1) {
                    result[i][j] = 0;
                    level_cells.push_back({i, j});
                }
            }
        }
        array<int, 4> di = {1, -1, 0, 0}, dj = {0, 0, -1, 1};
        int level = 0;
        while (!level_cells.empty()) {
            vector<pair<int, int>>next_level_cells;
            int nexti, nextj;
            for (auto [curr_i, curr_j] : level_cells) {                
                for (int i = 0; i < 4; i++) {
                    nexti = curr_i + di[i];
                    nextj = curr_j + dj[i];
                    if (!valid_position(nexti, nextj, n, m))
                        continue;
                    if (result[nexti][nextj] != INT_MAX) 
                        continue;
                    if (result[nexti][nextj] > level + 1) {
                        next_level_cells.push_back({nexti, nextj});
                        result[nexti][nextj] = level + 1;
                    }
                }
            }
            swap(level_cells, next_level_cells);
            level++;
        }
        return result;
    }
    bool valid_position(int i, int j, int n, int m) {
        return i >= 0 && j >= 0 && i < n && j < m;
    }
};

