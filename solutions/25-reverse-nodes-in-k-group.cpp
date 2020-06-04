using namespace std;

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
  ListNode* reverseKGroup(ListNode* head, int k) {
    if (k < 2) {
      return head;
    }
    // 最终结果的虚拟头
    ListNode v_head(0);
    // 前一组翻转后的尾部
    ListNode* prev_group_tail = &v_head;

    ListNode* from;
    ListNode* p = head;
    ListNode* current;
    int counter = 0;
    while (p != nullptr) {
      current = p;
      p = p->next;
      counter++;
      if (counter == 1) {
        from = current;
      } else if (counter == k) {
        reverse(from, current, prev_group_tail);
        prev_group_tail = from;
        counter = 0;
      }
    }

    if (counter != 0) {
      prev_group_tail->next = from;
    }

    return v_head.next;
  }

  void reverse(ListNode* head, ListNode* tail, ListNode* prev_tail) {
    tail->next = nullptr;

    ListNode* prev = nullptr;
    ListNode* current = nullptr;
    ListNode* next = head;
    while (next) {
      prev = current;
      current = next;
      next = next->next;
      current->next = prev;
    }
    prev_tail->next = current;
  }
};

int main() {
  ListNode n1(1);

  ListNode n2(2);
  n1.next = &n2;

  ListNode n3(3);
  n2.next = &n3;

  ListNode n4(4);
  n3.next = &n4;

  Solution s;
  ListNode* head = s.reverseKGroup(&n1, 3);

  return 0;
}