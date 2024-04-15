class Solution(object):
    def invertTree(self, root):
        def traverse(root):
            if root:
                root.left, root.right = root.right, root.left
                traverse(root.left)
                traverse(root.right)

        traverse(root)
        return root