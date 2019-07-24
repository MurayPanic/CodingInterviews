# 剑指offer - 和为s的连续正数序列
题目描述： 输入一个正数s， 打印出所有和为s的连续正数序列（至少含有两个数）。 例如，输入15, 由于1+2+3+4+5=4+5+6=7+8=15, 所以打印出3个连续序列1～5, 4～6 和7～8。

## 解题思路：
- 暴力穷举
- 双指针策略


### 解法一： 暴力穷举
- 注意循环的起始条件。

```c++
class Solution {
public:
    vector<vector<int> > FindContinuousSequence(int sum) {
        vector<vector<int> > result;
        int target = sum;
        int head = 1;
        while(head <sum){
            int tmp = head;
            while(target>0){
                target-=tmp;
                ++tmp;
            }
            if(target ==0){
                vector<int> tmpResult;
                for(int index = head; index<tmp; ++index){tmpResult.push_back(index);}
                result.push_back(tmpResult);
            }
            ++head;
            target= sum;
        }

        return result;
    }
};
```

### 解法二： 双指针思想
- 实际的实施不一定用指针实现；
- 记录连续数组的头元素和尾元素大小；
- 当当前数组和比目标小的时候，尾部元素加一， 然后将该元素加入到和中；
- 当当前数组和比目标大的时候，先将该元素从和中减去，然后头部元素加一；
- 循环的条件是头元素比（目标+1）/2小的时候（不含等于号）。

```c++
class Solution {
public:
    vector<vector<int> > FindContinuousSequence(int sum) {
        int head =1;
        int tail =2;
        int cursum=head+tail;
        vector<vector<int> > result;
        while(head < (sum+1)/2 ){

            if(cursum == sum){
                vector<int> tmpResult;
                for(int index = head; index<=tail;++index){tmpResult.push_back(index);}
                result.push_back(tmpResult);
                ++tail;
                cursum +=tail;
            }

            else if(cursum<sum){
                ++tail;
                cursum += tail;
            }
            else if(cursum>sum){
                cursum -= head;
                ++head;
            }


        }

        return result;
    }
};
```
