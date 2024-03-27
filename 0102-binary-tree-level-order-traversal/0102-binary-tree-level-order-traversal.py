class Solution(object):
    def traverse(self, root, level, pos, result):
        if not root:
            return

        if len(result) < level + 1:
            result.append([])
        
        result[level].append(root.val)

        self.traverse(root.left, level + 1, pos * 2, result)
        self.traverse(root.right, level + 1, pos * 2 + 1, result)

    def levelOrder(self, root):
        if not root:
            return []

        result = []

        self.traverse(root, 0, 0, result)

        return result
