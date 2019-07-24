# 剑指offer - 和为s的两个数字
题目描述：输入一个递增排序的数组和一个数字S，在数组中查找两个数，使得他们的和正好是S，如果有多对数字的和等于S，输出两个数的乘积最小的。

输出描述： 对应每个测试案例，输出两个数，小的先输出。

## 解题思路：
- 哈希表
- 双指针法

### 解法一：哈希表
- 遍历数组，建立一个哈希表，其中键为数组中的元素，值为和减去数组中的元素值；
- 遍历哈希表，查询每个键对应的值是否也是哈希表里面的键。

```c++
class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        vector<int> result;
        if(array.empty()){return result;}

        unordered_map<int, int> numDict;

        for(auto item : array){
            auto pos = numDict.find(item);
            if(pos == numDict.end() ){
                numDict[item]= sum-item;
            }else{
                continue;
            }

        }

        for(auto item : numDict){
            auto pos = numDict.find(item.second);
            if( pos!=numDict.end() ){
                int tmp = item.first * item.second;

                int cur=INT_MAX;

                if (!result.empty()){cur = result[0]*result[1];}

                if(tmp<cur){
                    if(result.empty()){
                        result.push_back(item.first);
                        result.push_back(item.second);
                    }else{
                        result[0] = item.first;
                        result[1] = item.second;
                    }

                }
            }
        }

        sort(result.begin(), result.end());

        return result;



    }
};
```

### 解法二： 双指针法
- 一个指针指向头部，一个指针指向尾部；
- 头指针指向的是数组中最小的数字，尾指针指向的是数组中最大的数字；
- 当当前的和比目标大的时候，向前移动尾指针；
- 当当前的和比目标小的时候，向后移动头指针；
- 当当前的和等于目标的时候，考虑其乘积是否为当前最小，若是则记录下来;

```c++
class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        vector<int> result;
        if( array.empty() ){return result;}
        auto head = array.begin();
        auto tail = array.end()-1;
        int curSum=0;
        while(head < tail){
            curSum = *head +*tail;
            if(curSum == sum ){
                int tmp = (*head) * (*tail);
                int curTmp = result.empty() ? INT_MAX  : result[0] * result[1];

                if(tmp<curTmp){
                    if(result.empty()){
                        result.push_back(*head);
                        result.push_back(*tail);
                    }else{
                        result[0] = *head;
                        result[1] = *tail;
                    }
                }
                ++head;
                --tail;
            }

            else if(curSum>sum){--tail;}
            else if(curSum<sum){++head;}

        }

        sort(result.begin(), result.end());
        return result;
    }
};
```
