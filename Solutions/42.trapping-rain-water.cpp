/*
 * @lc app=leetcode id=42 lang=cpp
 *
 * [42] Trapping Rain Water
 */

// @lc code=start
class Solution {
public:
    int trap(vector<int>& height) {
        int result = 0;
        int left = 0, right = height.size() - 1;
        int left_max = 0, right_max = 0;
        
        while (left < right) {
            if (height[left] < height[right]) {
                if (height[left] <= left_max) {
                   result += left_max - height[left]; 
                } else {
                    left_max = height[left];
                }
                left++;
            } else {
                if (height[right] <= right_max) {
                   result += right_max - height[right]; 
                } else {
                   right_max = height[right];
                }
                right--;
            }
        }

        return result;
    }
};
// @lc code=end

