"""
Reverse words in a string
Maybe I just keep the ins and outs?
Can I do it high level?
Do I need to do it in-place?
Let's do a good CHEAT.
"""


class Solution:
    def reverseWords(self, s: str) -> str:
        words = s.split(" ")
        result = ""
        for word in words[::-1]:
            if word != "":
                result += word + " "
        return result[:-1]
