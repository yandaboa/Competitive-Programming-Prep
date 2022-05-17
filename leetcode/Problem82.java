
class ListNode {
    int val;
    ListNode next;
    ListNode() {}
    ListNode(int val) { this.val = val; }
    ListNode(int val, ListNode next) { this.val = val; this.next = next; }
}

class Solution {
    public ListNode deleteDuplicates(ListNode head) {
        ListNode temp = head;
        ListNode sentinel = head;
        if(head.next == null){
            return head;
        }
        while(temp.next.val == temp.val){
            temp = temp.next;
        }
        sentinel = temp.next;
        temp = temp.next;
        head = sentinel;
        while(temp.next != null){
            while(temp.val == temp.next.val){
                temp = temp.next;
            }
            sentinel.next = temp.next;
            sentinel = sentinel.next;
            temp = temp.next;
        }
        return sentinel;
    }
}