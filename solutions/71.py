"""
This is a parsing problem, which are usually solved using stacks.
There are some rules, which make me think about just skipping to the solution.
If we face '.' that is some sort of no-op. We just skip parsing that.
If we face '..' we pop last dir from the stack. Because we came back to it.
Otherwise we append that to the stack.
Actually, this is a very cool problem.
"""


class Solution:
    def simplifyPath(self, path: str) -> str:
        stack = []

        # Input: path = "/home/user/Documents/../Pictures"
        for token in path.split("/"):  # home user Documents .. Pictures
            if token == "." or not token:
                continue
            if token == "..":  # True
                if stack:
                    stack.pop()
                continue
            stack.append(token)  # home user Pictures
        simplified_path = "/" + "/".join(stack)  # /home/user/Pictures
        return simplified_path
