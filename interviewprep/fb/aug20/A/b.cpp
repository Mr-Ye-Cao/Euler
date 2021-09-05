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
    vector<pair<int,TreeNode*> > dt;
    map<TreeNode*,TreeNode*> parent;
    
    void dfs(TreeNode* root, int depth){
        dt.push_back(make_pair(depth,root));
        if(root->left!=nullptr){
            parent[root->left]=root;
            dfs(root->left,depth+1);
        }
        if(root->right!=nullptr){
            parent[root->right]=root;
            dfs(root->right,depth+1);
        }
    }
    
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        dfs(root,0);
        std::sort(dt.begin(),dt.end());
        set<TreeNode*> res;
        
        for(int i=dt.size()-1;i>=0;i--)
            if(dt[i].first==dt[dt.size()-1].first)
                res.insert(dt[i].second);
                
        while(res.size()!=1){
            set<TreeNode*> cres;
            for(auto it=res.begin();it!=res.end();it++){
                cres.insert(parent[(*it)]);
            }
            res=cres;
        }
        
        return *res.begin();
    }
};