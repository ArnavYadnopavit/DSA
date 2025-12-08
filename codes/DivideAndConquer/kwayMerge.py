# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

# Definition for singly-linked list.
import heapq
class ListNode(object):
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

def build_list(arr):
    dummy = ListNode(0)
    cur = dummy
    for x in arr:
        cur.next = ListNode(x)
        cur = cur.next
    return dummy.next

def print_list(node):
    res = []
    while node:
        res.append(node.val)
        node = node.next
    print(res)


class Solution(object):
    def mergeKLists(self, lists):
        """
        :type lists: List[Optional[ListNode]]
        :rtype: Optional[ListNode]
        """
        n=len(lists)
        if(n==0):
            return None
        hp=[]
        for i in range(n):
            if(lists[i]):
                heapq.heappush(hp,(lists[i].val,id(lists[i]),lists[i]))
        if len(hp)==0:
            return None
        ret=heapq.heappop(hp)[2]
        temp=ret
        while(hp):
            if(temp.next):
                heapq.heappush(hp,(temp.next.val,id(temp.next),temp.next))
            temp.next=heapq.heappop(hp)[2]
            temp=temp.next
        return ret

# lists = [
#   1 -> 4 -> 5
#   1 -> 3 -> 4
#   2 -> 6
# ]

lists = [
    build_list([1, 4, 5]),
    build_list([1, 3, 4]),
    build_list([2, 6])
]
sol = Solution()
result = sol.mergeKLists(lists)
print_list(result)
