#include <iostream>



  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

class Solution {
public:
    void deleteNode(ListNode* node) {

        ListNode*p=node;
        node=node->next;
        delete p;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
