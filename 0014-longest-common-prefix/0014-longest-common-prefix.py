class Solution(object):
    def longestCommonPrefix(self, strs):
        result = ""
        breakLoop = False  
        minString = min(strs, key=len)

        for i in range(0, len(minString)):
            char = minString[i]

            inChar = ""

            for j in range(0, len(strs)):
                if strs[j][i] != char:
                    breakLoop = True
                    break
                else:
                    inChar = strs[j][i]
            
            if breakLoop:
                break   
            else:
                result += inChar
    
        return result