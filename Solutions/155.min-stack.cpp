/*
 * @lc app=leetcode id=155 lang=cpp
 *
 * [155] Min Stack
 */

// @lc code=start
#include <climits>

struct StackNode {
    int val;
    int min;
};

class MinStack {
public:
    vector<StackNode> stack;

    MinStack() {
        stack = {};
    };
    
    void push(int val) {
        StackNode new_node;
        if (stack.size()) {
            StackNode top = stack.back();
            new_node.min = val < top.min ? val : top.min;
        } else {
            new_node.min = val;
        }
        new_node.val = val;
        stack.push_back(new_node);
    }
    
    void pop() {
        stack.pop_back();
    }
    
    int top() {
        return stack.back().val;
    }
    
    int getMin() {
        return stack.back().min;
    }
};

/**
 * your minstack object will be instantiated and called as such:
 * minstack* obj = new minstack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getmin();
 */
// @lc code=end

