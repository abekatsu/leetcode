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
public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode *ret = new ListNode((l1->val + l2->val) % 10);
    int carry = (l1->val + l2->val) / 10;
    ListNode *p = l1->next; ListNode *q = l2->next;
    ListNode *cur = ret;

    while (p || q) {
      int x = (p != nullptr) ? p->val : 0;
      int y = (q != nullptr) ? q->val : 0;
      int sum = carry + x + y;
      cur->next = new ListNode(sum % 10);
      carry = sum / 10;
      // next loop
      if (p) {p = p->next;} if (q) {q = q->next;}
      cur = cur->next;
    }

    // 最後の繰り上がりがあるならば，新たなListNodeを作成する
    if (carry > 0) {
      cur->next = new ListNode(carry);
    }
    return ret;
  }
};


int main(int argc, char *argv[]) {
  ListNode l1(2, new ListNode(4, new ListNode(3)));
  ListNode l2(5, new ListNode(6, new ListNode(4, 0)));
  std::cout << l1.to_string() << std::endl ;
  std::cout << l2.to_string() << std::endl ;
  Solution *sol = new Solution();
  std::cout << sol->addTwoNumbers(&l1, &l2)->to_string() << std::endl ;

  ListNode *ex2_1 = new ListNode();
  ListNode *ex2_2 = new ListNode();
  std::cout << sol->addTwoNumbers(ex2_1, ex2_2)->to_string() << std::endl ;

  ListNode *ex3_1 = new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9)))))));
  ListNode *ex3_2 = new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9))));
  std::cout << ex3_1->to_string() << std::endl ;
  std::cout << ex3_2->to_string() << std::endl ;
  std::cout << sol->addTwoNumbers(ex3_1, ex3_2)->to_string() << std::endl ;
}
