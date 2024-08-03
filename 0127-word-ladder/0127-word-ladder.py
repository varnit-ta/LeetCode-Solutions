import collections

class Solution(object):
    def ladderLength(self, beginWord, endWord, wordList):
        if endWord not in wordList:
            return 0
        
        wordList.append(beginWord)
        graph = collections.defaultdict(list)
        
        def make_graph():
            for wrd in wordList:
                for i in range(len(wrd)):
                    x = wrd[:i] + "*" + wrd[i+1:]
                    graph[x].append(wrd)

        make_graph()

        # BFS
        def bfs():
            queue = collections.deque([(beginWord, 1)])
            visited = set()
            visited.add(beginWord)

            while queue:
                current_word, level = queue.popleft()
                
                for i in range(len(current_word)):
                    intermediate_word = current_word[:i] + "*" + current_word[i+1:]
                    for neighbor in graph[intermediate_word]:
                        if neighbor == endWord:
                            return level + 1
                        if neighbor not in visited:
                            visited.add(neighbor)
                            queue.append((neighbor, level + 1))
            return 0

        return bfs()
