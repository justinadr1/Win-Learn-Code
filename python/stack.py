class Node:
    def __init__(self, val, next):
        self.val = val
        self.bot = next

class Stack:
    def __init__(self):
        self.top = None

    def Push(self, val):
        node = Node(val, self.top)
        self.top = node

    def Pop(self):
        if not self.top:
            print("Stack is empty")
            return
        out = self.top.val
        self.top = self.top.bot
        return out
    
    def Print(self):
        if not self.top:
            print("Stack is empty")
            return
        print(f"{self.top.val} <- top")
        tmp = self.top.bot
        while tmp:
            print(tmp.val)
            tmp = tmp.bot

stack = Stack()

for x in range(100, 900, 100):
    stack.Push(stack)

stack.Print()

out = stack.Pop()
print(f"popped {out}")

stack.Print()