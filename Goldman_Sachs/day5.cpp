1373. Maximum Sum BST in Binary Tree


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */


class info{
    public:
    int maxi;
    int mini;
    bool isBST;
    int sum;
};

class Solution {
public:
    info solve(TreeNode *root,int &ans){

    //base case
    if(root == NULL){
        return {INT_MIN,INT_MAX,true,0};
    }

    info left = solve(root->left,ans);
    info right = solve(root->right,ans);

    info currNode;

    currNode.sum = left.sum + right.sum + root->val;
    currNode.maxi = max(root->val,right.maxi);
    currNode.mini = min(root->val,left.mini);

    if(left.isBST && right.isBST && (root->val>left.maxi && root->val<right.mini) ){
        currNode.isBST = true;
    }
    else{
        currNode.isBST = false;
    }

    //answer update
    if(currNode.isBST){
        ans = max(ans,currNode.sum);
    }

    return currNode;


}

    int maxSumBST(TreeNode* root) {
    int maxsum = 0;
    info temp = solve(root,maxsum);
    return maxsum;
    }
};


2327. Number of People Aware of a Secret

class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        const int m = 1e9+7;
        int curr =0;
        int ans =1;
        queue<pair<int,int>>delayq, forgetq;
        delayq.push({1,1});
        forgetq.push({1,1});
        for(int i=1;i<=n;i++){
            // number of people forgets the secret on ith day
            if(!forgetq.empty()&&forgetq.front().first+forget<=i){
                auto element = forgetq.front().second;
                forgetq.pop();
                ans = (ans- element +m)%m;
                curr = (curr - element+m)%m;
                
            }
            //  number of active spreader
            if(!delayq.empty()&&delayq.front().first+ delay<=i){
                auto element = delayq.front().second;
                delayq.pop();
                curr = (curr + element)%m;
            }
            // persons who knows the secret
            if(curr>0){
                ans  = (ans+curr)%m;
                delayq.push({i,curr});
                forgetq.push({i,curr});
            }
        }
        return ans;
        
    }
};