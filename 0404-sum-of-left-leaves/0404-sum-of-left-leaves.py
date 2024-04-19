class Solution(object):
    def sumOfLeftLeaves(self, root):
        result = [0]

        def traverse(root, side):
            if root:
                if side == "l" and not root.left and not root.right:
                    result[0] += root.val
                traverse(root.left, "l")
                traverse(root.right, "r")

        traverse(root, "m")
        return result[0]