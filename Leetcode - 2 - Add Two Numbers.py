# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        newHead1 = l1
        newHead2 = l2
        A = ListNode(0)
        newHead = A
        while (newHead1 != None or newHead2 != None): 
            add = 0
            if (newHead1 == None): 
                add = newHead2.val
                newHead2 = newHead2.next
            elif (newHead2 == None): 
                add = newHead1.val
                newHead1 = newHead1.next
            else: 
                add = newHead1.val + newHead2.val
                newHead2 = newHead2.next
                newHead1 = newHead1.next

            if (add >= 10): 
                newResult = ListNode(add % 10)
                newHead.next = newResult
                if newHead1 != None: 
                    newHead1.val += 1
                elif newHead2 != None: 
                    newHead2.val += 1
                else: 
                    newHead = newHead.next
                    newResult = ListNode(1)
                    newHead.next = newResult
                    return A.next
            else: 
                newResult = ListNode(add)
                newHead.next = newResult
            
            newHead = newHead.next
        return A.next
                 