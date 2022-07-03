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
    TreeNode* getR1(TreeNode* cr,int x){
        if(cr->val==x){
            return cr;
        }

        TreeNode* r1;
        if(cr->left!=nullptr){
            r1=getR1(cr->left,x);
            if(r1!=nullptr)
                return r1;
        }
        if(cr->right!=nullptr){
            r1=getR1(cr->right,x);
            if(r1!=nullptr)
                return r1;
        }

        return nullptr;
    }

    int countRC(TreeNode* r1){
        if(r1==nullptr){
            return 0;
        }
        int res=1;
        
        if(r1->left!=nullptr){
            res+=countRC(r1->left);
        }
        if(r1->right!=nullptr){
            res+=countRC(r1->right);
        }

        return res;
    }

    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
         TreeNode* cr=root;
         TreeNode* r1=getR1(cr,x);

         int cr1c=countRC(r1),cr2c=0;
         
         if(r1==root){
            // have to take one of two children
            cr2c=max(cr2c,countRC(r1->left));
            cr2c=max(cr2c,countRC(r1->right));
            if(n-cr2c<cr2c){
                return true;
            }
         }else{
            // take one of two children or parent
            // take parent
            if(n-cr1c>cr1c){
                return true;
            }

            // take one of two children
            cr2c=max(cr2c,countRC(r1->left));
            cr2c=max(cr2c,countRC(r1->right));
            if(n-cr2c<cr2c){
                return true;
            }
         }
        
        return false;
    }
};