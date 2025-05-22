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


class Solution:
    def reverseWords(self, s: str) -> str:
        """
        Input: s = "the sky is blue"
                    012345678901234
                    012
        Output: "blue is sky the"
        """
        stack = []
        word_start_idx = 0
        started_seeing_word = False
        for i in range(len(s)):
            if s[i] != " " and not started_seeing_word:
                started_seeing_word = True
                word_start_idx = i

            elif s[i] == " " and started_seeing_word:
                word = s[word_start_idx:i]
                stack.append(word)
                started_seeing_word = False

        if started_seeing_word:
            word = s[word_start_idx : len(s)]
            stack.append(word)

        reversed_words = ""
        while stack:
            reversed_words += stack.pop() + " "
        return reversed_words[:-1]
