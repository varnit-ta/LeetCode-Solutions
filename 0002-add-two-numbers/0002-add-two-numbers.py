# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        def linkedListToList(self, head):
            if not head:
                return []
            pointer = head
            sll_list = []
            while pointer:
                sll_list.append(pointer.val)
                pointer = pointer.next
            return sll_list

        def jn(l):
            for i in range(len(l)):
                l[i] = str(l[i])
            return l
        
        l1 = int(''.join(jn(linkedListToList(self,l1)[::-1])))
        l2 = int(''.join(jn(linkedListToList(self,l2)[::-1])))
        
        h = ','.join(list(str(l1 +l2))[::-1])
        i = ListNode(h)
        return i     
        