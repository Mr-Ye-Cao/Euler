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
class Solution {
public:
    vector<pair<int,int> > leaves;
    
    void update(TreeNode* root,int depth){
        if(root->left==nullptr&&root->right==nullptr){
            leaves.push_back(make_pair(depth,root->val));
            return;
        }
        
        if(root->left!=nullptr)
            update(root->left,depth+1);
        
        if(root->right!=nullptr)
            update(root->right,depth+1);
    }
    
    int deepestLeavesSum(TreeNode* root) {
        update(root,0);
        
        std::sort(leaves.begin(),leaves.end());
        
        int res=leaves[leaves.size()-1].second;
        int dp=leaves[leaves.size()-1].first;
        
        for(int i=leaves.size()-2;i>=0;i--){
            if(leaves[i].first==dp)
                res+=leaves[i].second;
        }
        
        return res;
    }
};