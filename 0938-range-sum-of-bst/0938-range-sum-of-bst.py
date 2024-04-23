class Solution(object):
    def rangeSumBST(self, root, low, high):
        if root:
            if low <= root.val <= high:
                return root.val + self.rangeSumBST(root.left, low, high) + self.rangeSumBST(root.right, low, high)
            else:
                return self.rangeSumBST(root.left, low, high) + self.rangeSumBST(root.right, low, high)
        else:
            return 0
