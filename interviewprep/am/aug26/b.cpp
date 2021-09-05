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
    void explore(TreeNode* root,int target){
        // left child , right child , parent
        // pre-order traversal
        if(root->left!=nullptr)
            explore(root->left,target);
        if(root->right!=nullptr)
            explore(root->right,target);
        
        if((root->left==nullptr||root->left->val==-1)&&(root->right==nullptr||root->right->val==-1)&&(root->val==target))
            root->val=-1;
        
        // original if statement would run into nullptr reference error
        // if((root->left==nullptr&&root->right==nullptr&&root->val==target)||(root->left->val==-1&&root->right->val==-1&&root->val==target)){
        //     root->val=-1;
        // }
    }
    
    void update(TreeNode* root,TreeNode* res){
        if(root->left!=nullptr&&root->left->val!=-1){
            res->left=new TreeNode(root->left->val);
            update(root->left,res->left);
        }
        if(root->right!=nullptr&&root->right->val!=-1){
            res->right=new TreeNode(root->right->val);
            update(root->right,res->right);
        }
    }
    
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        explore(root,target);
        
        if(root->val==-1)
            return nullptr;
        
        TreeNode* res=new TreeNode(root->val);
        
        update(root,res);
        
        return res;
    }
};