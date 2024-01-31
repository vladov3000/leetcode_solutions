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
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int length = 0;
        for (ListNode* i = head; i != nullptr; i = i->next) {
            length++;
        }

        if (length == 1) {
            return nullptr;
        }

        ListNode* before = head;
        int       index  = length - n;
        if (index == 0) {
            return head->next;
        }

        while (index > 1) {
            before = before->next;
            index--;
        }

        before->next = before->next->next;
        return head;
    }
};
