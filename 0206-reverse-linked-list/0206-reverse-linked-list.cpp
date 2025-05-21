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
        if(head == NULL || head->next == NULL)return head;

        ListNode *newHead = head;
        ListNode *tail = NULL;
        head = head->next;
        newHead->next = NULL;
        while(head){
            tail = head;
            head = head->next;
            tail->next = newHead;
            newHead = tail;
        }
        return newHead;
    }
};