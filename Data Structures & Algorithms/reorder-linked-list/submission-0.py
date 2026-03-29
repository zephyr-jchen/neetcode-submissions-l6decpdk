# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:

    def midNode(self,head: Optional[ListNode]) -> Optional[ListNode]:
            slow = head
            fast = head
            while fast and fast.next:
                slow = slow.next
                fast = fast.next.next
            return slow
        
    def reverseList(self,head: Optional[ListNode]) -> Optional[ListNode]:
        pre = None
        cur = head
        while cur:
            nxt = cur.next
            cur.next = pre
            pre = cur
            cur = nxt
        return pre

    def reorderList(self, head: Optional[ListNode]) -> None:
        mid = self.midNode(head)
        head2 = self.reverseList(mid)
        head1 = head
        while head2.next:
            tmp1 = head1.next
            tmp2 = head2.next
            head1.next = head2
            head2.next = tmp1
            head1 = tmp1
            head2 = tmp2
        return
        

        


        