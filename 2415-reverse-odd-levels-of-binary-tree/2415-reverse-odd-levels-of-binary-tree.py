class Solution(object):
    def reverseOddLevels(self, root):
        arr = []

        def traverse(node, level=0):
            if node:
                if level % 2 != 0:
                    if len(arr) <= level // 2:
                        arr.append([])
                    arr[level//2].append(node)
                traverse(node.left, level + 1)
                traverse(node.right, level + 1)

        traverse(root)

        for level in arr:
            left, right = 0, len(level) - 1
            while left < right:
                level[left].val, level[right].val = level[right].val, level[left].val
                left += 1
                right -= 1

        return root