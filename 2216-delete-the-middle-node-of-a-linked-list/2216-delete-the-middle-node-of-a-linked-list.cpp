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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode *temp = head;
        int cnt = 0 ; 
        while(temp != NULL){
            cnt++;
            temp = temp->next;
        }
        temp = head;
        cnt/=2;
        cnt++;
        temp = head;
        int pos = 1;
        while(pos < cnt-1){
            temp= temp->next;
            pos++;
        }
        if(temp->next != nullptr)
            temp -> next = temp->next->next;
        else{
            
            head = nullptr;
            
        }
        return head;
    }
};