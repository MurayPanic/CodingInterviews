# 剑指offer- 链表中倒数第k个节点

题目描述：输入一个链表，输出该链表中倒数第k个结点。



## 解题思路：
- 基础思路是遍历链表两遍，第一遍知道链表长度n， 第二遍遍历到第n-k+1个节点
- 为了只遍历一次，采用双指针策略，两个指针相聚k-1个节点。
- 当在前面的节点遍历到链表的尾部的时候，后面的节点就是倒数第k个节点。
- 注意考虑链表为空链表，或者链表长度小于k的情况。


## 解法一：双指针法

```c++
/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        
        if(pListHead == nullptr){return nullptr;}
        ListNode* firstPointer = pListHead;
        ListNode* secondPointer = pListHead;
        
        for(int i = 1; i<=k-1; ++i){
            if(firstPointer ->next != nullptr){ firstPointer = firstPointer ->next;}
            else{
                if (i<= k-1){return nullptr;}
            }
        }
        
        
        while(firstPointer ->next != nullptr){
            secondPointer = secondPointer->next;
            firstPointer = firstPointer ->next;
            
        }
        
        return secondPointer;
    
    }
};

```
