/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 */

// @lc code=start
#include <algorithm>
class Solution {
public:
  vector<vector<int>> threeSum(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> result;

    int i = 0;
    while (i < nums.size() - 1) {
      if (nums[i] > 0) {
        // considering our array is sorted, can't get a sum = 0 with numbers
        // larger than 0;
        break;
      }

      int l = i + 1, r = nums.size() - 1;

      while (l < r) {
        int target = 0 - nums[i] - nums[l];

        if (target > nums[r]) {
          l++;
        } else if (nums[r] != target) {
          r--;
        } else if (nums[r] == target) {
          result.push_back({nums[i], nums[l], nums[r]});
          r = nums.size() - 1;
          do {
            ++l;
          } while (nums[l] == nums[l - 1] && l < r);
        }
      }

      do {
        ++i;
      } while (nums[i] == nums[i - 1] && i < nums.size() - 1);
    }

    return result;
  }
};
// @lc code=end
