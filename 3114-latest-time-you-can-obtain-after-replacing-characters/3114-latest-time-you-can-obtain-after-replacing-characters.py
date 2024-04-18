class Solution(object):
    def findLatestTime(self, s):
        hours, minutes = s.split(':')
    
        if hours[0] == '?':
            if hours[1] in ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9']:
                if int(hours[1]) > 1:
                    hours = "0" + hours[1]
                else:
                    hours = "1" + hours[1] 
            else:
                hours = '1' + hours[1]

        if hours[1] == '?':
            if hours[0] == '1':
                hours = hours[0] + '1'
            else:
                hours = hours[0] + '9'
        
        if minutes[0] == '?':
            minutes = '5' + minutes[1]
        if minutes[1] == '?':
            minutes = minutes[0] + '9'
        
        return hours + ':' + minutes
        