/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 */

// @lc code=start
class Solution {
public:
    bool is_opening(char c) {
        if 
        (
            c == '(' ||
            c == '{' ||
            c == '[' 
        ) {
            return true;
        }
        return false;
    }

    bool is_closing(char c) {
        if 
        (
            c == ')' ||
            c == '}' ||
            c == ']' 
        ) {
            return true;
        }
        return false;
    }

    char get_matching(char c) {
        if (c == ')') {
            return '(';
        } else if (c == '}') {
            return '{';
        } else {
            return '[';
        }
    }

    bool isValid(string s) {
        vector<char> stack;

        for (auto c : s) {
            if (is_opening(c)) {
                stack.push_back(c);
            } else if (is_closing(c)) {
                if (stack.empty()) {
                    return false;
                } else if (stack[stack.size() - 1] != get_matching(c)) {
                    return false;
                } else {
                    stack.pop_back();
                }
            }
        }
        
        return stack.empty() ? true : false;
    }
};
// @lc code=end

