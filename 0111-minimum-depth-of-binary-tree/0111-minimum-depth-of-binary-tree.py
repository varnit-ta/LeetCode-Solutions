class Solution(object):
    def minDepth(self, root):
        arr = []

        def traverse(root, level=1, arr=arr):
            if root:
                traverse(root.left, level+1)

                if not root.left and not root.right:
                    arr.append(level)

                traverse(root.right, level+1)

        traverse(root)

        return min(arr) if arr else 0