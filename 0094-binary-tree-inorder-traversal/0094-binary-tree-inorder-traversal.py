class Solution(object):
    def inorderTraversal(self, root):
        def traverse(root, arr):
            if root:
                traverse(root.left, arr)
                arr.append(root.val)
                traverse(root.right, arr)

        arr = []
        traverse(root, arr)
        return arr