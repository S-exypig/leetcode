from ast import main
from typing import List


class Solution:
    def validateStackSequences(self,pushed: List[int], popped: List[int]) -> bool:
        stk=[]
        i=0
        for e in pushed:
            stk.append(e)
            while stk and stk[-1]==popped[i]:
                stk.pop()
                i+=1
        return i==len(popped)
    
if __name__ == '__main__':
    pushed = [1, 2, 3, 4, 5]
    popped = [4, 5, 3, 2, 1]
    print(Solution().validateStackSequences(pushed, popped))  # 输出 True
    popped = [4, 3, 5, 1, 2]
    print(Solution().validateStackSequences(pushed, popped))  # 输出 False
