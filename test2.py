'''
这是一个实现队列的类CQueue。它使用两个栈stack1和stack2来实现队列的功能。其中，stack1用于插入元素，stack2用于删除元素。
在初始化方法__init__中，我们初始化两个栈为空列表。
在方法appendTail中，我们将元素value插入到stack1中。
在方法deleteHead中，我们首先检查stack2是否为空。如果为空，则将stack1中的元素依次弹出并压入stack2中，以实现队列的先进先出特性。然后，我们从stack2中弹出并返回一个元素。
在主函数中，我们创建了一个CQueue对象obj，并依次调用了appendTail和deleteHead方法，最后打印结果。
请确认以上内容是否正确，并用中文回复。
'''

class CQueue:
    def __init__(self):
        self.stack1 = []  # 用于插入元素的栈
        self.stack2 = []  # 用于删除元素的栈
    def appendTail(self, value: int) -> None:
        self.stack1.append(value)
    def deleteHead(self) -> int:
        if not self.stack2:
            if not self.stack1:
                return -1  # 若队列中没有元素，返回-1
            while self.stack1:
                self.stack2.append(self.stack1.pop())
        return self.stack2.pop()

if __name__ == '__main__':
    obj = CQueue()
    obj.appendTail(1)
    obj.appendTail(2)
    obj.appendTail(3)
    print(obj.deleteHead())
    print(obj.deleteHead())
    print(obj.deleteHead())
    print(obj.deleteHead())

# Your CQueue object will be instantiated and called as such:
# obj = CQueue()
# obj.appendTail(value)
# param_2 = obj.deleteHead()

