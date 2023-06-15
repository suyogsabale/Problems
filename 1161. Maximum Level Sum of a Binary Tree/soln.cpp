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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        TreeNode* node;
        int levelSize;
        int curLevel = 1;
        int maxSum = INT_MIN, maxLevel = -1;
        int levelSum = 0;
        
        q.push(root);
        
        while(!q.empty()){
            levelSize = q.size();
            for(int i = 0; i < levelSize; i++){
                node = q.front();
                q.pop();
                
                if(node->left){
                    q.push(node->left);
                }
                
                if(node->right){
                    q.push(node->right);
                }
                
                levelSum += node->val;
            }
            
            //clean up before going to next level
            if(levelSum > maxSum){
                maxSum = levelSum;
                maxLevel = curLevel;
            }
            levelSum = 0;  
            curLevel++;
        }
        
        return maxLevel;
    }
};