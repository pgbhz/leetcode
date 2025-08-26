"""
This questions smells like stack.
Parse the input using a stack.
If the stack is not empty at the end of the parsing, it's not valid.
Also, if the top of the stack is not valid for the current closing symbol, it is not valid.
"""


class Solution:
    def isValid(self, s: str) -> bool:
        matches = {"(": ")", "{": "}", "[": "]"}
        stack = []
        for symbol in s:
            if symbol in matches:
                stack.append(symbol)
            else:
                if stack:
                    if symbol != matches[stack[-1]]:
                        return False
                    stack.pop()
                else:
                    return False
        if stack:
            return False
        return True
