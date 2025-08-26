"""
Find the length of the longest substring without duplicate chars.
We can keep a hash map of seen chars and update as we slide through the array.
The tricky thing is to decide when to expand and when to contract.
Bro, remember to always spit the brute force.
What is the brute force? Generate all possible substrings.
Two pointers is @@@ slimy. I love it.
You forgot the empty string case, @@@.
"""


class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        # return self.bruteForce(s) <- always code this @@@ first
        # remember, what leads the two pointers? The right pointer is an inevitable force forward.
        """
        s = "abcabcbb"
        """
        if len(s) == 1:
            return 1
        max_len = 0
        l = 0
        r = 0
        while r < len(s) - 1:
            r += 1
            while s[r] in s[l:r]:
                l += 1
            max_len = max(max_len, r - l + 1)
        return max_len
