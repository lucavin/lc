/*
 * @lc app=leetcode id=110 lang=c
 *
 * [110] Balanced Binary Tree
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

int getHeight(struct TreeNode *node) {
  if (node == NULL) {
    return -1;
  } else {
    int leftHeight = getHeight(node->left);
    int rightHeight = getHeight(node->right);
    return leftHeight >= rightHeight ? leftHeight + 1 : rightHeight + 1;
  }
}

bool isBalanced(struct TreeNode *root) {
  if (root == NULL) {
    return true;
  }

  int balFac = abs(getHeight(root->left) - getHeight(root->right));
  if (balFac < 2 && isBalanced(root->left) && isBalanced(root->right)) {
    return true;
  } else {
    return false;
  }
}
// @lc code=end
