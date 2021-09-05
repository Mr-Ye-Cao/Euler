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
    vector<long long> store;
    
    long long calculate_subsum(TreeNode* root){
        if(root->left==nullptr&&root->right==nullptr){
            store.push_back(root->val);
            return root->val;
        }
        
        long long vl=0,vr=0;
        
        if(root->left!=nullptr)
            vl=calculate_subsum(root->left);
        
        if(root->right!=nullptr)
            vr=calculate_subsum(root->right);
        
        store.push_back(vl+vr+root->val);
        return vl+vr+root->val;
    }
    
    int maxProduct(TreeNode* root) {
        // (R-U)U
        // -U^2+UR (R/2)
        // O(N)
        
        TreeNode* cr=root;
        long long R=calculate_subsum(cr);
        
        long long res=-1;
        for(int i=0;i<store.size();i++){
            long long prd=(R-store[i])*store[i];
            res=max(res,prd);
        }
        
        return res%(1000000000ll+7ll);
    }
};