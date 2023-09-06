class Solution:
        
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        if (len(lists) == 0): 
            return None
        if (len(lists) == 1): 
            return lists[0]
        result = ListNode(0)
        A = result
        while (True):
            minValue = 100000
            minIndex = -1
            for idx in range(len(lists) - 1, -1, -1): 
                node = lists[idx]
                if (node == None): 
                    lists.pop(idx)
                    if (idx < minIndex): 
                        minIndex -= 1
                    continue
                else: 
                    if (node.val < minValue): 
                        minValue = node.val
                        minIndex = idx
            if (minIndex == -1): 
                break
            result.next = ListNode(minValue)
            lists[minIndex] = lists[minIndex].next
            result = result.next
        return A.next