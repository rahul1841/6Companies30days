455. Assign Cookies

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int i=0, j=0;

        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        while(i<g.size() && j<s.size())
        {
            if(g[i] <= s[j])
            {
                i++; 
            }
            
            j++;
        }

        return i;
    }
};


703. Kth Largest Element in a Stream

class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) {
        this->k=k;
        for(int num : nums){
            add(num);
        }
    }
    int add(int val) {
        minHeap.push(val);
        if(minHeap.size()>k){
            minHeap.pop();
        }
        return minHeap.top();
    }
private:
    int k;
    priority_queue<int,vector<int>,greater<int>> minHeap;
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
