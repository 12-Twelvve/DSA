class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

    def printData(self):
        print(self.data)

    def insert(self, data):
        if data < self.data:
            if self.left is None:
                self.left = Node(data)
            else:
                self.left.insert(data)
        elif data > self.data:
            if self.right is None:
                self.right = Node(data)
            else:
                self.right.insert(data)

    def insertArray(self, arr):
        for a in arr:
            self.insert(a)

from collections import  deque
queue = deque()
# append -enqueue
# popleft -deque

class levelOrder:
    def __init__(self, root):
        queue.append(root)

    def handler(self):
        while len(queue) != 0:
            root = queue.popleft()
            # print(len(queue))
            root.printData()
            if root.left != None:
                queue.append(root.left)
            if root.right != None:
                queue.append(root.right)


#create a tree
root = Node(12) #root node
arr = [5,14, 50, 11, 10, 3, 56] #insert child nodes
root.insertArray(arr)

order = levelOrder(root)
order.handler()

