/**
 * Definition for singly-linked list.
 */
struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
 public:
  ListNode* reverseList(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* curr = nullptr;
    ListNode* next = head;
    while (next) {
      prev = curr;
      curr = next;
      next = next->next;
      curr->next = prev;
    }
    return curr;
  }
};