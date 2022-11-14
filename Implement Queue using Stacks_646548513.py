class MyQueue:

    def __init__(self):
        self.stack1 = []
        self.stack2 = []

    def push(self, x: int) -> None:
        self.stack1.append(x)
        print(self.stack1)

    def pop(self) -> int:
        while len(self.stack1) > 1:
            top = self.stack1.pop()
            self.stack2.append(top)
        org_top = self.stack1.pop()
        while len(self.stack2) > 0:
            top = self.stack2.pop()
            self.stack1.append(top)
        print(self.stack1)
        return org_top

    def peek(self) -> int:
        while len(self.stack1) > 1:
            top = self.stack1.pop()
            self.stack2.append(top)
        org_top = self.stack1.pop()
        self.stack2.append(org_top)
        # self.stack1.append(top)
        while len(self.stack2) > 0:
            top = self.stack2.pop()
            self.stack1.append(top)
        print(self.stack1, "**")
        return org_top

    def empty(self) -> bool:
        return len(self.stack1) == 0


# Your MyQueue object will be instantiated and called as such:
# obj = MyQueue()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.peek()
# param_4 = obj.empty()
