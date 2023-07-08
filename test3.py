'''
这是一个用两个队列实现栈的类。主要的思路是，将元素压入非空的队列中，然后将另一个队列中的元素依次出队并入队到非空的队列中，
这样保证了栈的后进先出的特性。具体的实现如下：
- 初始化时，创建两个空的双端队列queue1和queue2。
- push方法：如果queue1非空，则将元素x压入queue1中；如果queue1为空，则将元素x压入queue2中。
- pop方法：如果queue1非空，则将queue1中的元素依次出队并入队到queue2中，直到queue1中只剩下一个元素，然后返回该元素；如果queue1为空，则将queue2中的元素依次出队并入队到queue1中，直到queue2中只剩下一个元素，然后返回该元素。
- top方法：如果queue1非空，则返回queue1的最后一个元素；如果queue1为空，则返回queue2的最后一个元素。
- empty方法：如果queue1和queue2都为空，则返回True；否则返回False。
'''

from collections import deque


class MyStack:

    def __init__(self):
        self.queue1:deque=deque()
        self.queue2:deque=deque()

    def push(self, x: int) -> None:
        if self.queue1:
            self.queue1.append(x)
        else:
            self.queue2.append(x)
    def pop(self) -> int:
        if self.queue1:
            while len(self.queue1)>1:
                self.queue2.append(self.queue1.popleft())
            return self.queue1.popleft()
        else:
            while len(self.queue2)>1:
                self.queue1.append(self.queue2.popleft())
            return self.queue2.popleft()

    def top(self) -> int:
        return self.queue1[-1] if self.queue1 else self.queue2[-1]

    def empty(self) -> bool:
        return not self.queue1 and not self.queue2


# Your MyStack object will be instantiated and called as such:
# obj = MyStack()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.top()
# param_4 = obj.empty()