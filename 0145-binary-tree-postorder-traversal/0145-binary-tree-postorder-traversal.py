class Solution(object):
    def post(self, root, array):
        if root:
            self.post(root.left, array)
            self.post(root.right, array)
            array.append(root.val)

    def postorderTraversal(self, root):
        result = []
        self.post(root, result)
        return result