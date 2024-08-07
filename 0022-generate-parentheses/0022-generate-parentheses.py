class Solution(object):
    def generateParenthesis(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        def backtrack(current, open_count, close_count):
            # If the current combination is of length 2 * n, it's a valid combination
            if len(current) == 2 * n:
                result.append(current)
                return
            
            # If we can add an open parenthesis, do so and recurse
            if open_count < n:
                backtrack(current + '(', open_count + 1, close_count)
            
            # If we can add a close parenthesis, do so and recurse
            if close_count < open_count:
                backtrack(current + ')', open_count, close_count + 1)
        
        result = []
        backtrack('', 0, 0)
        return result