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