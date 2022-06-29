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
    int maxLevelSum(TreeNode* root) {
        vector<pair<int,int> > nodes;

        TreeNode* cr=root;
        queue<pair<int, TreeNode*> > tovisit;
        
        int depth=1;
        tovisit.push(make_pair(1, root));
        nodes.push_back(make_pair(1,root->val));

        while(! tovisit.empty()){
            pair<int, TreeNode*> n=tovisit.front();
            tovisit.pop();

            if(n.second->left!=nullptr){
                depth=max(depth,n.first+1);
                nodes.push_back(make_pair(n.first+1,n.second->left->val));
                tovisit.push(make_pair(n.first+1,n.second->left));
            }
            if(n.second->right!=nullptr){
                depth=max(depth,n.first+1);
                nodes.push_back(make_pair(n.first+1,n.second->right->val));
                tovisit.push(make_pair(n.first+1,n.second->right));
            }
        }

        map<int,int> depval;

        for(int i=0;i<nodes.size();i++){
            if(depval.find(nodes[i].first)==depval.end()){
                depval[nodes[i].first]=nodes[i].second;
            }else{
                depval[nodes[i].first]+=nodes[i].second;
            }
        }

        int res=-1;
        int result=INT_MIN;
        for(int i=1;i<=depth;i++){
            if(result<depval[i]){
                res=i;
                result=depval[i];
            }
        }

        return res;
    }
};