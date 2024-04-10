class Solution(object):
    def traverse(self, root, arr, level):
        if root:
            self.traverse(root.left, arr, level+1)
            arr.append([root.val, level])
            self.traverse(root.right, arr, level+1)
        else:
            arr.append([None, level])

    def isSymmetric(self, root):
        left_arr = []
        right_arr = []

        self.traverse(root.left, left_arr, 0)
        self.traverse(root.right, right_arr, 0)

        if left_arr[::-1] == right_arr:
            return True
        else:
            return False