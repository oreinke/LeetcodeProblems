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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode();
        ListNode* cur = head;

        int carry = 0;
        while (l1 != nullptr && l2 != nullptr) {
            cur->next = new ListNode();
            cur = cur->next;
            cur->val = (l1->val + l2->val + carry) % 10;
            carry = (l1->val + l2->val + carry) / 10;
            l1 = l1->next;
            l2 = l2->next;
        }

        while (l1 != nullptr) {
            cur->next = new ListNode();
            cur = cur->next;
            cur->val = (l1->val + carry) % 10;
            carry = (l1->val + carry) / 10;
            l1 = l1->next;
        }

        while (l2 != nullptr) {
            cur->next = new ListNode();
            cur = cur->next;
            cur->val = (l2->val + carry) % 10;
            carry = (l2->val + carry) / 10;
            l2 = l2->next;
        }

        if (carry > 0) {
            cur->next = new ListNode();
            cur = cur->next;
            cur->val = carry;
        }
        head = head->next;

        return head;
    }
};