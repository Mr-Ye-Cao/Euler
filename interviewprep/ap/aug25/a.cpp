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
    void sum(TreeNode* r, TreeNode* r1){
        if(r1==nullptr)
            return;
        
        if(r!=nullptr){
            r->val+=r1->val;
        }else{
            r=new TreeNode(r1->val);
        }
        
        if(r1->left!=nullptr){
            if(r->left==nullptr){
                r->left=new TreeNode();
            }
            sum(r->left ,r1->left);            
        }
        
        if(r1->right!=nullptr){
            if(r->right==nullptr){
                r->right=new TreeNode();
            }
            sum(r->right,r1->right);
        }
    }
    
    
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(root1==nullptr && root2==nullptr)
            return nullptr;
            
        TreeNode* root = new TreeNode();
        TreeNode* cr1 = root;
        TreeNode* cr2 = root;
        
        sum(cr1,root1);
        sum(cr2,root2);
        
        return root;
    }
};