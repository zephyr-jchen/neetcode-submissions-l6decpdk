class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        mapping = {']':'[',')':'(','}':'{'}
        for c in s:
            if c in mapping:
                top = stack.pop() if stack else  '#'
                if top != mapping[c]:
                    return False
            else:
                stack.append(c)
        return not stack