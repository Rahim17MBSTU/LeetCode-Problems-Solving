/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int val=0, ListNode next=null) {
 *         this.val = val;
 *         this.next = next;
 *     }
 * }
 */
public class Solution {
    public ListNode OddEvenList(ListNode head) {
       if(head == null)return head;
       if(head.next == null)return head;
       ListNode odd = null;
       ListNode oddhead = null;
       ListNode eventail = null;
       ListNode evenhead = null;
       ListNode tail = null;
       int cnt = 1;
       while(head!=null){
            if(cnt % 2 == 1){
                if(oddhead == null){
                    oddhead = tail = head;
                }else{
                    tail.next = head;
                    tail = head;
                }
            }else{
                if(evenhead == null){
                    evenhead = head;
                    eventail = head;
                }else{
                    eventail . next = head;
                    eventail = head;
                }
            }
            head = head.next;
            cnt++;
       }
       tail.next = null;
        eventail.next = null;
       tail.next = evenhead;
       return oddhead;


    }
}