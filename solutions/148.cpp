/**
 * Definition for singly-linked list.
 * struct ListNode {
 * int val;
 * ListNode *next;
 * ListNode() : val(0), next(nullptr) {}
 * ListNode(int x) : val(x), next(nullptr) {}
 * ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {

public:
  ListNode *sortList(ListNode *head) {

    if (head == nullptr || head->next == nullptr) {
      return head;
    }

    ListNode *slow = head;
    ListNode *fast = head;
    ListNode *prev = nullptr;

    // find midpoint of linked list
    while (fast != nullptr && fast->next != nullptr) {
      prev = slow;
      slow = slow->next;
      fast = fast->next->next;
    }

    // divides the list in two
    prev->next = nullptr;

    ListNode *l1 = sortList(head);
    ListNode *l2 = sortList(slow);

    head = merge(l1, l2);
    return head;
  }

  ListNode *merge(ListNode *l1, ListNode *l2) {
    if (l1 == nullptr) {
      return l2;
    }
    if (l2 == nullptr) {
      return l1;
    }

    ListNode *sentinel = new ListNode();
    ListNode *tail = sentinel;
    while (l1 != nullptr && l2 != nullptr) {
      if (l1->val < l2->val) {
        tail->next = l1;
        l1 = l1->next;
      } else {
        tail->next = l2;
        l2 = l2->next;
      }
      tail = tail->next;
    }

    while (l1 != nullptr) {
      tail->next = l1;
      l1 = l1->next;
      tail = tail->next;
    }

    while (l2 != nullptr) {
      tail->next = l2;
      l2 = l2->next;
      tail = tail->next;
    }

    ListNode *merged_head = sentinel->next;
    delete sentinel;
    return merged_head;
  }
};
