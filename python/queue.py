# would this also work?
import sys

class Node:
    def __init__(self, val, next=None):
        self.val = val
        self.next = next

class Queue:
    def __init__(self):
        self.front = None
        self.rear = None

    def Enqueue(self, val):
        node = Node(val)
        if not self.front:
            self.front = self.rear = node
        else:
            self.rear.next = node
            self.rear = node

    def Dequeue(self):
        if not self.front:
            print("Queue is empty")
            return
        out = self.front.val
        self.front = self.front.next
        if self.front is None:
            self.rear = None
        return out
    
    def Print(self):
        if not self.front:
            print("Queue is empty")
            return
        print(f"{self.front.val} <- front")
        tmp = self.front.next
        while tmp:
            if not tmp.next:
                print(f"{tmp.val} <- rear")
                break
            print(tmp.val)
            tmp = tmp.next

q = Queue()

q.Enqueue(40)
q.Enqueue(50)
q.Enqueue(60)
q.Enqueue(70)

q.Print()
            