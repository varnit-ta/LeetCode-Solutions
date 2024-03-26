class Solution(object):
    def rec(self, root, i):
        if root is None:
            return i
            
        i += 1
        left_depth = self.rec(root.left, i)
        right_depth = self.rec(root.right, i)
        return max(left_depth, right_depth)

    def maxDepth(self, root):
        if root is None:
            return 0
        return self.rec(root, 0)
