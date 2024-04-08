class Solution(object):
    def binaryTreePaths(self, root):
        result = []
        self.traverse([], root, result)
        return result

    def traverse(self, path, root, result):
        if root:
            path.append(str(root.val))
            if not root.left and not root.right:
                result.append("->".join(path))
            else:
                self.traverse(path, root.left, result)
                self.traverse(path[:], root.right, result)
            path.pop()