class Solution(object):
    def smallestFromLeaf(self, root):
        def traverse(root, word, words):
            if root:
                word = chr(root.val + 97)  + word
                if not root.left and not root.right:
                    words[0] = min(words[0], word)

                traverse(root.left, word, words)
                traverse(root.right, word, words)

        words = [chr(ord('z') + 1)] 
        traverse(root, "", words)
        return words[0]
