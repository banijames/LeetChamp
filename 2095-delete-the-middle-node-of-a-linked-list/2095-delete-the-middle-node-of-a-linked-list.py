# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def deleteMiddle(self, head: Optional[ListNode]) -> Optional[ListNode]:
        #edge case:if one element and removing the middle == empty
        if not head or not head.next:
            return None
        #for finding middle 
        slow,fast=head,head
        fast=fast.next.next
        while fast and fast.next:
            slow=slow.next
            fast=fast.next.next

        #disconnect and deletes the node
        slow.next=slow.next.next
        return head

        
