"""
Merge all overlapping intervals, return an array of non-overlapping intervals that covers
all the intervals in the input.

Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]


Can we do this iteratively? Should we do it recursively?
Should we do it in place?
Wait, I forgot to ask some questions.

- What is the size of the input? from 1 to 10e4
- every interval is a two-sized list

We can, temporarily, build a merged interval. Until we don't see a non-overlapping interval,
we're building that object. When do we finish the building process? When we reach that non-overlapping interval.

What is the complexity of this? Linear, I suppose.
Can we have an additional array? Let's suppose yes.
Is it possible for the start of a subsequent interval to be smaller than of a previous interval?

- The input is sort of misleading. It is apparently sorted, but this may not be the case.

Solution is somewhat esoteric, for connected components.

Key takeaways:
    - O(n log n) for sorting
    - Never take sorted input for granted
    - You can build things inplace in the output
"""

from typing import List


class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        intervals.sort(key=lambda x: x[0])
        merged = []
        for interval in intervals:
            # if merged is empty: just throw the first interval there to start mergin
            # if current element of merged ends before the start of the current interval: no overlap
            if len(merged) == 0 or merged[-1][1] < interval[0]:
                merged.append(interval)
            else:
                merged[-1][1] = max(merged[-1][1], interval[1])
        return merged
