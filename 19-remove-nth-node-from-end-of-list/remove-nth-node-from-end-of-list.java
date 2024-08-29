/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode removeNthFromEnd(ListNode head, int n) {
        ArrayList<ListNode> nodes = new ArrayList<ListNode>();
        ListNode retNode = head;

        while (head != null)
        {
            nodes.add(head);
            head = head.next;
        }

        if (nodes.size() == 1)
            return null;
        else if (n == 1)
        {
            nodes.get(nodes.size() - 2).next = null;
        }
        else if (n == nodes.size())
        {
            retNode = nodes.get(1);
        }
        else
        {
            n = nodes.size() - n;
            nodes.get(n - 1).next = nodes.get(n + 1);
        }

        return retNode;
    }
}