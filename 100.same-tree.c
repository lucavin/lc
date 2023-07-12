/*
 * @lc app=leetcode id=100 lang=c
 *
 * [100] Same Tree
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
bool isSameTree(struct TreeNode *p, struct TreeNode *q) {
  if (!p && !q)
    return true;
  if (!p || !q)
    return false;
  bool sameNode = p->val == q->val ? true : false;

  return sameNode && isSameTree(p->left, q->left) &&
         isSameTree(p->right, q->right);
}
// @lc code=end
