import heapq

class Solution:
    def longestDiverseString(self, a: int, b: int, c: int) -> str:
        pq = []
        if a > 0:
            heapq.heappush(pq, (-a, 'a'))
        if b > 0:
            heapq.heappush(pq, (-b, 'b'))
        if c > 0:
            heapq.heappush(pq, (-c, 'c'))
        result = ""
        while pq:
            count, letter = heapq.heappop(pq)
            if len(result) >= 2 and letter == result[-1] and letter == result[-2]:
                if not pq:
                    break
                next_count, next_letter = heapq.heappop(pq)
                result += next_letter
                next_count += 1
                if next_count < 0:
                    heapq.heappush(pq, (next_count, next_letter))
                heapq.heappush(pq, (count, letter))
            else:
                result += letter
                count += 1
                if count < 0:
                    heapq.heappush(pq, (count, letter))
        return result