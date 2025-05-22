"""
I can hash each word into it's own anagrammic signature.
How? Counter.
Damn, Counter not hashable.
Input: strs = ["eat","tea","tan","ate","nat","bat"]

Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
"""

from collections import Counter, defaultdict
from typing import List


class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        anagrams = defaultdict(list)
        for word in strs:
            hashed_word = ""
            counter = Counter(word)
            for k in sorted(counter.keys()):
                hashed_word += str(k) + str(counter[k])
            anagrams[hashed_word].append(word)

        grouped_anagrams = []
        for category in anagrams.values():
            grouped_anagrams.append(category)

        return grouped_anagrams
