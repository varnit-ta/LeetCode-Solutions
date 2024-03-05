class Solution(object):
    def pivotInteger(self, n):
        ias = True
        l = []
        
        for i in range(1,n+1):
            l.append(i)
            
        for x in range(len(l)):
            if sum(l[:x+1]) == sum(l[x:]):
                return l[x]
                break
            else:
                ias = False
                
        if ias == False:
            return -1