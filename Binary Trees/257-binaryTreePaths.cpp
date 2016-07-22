/*  257. Binary Tree Paths 
    Given a binary tree, return all root-to-leaf paths.
    For example, given the following binary tree:
       1
     /   \
    2     3
     \
      5
    All root-to-leaf paths are:
    ["1->2->5", "1->3"]
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<int> path;
        vector<string> ans;
        
        if(!root)
            return ans;
            
        treepath(root, path, ans);
        
        return ans;
    }
    void treepath(TreeNode* root, vector<int> &path, vector<string> &ans){
        
        if(!root)
            return;
            
        path.push_back(root->val);
        
        if(!root->left && !root->right){
            
            string s="";
            
            for(int i=0; i < path.size(); i++){
                s += to_string(path[i]);
                if(i != path.size()-1)
                    s += "->";
            }
            
            ans.push_back(s);
        }
        
        treepath(root->left,path,ans);
        treepath(root->right,path,ans);
        
        path.pop_back();
    }
};