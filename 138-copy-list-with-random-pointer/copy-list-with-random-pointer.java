/*
// Definition for a Node.
class Node {
    int val;
    Node next;
    Node random;

    public Node(int val) {
        this.val = val;
        this.next = null;
        this.random = null;
    }
}
*/

class Solution {
    public Node copyRandomList(Node head) {
        if (head == null)
            return null;

        if (head.next == null)
        {
            Node nd = new Node(head.val);
            nd.next = null;
            if (head.random != null)
                nd.random = nd;
            else
                nd.random = null;
            return nd;
        }

        Node newHead = new Node(head.val);
        Node curNode = head;
        newHead.next = new Node(head.next.val);
        HashMap<Integer, Node> indiciesNew = new HashMap<Integer, Node>();
        HashMap<Node, Integer> indiciesOld = new HashMap<Node, Integer>();
        indiciesOld.put(head, 0);
        indiciesNew.put(0, newHead);
        int i = 1;
        curNode = head.next;
        newHead = newHead.next;
        while (curNode != null)
        {  
            if (curNode.next != null)
                newHead.next = new Node(curNode.next.val);
            else
                newHead.next = null;

            indiciesNew.put(i, newHead);
            indiciesOld.put(curNode, i);
            
            newHead = newHead.next;
            curNode = curNode.next;
            i++;
        }

        curNode = head;
        newHead = indiciesNew.get(0);

        while (curNode != null)
        {
            if (curNode.random != null)
                newHead.random = indiciesNew.get(indiciesOld.get(curNode.random));
            
            curNode = curNode.next;
            newHead = newHead.next;
        }

        return indiciesNew.get(0);
    }
}