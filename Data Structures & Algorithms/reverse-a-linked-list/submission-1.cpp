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
    ListNode* reverseList(ListNode* head) {
        ListNode *current, *follow, *ahead;
        if(head == NULL){
            return head;
        }
        current = head;
        follow = NULL;

        while(current != NULL){
            ahead = current->next;
            current->next = follow;
            follow = current;
            current = ahead;
        }
        head = follow;
        return head;
    }
};
