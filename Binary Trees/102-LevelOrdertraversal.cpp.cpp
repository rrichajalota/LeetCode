/* Question 102- Level Order Traversal

Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:
[
  [3],
  [9,20],
  [15,7]
]

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
    struct qitem{			// a structure to store the current node and the depth of the node
        TreeNode *node;
        int depth;
    };
public:
    vector<vector<int>> levelOrder(TreeNode* root) {

        vector<vector<int>> result;

        if (!root){
            return result;
        }

        queue<qitem> q;
        qitem qi= {root, 1}; // initialized the current node as root and depth as 1 
        q.push(qi);

        vector<int> levelnodes;

        int checkdepth= 1;	// a counter that checks depth and adds value in the result vector.

        while(!q.empty()){

            qi= q.front();
            TreeNode *current= qi.node;
            int depth= qi.depth;

            if(current->left){
                qi.node= current->left;
                qi.depth= 1+depth;
                q.push(qi);
            }

            if(current->right){
                qi.node= current->right;
                qi.depth= 1+depth;
                q.push(qi);
            }

            if(checkdepth== depth){
                levelnodes.push_back(current->val);
            }

            else{
                result.push_back(levelnodes);
                checkdepth++;
                levelnodes.resize(0);
                levelnodes.push_back(current->val);
            }

            q.pop();
        }

        result.push_back(levelnodes);	// adds the nodes of the last level to the result vector

        return result;
    }
};
