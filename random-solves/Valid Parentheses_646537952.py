class Solution:
    def isValid(self, str: str) -> bool:
        s = []
        for c in str:
            if c in "({[":
                s.append(c)
                print(c)
            else:
                if len(s) == 0:
                    return False
                top = s.pop()
                print(top, c)
                if top == '(' and c == ')':
                    pass
                elif top == '{' and c == '}':
                    pass
                elif top == '[' and c == ']':
                    pass
                else:
                    return False
        return len(s) == 0
