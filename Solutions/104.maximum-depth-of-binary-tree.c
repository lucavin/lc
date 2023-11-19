/*
 * @lc app=leetcode id=104 lang=c
 *
 * [104] Maximum Depth of Binary Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int maxDepth(struct TreeNode *root) {
  if (root == NULL)
    return 0;

  int leftDepth = maxDepth(root->left);
  int rightDepth = maxDepth(root->right);
  return 1 + (leftDepth >= rightDepth ? leftDepth : rightDepth);
}
// @lc code=end
