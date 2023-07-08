'''
给定两个非空链表，表示两个非负整数。数字以相反的顺序存储，每个节点包含一个数字。将这两个数字相加并以相同的方式返回一个新的链表。
 首先，我们将两个链表分别反转，然后从头开始遍历两个链表，将对应节点的值相加，并考虑进位。如果相加的结果大于等于10，则需要进位。我们使用一个标志位flag来表示是否需要进位。
 创建一个新的链表res来存储相加的结果。我们使用一个指针cur来指向当前节点。遍历过程中，如果res为空，则将当前节点作为头节点赋值给res，并将cur指向res。否则，将当前节点添加到cur的后面，并更新cur为新添加的节点。
 当其中一个链表遍历完后，我们需要将另一个链表的剩余部分添加到结果链表中。最后，我们需要将结果链表反转，然后返回。
 时间复杂度：O(max(m, n))，其中m和n分别是两个链表的长度。
空间复杂度：O(max(m, n))，需要创建一个新的链表来存储结果。

'''

# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None
        
class Solution:
    def twoSum(headA:ListNode,headB:ListNode)->ListNode:
        if not headA or not headB:
            return headA if headA else headB
        def reverseList(head:ListNode)->ListNode:
            if not head or not head.next:
                return head
            pre=None
            cur=head
            nex=head.next
            while nex:
                cur.next=pre
                pre=cur
                cur=nex
                nex=nex.next
            cur.next=pre
            return cur
        headA=reverseList(headA)
        headB=reverseList(headB)
        res:ListNode=None
        flag:bool=False
        cur:ListNode=None
        while headA and headB:
            num=headA.val+headB.val+(1 if flag else 0)
            flag=False
            if num>=10:
                num-=10
                flag=True
            if res is None:
                res=ListNode(num)
                cur=res
            else:
                cur.next=ListNode(num)
                cur=cur.next
            headA,headB=headA.next,headB.next
        headB=headA if headA else headB
        while headB:
            cur.next=ListNode(headB.val)
            headB,cur=headB.next,cur.next
        res=reverseList(res)
        return res
    
if __name__ == '__main__':
    A:ListNode=ListNode(1)
    cur=A
    for i in range(2,5):
        cur.next=ListNode(i)
        cur=cur.next
    B:ListNode=ListNode(3)
    B.next=ListNode(4)
    res=Solution.twoSum(A,B)
    cur=res
    while cur:
        print(cur.val)
        cur=cur.next
    