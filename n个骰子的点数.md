# 剑指offer - n个骰子的点数
题目描述：将一个骰子投掷n次，获得的总点数为s，s的可能范围为n~6n。
掷出某一点数，可能有多种掷法，例如投掷2次，掷出3点，共有(1,2),(2,1)两种掷法。请求出投掷n次，掷出n~6n点分别有多少种掷法。

[ACWing传送门](https://www.acwing.com/problem/content/76/)

## 解题思路：
- ACWing上的题目与原书中的题目中要求的输出不同，原书中要求输出的是概率，而ACWing上只是要求统计掷法数目，不过本质是一样的;
- 可以有三种解法：
	+ 暴力枚举;
	+ 递归;
	+ 动态规划。

### 解法一： 暴力枚举
- 首先把n个骰子所能投出的点数组合全部枚举出来，然后求和；
- 求和完后统计和的个数；
- 程序上的实现就是先求出全排列，然后算出每个排列的和；
- 会超时；

```c++
class Solution {
public:

     
    vector<int> numberOfDice(int n) {
        vector<int> result(5*n+1,0);
        vector<int> dice(n,0);
        rockDice(dice, dice.begin(), result);
        return result;
    }
    
    void rockDice(vector<int>& dice, vector<int>::iterator pointer, vector<int>& result){
        
        if(pointer==dice.end()){
            int tmpSum{0};
            int len = dice.size();
            for(auto item: dice){tmpSum+=item;}
            ++result[tmpSum-len];
            return;
        }
        
        for(int i =1; i<=6;++i){
            *pointer = i;
            rockDice(dice, pointer+1, result);
        }
        
        
    }
        
};
```


### 解法二：递归
- 能够生成正确的结果;
- 在ACWing上超时，不能被接受。

```c++
class Solution {
public:
    vector<int> numberOfDice(int n) {
        vector<int> result;
        for(int sum=n; sum <=6*n; ++sum){
            int tmp = numOfSum(sum, n);
            result.push_back(tmp);
        }

        return result;
    }

    int numOfSum(int sum, int n){

        if(n==1){
            return (sum<=6 && sum>0) ?  1 : 0 ;
        }

        int tmp{0};

        for(int i =1 ; i<=6; ++i){
	    if(sum-i<=0){break;}
            tmp+=numOfSum(sum-i, n-1);
        }

        return tmp;


    }


};

```

### 解法三 动态规划：
- 首先要有一个概念。就是摇n个骰子得出的和为s的组合数目，等于以下情况出现的次数的和：
	+ 摇n-1个骰子得出的和为s-1。也就是说第n次摇出的数字是1;
	+ 摇n-1个骰子得出的和为s-2。也就是说第n次摇出的数字是2;
	+ 摇n-1个骰子得出的和为s-3。也就是说第n次摇出的数字是3;
  	+ 摇n-1个骰子得出的和为s-4。也就是说第n次摇出的数字是4;
	+ 摇n-1个骰子得出的和为s-5。也就是说第n次摇出的数字是5;
	+ 摇n-1个骰子得出的和为s-6。也就是说第n次摇出的数字是6;
- 所以这里动态规划对应的状态转移方程是一个二元函数f(n,s), 其中n是骰子的个数， s是和; 具体的转移方程是：
	+ f(n,s) = f(n-1, s-1)+f(n-1, s-2)+f(n-1, s-3)+f(n-1, s-4)+f(n-1, s-5)+f(n-1, s-6)
- 用动态规划实现，需要维护一张n 乘 6n的二维表。
- 具体实现时候要注意：
	+ 动态规划表格元素的下标起始是0 还是1;
	+ 要摇n个骰子，和的范围是n～6n；
	+ 用vector容器实现记得要先初始化。

```c++
class Solution {
public:
    vector<int> numberOfDice(int n) {
        vector< vector<int> > dp(n+1);
        
        for(auto & row : dp){
           row.resize(6*n+1, 0);    
        }
        
        for(int i = 1 ; i<=6; ++i){
            dp[1][i]=1;
        }
        
        for(int i = 1; i <= n ; ++i){
             for(int j = i; j <= 6*i+1; ++j){
                 
                 for(int k=1; k<=6;++k){
                     if(j-k>0 && i-1>0){
                         dp[i][j] +=dp[i-1][j-k];
                     }else{break;}
                 }
             }
        }
        
        vector<int> result;
        
        for(int i=n; i<=6*n;++i){
            result.push_back(dp[n][i]);
        }
        
        
        
        return result;
    }
};
```

