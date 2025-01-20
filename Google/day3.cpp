23. Merge k Sorted Lists

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<tuple<int, int, ListNode*>, vector<tuple<int, int, ListNode*>>, greater<tuple<int, int, ListNode*>>> minheap;

        for (int i = 0; i < lists.size(); i++) {
            if (lists[i] != nullptr) {
                minheap.push(make_tuple(lists[i]->val, i, lists[i]));
            }
        }

        ListNode* result = nullptr;
        ListNode* resultTail = nullptr; 
        while (!minheap.empty()) {
            auto [value, listIndex, node] = minheap.top();
            minheap.pop();
            if (result == nullptr) {
                result = new ListNode(value);
                resultTail = result;
            } else {
                resultTail->next = new ListNode(value);
                resultTail = resultTail->next;
            }
            if (node->next != nullptr) {
                minheap.push(make_tuple(node->next->val, listIndex, node->next));
            }
        }
        return result;
    }
};


2233. Maximum Product After K Increments

class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) 
    {
        priority_queue<int,vector<int>,greater<int>>pq;
        for(auto val:nums) pq.push(val);

        long long mod = 1e9+7, ans = 1, val;
        while(k--)
        {
            val = pq.top(); pq.pop();
            pq.push(val+1);
        }

        while(!pq.empty())
        {
            ans = (ans * pq.top()) % mod;
            pq.pop();
        }
        return ans;
    }
};


2343. Query Kth Smallest Trimmed Number

class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        vector<int>ans;
        for(int i=0;i<queries.size();i++){
            int k=queries[i][0];
            int trim=queries[i][1];
            priority_queue<pair<string,int>,vector<pair<string,int>>,greater<pair<string,int>>>pq;
            for(int j=0;j<nums.size();j++){
                string temp=nums[j];
                string res;
                for(int l=temp.size()-trim;l<temp.size();l++)
                    res+=temp[l];
                pq.push({res,j});
            }
            int top;
            while(!pq.empty() && k-- ){
                top=pq.top().second;
                pq.pop();
            }
            ans.push_back(top);  
        }
        return ans;
    }
};


