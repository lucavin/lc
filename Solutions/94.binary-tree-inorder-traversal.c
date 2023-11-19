/*
 * @lc app=leetcode id=94 lang=c
 *
 * [94] Binary Tree Inorder Traversal
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
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void traverse(struct TreeNode *root, int *arr, int *index) {
  if (!root)
    return;

  traverse(root->left, arr, index);
  arr[*index] = root->val;
  *index += 1;
  traverse(root->right, arr, index);
}

int *inorderTraversal(struct TreeNode *root, int *returnSize) {
  *returnSize = 0;
  int *resultArr = malloc(100 * sizeof(int));
  traverse(root, resultArr, returnSize);
  return realloc(resultArr, *returnSize * sizeof(int));
}
// @lc code=end
