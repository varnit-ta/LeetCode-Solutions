class Solution(object):
    def hasCycle(self, head):
        ptr = head

        if ptr == None:
            return False

        while ptr.next != None:
            if type(ptr.val) == str:
                return True
            else:
                ptr.val = str(ptr.val)

            ptr = ptr.next

        return False