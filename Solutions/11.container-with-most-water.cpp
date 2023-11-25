/*
 * @lc app=leetcode id=11 lang=cpp
 *
 * [11] Container With Most Water
 */

// @lc code=start
class Solution {
public:
    int maxArea(vector<int>& height) {
        int result = 0;
        int i = 0, j = height.size() - 1;

        while (j >= i + 1) {
            int min_height = min(height[i], height[j]);

            int curr_vol = min_height * (j - i);

            result = curr_vol > result ? curr_vol : result;

            if (height[i] > height[j]) {
                j--;
            } else {
                i++;
            }
        }

        return result;
    }
};
// @lc code=end

