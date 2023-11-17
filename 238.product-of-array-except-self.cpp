/*
 * @lc app=leetcode id=238 lang=cpp
 *
 * [238] Product of Array Except Self
 */

// @lc code=start
class Solution {
public:
  vector<int> productExceptSelf(vector<int> &nums) {
    vector<int> result(nums.size());
    vector<int> prefix(nums.size());
    vector<int> postfix(nums.size());

    for (int i = 0; i < nums.size(); i++) {
      int postfix_index = nums.size() - 1 - i;
      if (i == 0) {
        prefix[0] = nums[0];
        postfix[postfix_index] = nums[postfix_index];
      } else {
        prefix[i] = prefix[i - 1] * nums[i];
        postfix[postfix_index] =
            postfix[postfix_index + 1] * nums[postfix_index];
      }
    }

    for (int i = 0; i < nums.size(); i++) {
      if (i == 0 && nums.size()) {
        result[i] = postfix[i + 1];
      } else if (i == nums.size() - 1) {
        result[i] = prefix[i - 1];
      } else {
        result[i] = prefix[i - 1] * postfix[i + 1];
      }
    }

    return result;
  }
};
// @lc code=end
