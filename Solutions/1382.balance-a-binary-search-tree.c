/*
 * @lc app=leetcode id=1382 lang=c
 *
 * [1382] Balance a Binary Search Tree
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
int height(struct TreeNode *root) {
  if (root == NULL)
    return -1;

  int left = height(root->left);
  int right = height(root->right);

  return 1 + (left >= right ? left : right);
}

int check_balance_factor(struct TreeNode *root) {
  return height(root->left) - height(root->right);
}

struct TreeNode *balance(struct TreeNode *root, bool *bal) {
  if (root == NULL)
    return NULL;

  root->left = balance(root->left, bal);
  root->right = balance(root->right, bal);

  // Check the balance factor
  int bal_factor = check_balance_factor(root);
  // printf("node : %d, bf : %d\r\n", root->val, bal_factor);
  if (bal_factor >= 2 || bal_factor <= -2) {
    *bal = false;
    // LL Rotation
    if (bal_factor >= 2 && check_balance_factor(root->left) >= 0) {
      struct TreeNode *tmp_node = root;
      struct TreeNode *left_node = root->left;

      tmp_node->left = left_node->right;
      left_node->right = tmp_node;
      return left_node;
    }

    // RR Rotation
    else if (bal_factor <= -2 && check_balance_factor(root->right) <= 0) {
      struct TreeNode *tmp_node = root;
      struct TreeNode *right_node = root->right;

      tmp_node->right = right_node->left;
      right_node->left = tmp_node;
      return right_node;
    }

    // LR Rotation
    else if (bal_factor >= 2 && check_balance_factor(root->left) <= 0) {
      struct TreeNode *tmp_node = root;
      struct TreeNode *left_node = root->left;
      struct TreeNode *new_node = left_node->right;

      tmp_node->left = new_node->right;
      left_node->right = new_node->left;
      new_node->left = left_node;
      new_node->right = tmp_node;
      return new_node;
    }

    // RL Rotation
    else if (bal_factor <= -2 && check_balance_factor(root->right) >= 0) {
      struct TreeNode *tmp_node = root;
      struct TreeNode *right_node = root->right;
      struct TreeNode *new_node = right_node->left;

      tmp_node->right = new_node->left;
      right_node->left = new_node->right;
      new_node->right = right_node;
      new_node->left = tmp_node;
      return new_node;
    }
  }
  return root;
}

struct TreeNode *balanceBST(struct TreeNode *root) {
  bool bal = false;

  while (bal == false) {
    bal = true;
    root = balance(root, &bal);
  }
  return root;
}
// @lc code=end
