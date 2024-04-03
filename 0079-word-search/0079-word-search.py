class Solution(object):
    result = False

    def traverse(self, board, word, board_pos, word_pos, array):
        if word_pos == len(word):
            self.result = True
            return

        temp = board[board_pos[0]][board_pos[1]]
        board[board_pos[0]][board_pos[1]] = "#"

        directions = [(0, 1), (0, -1), (1, 0), (-1, 0)]
        for dx, dy in directions:
            next_x, next_y = board_pos[0] + dx, board_pos[1] + dy

            if 0 <= next_x < len(board) and 0 <= next_y < len(board[0]) and board[next_x][next_y] == word[word_pos]:
                self.traverse(board, word, (next_x, next_y), word_pos + 1, array + [board[next_x][next_y]])

        board[board_pos[0]][board_pos[1]] = temp

    def exist(self, board, word): 
        for i in range(len(board)):
            for j in range(len(board[0])):
                if board[i][j] == word[0]:
                    self.traverse(board, word, (i, j), 1, [board[i][j]])
        return self.result
