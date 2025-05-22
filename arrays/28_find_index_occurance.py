"""
Get the first occurrence of str needle in str haystack.
A two pointers approach will do the job.
Why?
We increment a first pointer, from the 0th to the
(len(haystack) - len(needle))th position. For each position,
we increment a second pointer while the characters match.

This has a complexity of n * m, where n is the len of haystack
and m is the len of the needle. But this supposes that a partial match of m-1 keeps occurring.

Is there a better way to do this?
Is there a O(n) way to do this?

We can just go from the beginning to end.
If we are "seeing" the needle, we keep matching characters until the needle is seen.
Otherwise, we start "seeing" when the first character match.
If we are "seeing" the needle and a character mismatch occurs, then we stop "seeing".

bug log

attempt 1:
    - we begin not "seeing", but we could begin "seeing".
    - we could be not "seeing" but start to "see".
    - we need to update "startedSeeingAt" when "seeing" changes state.

attempt 2:

"""


class Solution:
    """
    Testcase:

        mississippi   issip
        01234567890   01234
    """

    def strStr(self, haystack: str, needle: str) -> int:
        n = len(needle)
        m = len(haystack)
        for window_start in range(0, m - n + 1):
            for i in range(n):
                if needle[i] != haystack[window_start + i]:
                    break
                if i == n - 1:
                    return window_start
        return -1
