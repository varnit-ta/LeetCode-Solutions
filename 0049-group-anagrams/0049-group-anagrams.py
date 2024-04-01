class Solution(object):
    def groupAnagrams(self, strs):
        store = {}

        for word in strs:
            word = word.lower()
            arr = [0]*26

            for letter in word:
                arr[ord(letter) - 97] += 1

            arr_tuple = tuple(arr)

            if arr_tuple in store:
                store[arr_tuple].append(word)
            else:
                store[arr_tuple] = [word]

        return list(store.values())
