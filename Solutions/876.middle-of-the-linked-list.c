/*
 * @lc app=leetcode id=876 lang=c
 *
 * [876] Middle of the Linked List
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *middleNode(struct ListNode *head) {
  int count = 0;

  struct ListNode *curr = head;

  while (curr != NULL) {
    count++;
    curr = curr->next;
  }

  curr = head;

  if (count % 2 == 1) {
    count = (count / 2);
  } else {
    count /= 2;
  }

  for (int i = 0; i < count; i++) {
    curr = curr->next;
  }

  return curr;
}
// @lc code=end
