/*
 * @lc app=leetcode id=543 lang=c
 *
 * [543] Diameter of Binary Tree
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
int diameterHelper(struct TreeNode *root, int *max) {
  if (root == NULL)
    return -1;

  int lh = diameterHelper(root->left, max);
  int rh = diameterHelper(root->right, max);
  int diam = 2 + lh + rh;
  if (diam > *max) {
    *max = diam;
  }
  return 1 + (lh >= rh ? lh : rh);
}

int diameterOfBinaryTree(struct TreeNode *root) {
  int max = 0;
  diameterHelper(root, &max);
  return max;
}
// @lc code=end
