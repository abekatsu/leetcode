#include <iostream>
#include <string>
#include <sstream>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}

  std::string to_string() {
    std::stringstream ss;
    ListNode *node = this;
    while (node) {
      ss << node->val;
      node = node->next;
    }
    return ss.str();
  }

};

class Solution {
private:
  ListNode* swap(ListNode *head) {
    if (head == nullptr || head->next == nullptr) {
      // nothing to do
      return head;
    }

    ListNode *first = head;
    ListNode *second = head->next;
    ListNode *new_head = second;

    new_head->next = first;
    new_head->next->next = swap(second->next);

    return new_head;
  }

public:
  ListNode* swapPairs(ListNode* head) {
    ListNode *first, *second, *third;

    if (head == nullptr || head->next == nullptr) {
      // nothing to do
      return head;
    }

    first = head;
    second = head->next;
    third = second->next;

    head = second;
    head->next = first;
    head->next->next = swapPairs(third);

    return head;
  }

  ListNode* swapPairs04(ListNode* head) {
    ListNode *next;

    if (head == nullptr || head->next == nullptr) {
      // nothing to do
      return head;
    }

    next = head->next;
    head->next = swapPairs04(next->next);
    next->next = head;

    return next;
  }

};

int main(int argc, char *argv[]) {
  ListNode node(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));

  Solution sol;
  std::cout << node.to_string() << std::endl;
  ListNode *swappedNode = sol.swapPairs04(&node);
  std::cout << swappedNode->to_string() << std::endl;

}
