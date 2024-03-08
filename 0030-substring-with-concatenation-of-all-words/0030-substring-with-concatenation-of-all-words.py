class Solution(object):
    def check(self, s, word_count, word_length):
        # Count occurrences of words in the current substring
        current_word_count = Counter()
        for i in range(0, len(s), word_length):
            word = s[i : i + word_length]
            current_word_count[word] += 1
        
        return current_word_count == word_count

    def findSubstring(self, s, words):
        result = []

        if s == "".join(words):
            return [0]

        word_count = Counter(words)
        word_length = len(words[0])
        total_length = len(words) * word_length

        for i in range(len(s) - total_length + 1):
            substring = s[i : i + total_length]
            if self.check(substring, word_count, word_length):
                result.append(i)

        return result
