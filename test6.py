'''
问题描述：
实现一个这样的栈，这个栈除了可以进行普通的push、pop操作以外，还可以进行getMin的操作，getMin方法被调用后，
会返回当前栈的最小值。栈里面存放的都是 int 整数，并且数值的范围是 [-100000, 100000]。
要求所有操作的时间复杂度是 O(1)。且空间复杂度为O(1)。


该代码实现了一个最小栈类。最小栈是一个特殊的栈数据结构，除了支持常规的压入（push）、弹出（pop）操作外，还支持获取栈中的最小值（getMin）操作。
在该类中，使用一个列表（stack）来存储栈中的元素，并使用一个变量（min_value）来记录当前的最小值。在初始化时，将最小值设置为正无穷大。
push方法用于将元素压入栈中。如果新元素小于等于当前的最小值，需要将旧的最小值压入栈中，并更新最小值为新的元素。然后将新元素压入栈中。
pop方法用于弹出栈顶的元素。首先弹出栈顶的元素，并将其存储在变量e中。如果弹出的元素等于当前的最小值，说明最小值已经被弹出，需要重新寻找栈中的最小值。将栈顶的元素再次弹出，并更新最小值为该元素。最后返回变量e。
getMin方法用于获取栈中的最小值，直接返回变量min_value即可。
该实现的时间复杂度为O(1)，空间复杂度为O(n)，其中n为栈中的元素个数。
'''

from math import inf


class MinStack:
    def __init__(self):
        self.stack = []
        self.min_value = inf  # 初始化最小值为正无穷大
        
    def push(self, x: int) -> None:
        if x <= self.min_value:
            # 将旧的最小值压入栈中，更新最小值为新的元素
            self.stack.append(self.min_value)
            self.min_value = x
        self.stack.append(x)
        
    def pop(self) -> int:
        e=self.stack.pop()
        if e == self.min_value:
            # 如果弹出的元素是当前最小值，重新寻找栈中的最小值
            self.min_value = self.stack.pop()
        return e
    def getMin(self) -> int:
        return self.min_value
    
if __name__ == '__main__':
    stack = MinStack()
    stack.push(3)
    stack.push(2)
    stack.push(1)
    stack.push(5)
    stack.push(0)
    stack.push(-1)
    print(stack.getMin())
    print(stack.pop())
    print(stack.getMin()) 
    print(stack.pop())
    print(stack.getMin()) 
    print(stack.pop())
    print(stack.getMin()) 
    print(stack.pop())
    print(stack.getMin()) 
    print(stack.pop())