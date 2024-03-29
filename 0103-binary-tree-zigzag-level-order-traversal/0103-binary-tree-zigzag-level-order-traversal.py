class Solution(object):
    def traverse(self, root, level, result, side):
        if not root:
            return

        if len(result) < level + 1:
            result.append([])
        
        if side == 1:
            result[level].append(root.val)
        else:
            result[level].insert(0, root.val)

        self.traverse(root.left, level + 1, result, 1 if side == -1 else -1)
        self.traverse(root.right, level + 1, result, 1 if side == -1 else -1)

    def zigzagLevelOrder(self, root):
        if not root:
            return []

        result = []

        self.traverse(root, 0, result, 1)

        return result