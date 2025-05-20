/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public void DeleteNode(ListNode node) {
        ListNode temp = null;
        while(node.next != null){
            temp = node;
            node.val = node.next.val;
            node = node.next;

        }
        temp.next = null;
        
    }
}