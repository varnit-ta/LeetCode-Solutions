class Solution(object):
    def sumNumbers(self, root):
        result = [0]

        def traverse(root, num):
            if root:
                num += str(root.val)
                if not root.left and not root.right:
                    result[0] += int(num)

                traverse(root.left, num)
                traverse(root.right, num)

        traverse(root, "")
        return result[0]