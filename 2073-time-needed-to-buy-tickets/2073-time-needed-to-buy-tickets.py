class Solution(object):
    def timeRequiredToBuy(self, tickets, k):
        time = 0
        i = 0
        m = 0

        while tickets:
            print(i, tickets[i], m)

            if i == 0:
                m = min(tickets)
                if tickets[k] == m and tickets[k] != 1:
                    m -= 1

            tickets[i] -= m
            time += m

            if tickets[i] == 0:
                tickets.pop(i)

                if i == k:
                    return time

                if i < k:
                    k -= 1
                i = i % len(tickets)
            else:
                i = (i+1) % len(tickets)