#include <cstdio>

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if (head == nullptr) {
            return head;
        }

        ListNode *ptr_base = head;
        ListNode *ptr = head;

        while (ptr != nullptr) {
            if (ptr_base->val == ptr->val) {
                ptr = ptr->next;
            } else {
                ptr_base->next = ptr;
                ptr_base = ptr;
            }
        }

        ptr_base->next = nullptr;

        return head;
    }
};

int main() {
    printf("Hello!\n");
    return 0;
}
