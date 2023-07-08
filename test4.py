'''
该代码实现了一个最小栈的数据结构。它具有以下方法：
-  `__init__` ：初始化数据结构。
-  `push` ：将元素x推入栈中，并在最小栈中维护当前最小值。
-  `pop` ：从栈中弹出元素，并在最小栈中更新最小值。
-  `top` ：返回栈顶元素。
-  `min` ：返回最小栈中的最小值。
该数据结构使用两个栈来实现。一个栈用于存储元素，另一个栈用于存储当前最小值。每当元素被推入栈中时，如果最小栈为空或者新元素小于等于最小栈的栈顶元素，则将新元素也推入最小栈中。每当元素被弹出栈时，如果弹出的元素等于最小栈的栈顶元素，则同时从最小栈中弹出栈顶元素。
这样，无论何时需要获取最小值，只需访问最小栈的栈顶元素即可。该数据结构的时间复杂度为O(1)。
'''

print('hello world')

class MinStack:
    def __init__(self):
        self.stack=[]  # 用于存储栈中的元素
        self.min_stack=[]  # 用于存储当前栈中的最小元素

    def push(self, x: int) -> None:
        self.stack.append(x)  # 将元素 x 入栈
        if not self.min_stack or x <= self.min_stack[-1]:
            self.min_stack.append(x)  # 如果当前元素 x 是最小元素，则将其入最小栈

    def pop(self)->None:
        if self.stack.pop() == self.min_stack[-1]:
            self.min_stack.pop()  # 如果出栈的元素是最小元素，则将最小栈中的对应元素也出栈

    def top(self)->int:
        return self.stack[-1]  # 返回栈顶元素

    def min(self)->int:
        return self.min_stack[-1]  # 返回当前栈中的最小元素


# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(x)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.min()
