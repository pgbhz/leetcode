"""
Given two strings s and t, return true if t is an anagram of s, and false otherwise.

What is an anagram? Same char count.

What is the space complexity that we're looking for?

s and t consist of lowercase english letters only.
"""

from collections import defaultdict


class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False

        s_char_count = defaultdict(int)
        t_char_count = defaultdict(int)

        for i in range(len(s)):
            s_char_count[s[i]] += 1
            t_char_count[t[i]] += 1

        return s_char_count == t_char_count
