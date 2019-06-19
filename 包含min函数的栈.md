# 剑指offer - 包含min函数的栈
题目描述：定义栈的数据结构，请在该类型中实现一个能够得到栈中所含最小元素的min函数（时间复杂度应为O（1））。


## 解题思路
- 在普通栈的类里面新增一个辅助栈用于存储最小值
- 每次压栈之前都判断一下这个值是不是比最小更小：
   1. 若是， 则压入辅助栈
   2. 若不是， 则将辅助栈栈顶元素多压一次入栈内。
- 弹出时候， 辅助栈和主数据栈都要同时弹出


## 解法一：用辅助栈存储栈中的最小值

```c++
class Solution {
public:
    void push(int value) {
        data.push( value);
        if (min_stack.empty()||value < min_stack.top()){
            min_stack.push(value);
        }else{
            min_stack.push(min_stack.top());
        }
    }
    void pop() {
        if(!data.empty() && !min_stack.empty()){
            data.pop();
            min_stack.pop();
        }
        
    }
    int top() {
        return data.top();
    }
    int min() {
        return min_stack.top();
    }
 

private:
    stack<int> data;
    stack<int> min_stack;
};

```
