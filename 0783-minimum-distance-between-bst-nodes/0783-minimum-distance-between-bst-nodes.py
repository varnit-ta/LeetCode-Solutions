class Solution(object):
    def minDiffInBST(self, root):
        def traverse(root, arr):
            if root:
                traverse(root.left, arr)
                arr.append(root.val)
                traverse(root.right, arr)

        arr = []
        traverse(root, arr)

        arr.sort()
        m = abs(arr[0] - arr[1])

        for i in range(1, len(arr)):
            if abs(arr[i-1] - arr[i]) < m:
                m = abs(arr[i-1] - arr[i]) 
        return m