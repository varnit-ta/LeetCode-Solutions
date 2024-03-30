class Solution(object):
    def preOrder(self, root, result):
        if root:
            result.append(root.val)
            self.preOrder(root.left, result)
            self.preOrder(root.right, result)
            
    def preorderTraversal(self, root):
        array = []
        self.preOrder(root, array)
        return array