class Solution(object):
    def defangIPaddr(self, address):
        result = ""
        
        for k in address:
            if k == '.':
                result += '[.]'
            else:
                result += k

        return result