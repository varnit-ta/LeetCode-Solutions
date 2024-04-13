class Solution(object):
    def countNodes(self, root):
        def traverse(root, count=0):
            if root:
                count += 1
                count = traverse(root.left, count)
                count = traverse(root.right, count)
            return count

        return traverse(root)
