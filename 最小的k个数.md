# 剑指offer - 最小的k个数
题目描述：输入n个整数，找出其中最小的K个数。例如输入4,5,1,6,2,7,3,8这8个数字，则最小的4个数字是1,2,3,4,。


## 解题思路
- 借鉴快速排序，分治法
- 借助STL容器存储前最小的k个数


## 解法一： 利用快速排序（QuickSort）
- 利用快速排序寻找第K个最小数
- 解题思路与39题一致
- 每次基准数插入后， 判断基准数的下标是否为第k个。如果是，则将数组的前k个数输出
- 如果基准数的下标比k大，则在基准数右边的数列中继续搜索，否则在基准数左边继续搜索
- 注意判断的标准是基准数下标是否等于k-1。（数组的下标是从0开始， 第K个数的下标是k-1）

```c++
class Solution {
public:
    vector<int> result;
    vector<int>::iterator head;
    vector<int>::iterator result_pointer;
    int k_pos;
    
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        if(k==0 || input.empty() || k>input.size() ){return result;}
        head = input.begin();
        k_pos =k-1;
        partition(input.begin(), input.end()-1);
        
        for(auto i = input.begin(); i<=result_pointer;++i){
            result.push_back(*i);
        }
        
        
        return result;
    }
    
    
    void partition(vector<int>::iterator leftSide, 
                   vector<int>::iterator rightSide){
        if(leftSide> rightSide){return;}
        
        int anchor = *leftSide;
        auto leftPointer = leftSide;
        auto rightPointer = rightSide;
        
        
        while(leftPointer != rightPointer){
            while(*rightPointer >= anchor && leftPointer < rightPointer){--rightPointer;}
            while(*leftPointer <= anchor && leftPointer < rightPointer){++leftPointer;}
            swap(*leftPointer, *rightPointer);
        }
        
        swap(*leftPointer, *leftSide);
        
        int cur_pos = leftPointer - head;
        if(cur_pos == k_pos){ 
            result_pointer = leftPointer;
            
        }else if(cur_pos > k_pos){
            partition(leftSide, leftPointer -1);
        }else if(cur_pos < k_pos){
            partition(leftPointer+1, rightSide);
        }
        
        
    }
};

```


## 解法二：借助STL容器multiset
- 使用multiset 存储最小的k个数
- multiset里面存储的元素会自动排序， 可以选用greater模式，让大的元素排在前面。这样可以防止后续删除指针所引起的失效问题。
- 如果不选用greater 模式， 在删除元素的时候，注意必须使用（--iter）。因为删除的是末尾的元素，如果使用（iter--）使用的是iter原来的值， 往往是multiset.end(), 会导致erase（）操作出错。
- 按顺序遍历数组，每次遇到比multiset里面最大的元素要小的元素时，则插入元素， 并删除头部元素


### 使用multiset<int, greater<int>>

```c++


class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        multiset<int, greater<int>> tmp;
        
        if( k== 0 || input.empty() ||k > input.size()){ 
            vector<int> nothing;
            return nothing;}
        
        for(auto item : input){
            if (tmp.size()<k){tmp.insert(item);}
            
            else if(tmp.size()==k){
                
                if(item < *tmp.begin() ){
                    tmp.erase(tmp.begin() );
                    tmp.insert(item);
                    
                }
            }
            
        }
        
        
        vector<int> result( tmp.begin(), tmp.end() );
        return result;
        
    }
};
```
### 使用multiset<int>
```


class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        multiset<int > tmp;
        
        if( k== 0 || input.empty() ||k > input.size()){ 
            vector<int> nothing;
            return nothing;}
        
        for(auto item : input){
            if (tmp.size()<k){tmp.insert(item);}
            
            else if(tmp.size()==k){
                
                if(item < *(--tmp.end()) ){
                    tmp.erase(--tmp.end());
                    tmp.insert(item);
                    
                }
            }
            
        }
        
        
        vector<int> result( tmp.begin(), tmp.end() );
        return result;
        
    }
};
```
