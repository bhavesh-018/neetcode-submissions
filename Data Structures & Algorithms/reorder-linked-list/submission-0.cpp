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
    void reorderList(ListNode* head) {
        ListNode *slow, *fast, *first, *second, *follow, *ahead, *tmp1, *tmp2;
        slow = fast = head;

        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        second = slow->next;
        slow->next = NULL;
        follow = NULL;

        while(second){
            ahead = second->next;
            second->next = follow;
            follow = second;
            second = ahead;
        }

        first = head;
        second = follow;

        while(second){
            tmp1 = first->next;
            tmp2 = second->next;
            first->next = second;
            second->next = tmp1;
            first = tmp1;
            second = tmp2;
        }
    }
};
