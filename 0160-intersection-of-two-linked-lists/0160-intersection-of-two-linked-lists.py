class Solution(object):
    def getIntersectionNode(self, headA, headB):
        visitedA = set()
        
        ptrA = headA
        while ptrA:
            visitedA.add(ptrA)
            ptrA = ptrA.next
        
        ptrB = headB
        while ptrB:
            if ptrB in visitedA:
                return ptrB
            ptrB = ptrB.next
        
        return None
