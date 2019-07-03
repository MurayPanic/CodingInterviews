# 快速排序法（QuickSort）合集


## 入门理解
 - 参考 [白话经典算法系列之六 快速排序 快速搞定](https://blog.csdn.net/MoreWindows/article/details/6684558 ) 写出来的。
 - 思路上是“挖坑填数”
 - 使用迭代器来实现，参数传递中不需要传递数组
 - 注意比较大小的时候，一定要引入等于号。
 - 控制两个指针的循环条件是左指针小于右指针。

```c++
#include<iostream>
#include<vector>
using namespace std;

void execute();
void quicksort(vector<int>::iterator leftPointer, 
               vector<int>::iterator rightPointer);

vector<int>::iterator adjustArray(vector<int>::iterator leftPointer,  vector<int>::iterator rightPointer);


int main(){
       execute();

	return 0;
}


void execute(){
   cout<< "This program is an implementation of the QuickSort Algorithm"<< endl;
   cout<< "Please enter a number series: "<<endl;
   vector<int> inputSeries;
   for(int x; std::cin>>x; inputSeries.push_back(x)){}
   cout<<"The input series is : ";
   for(auto item : inputSeries){cout<<item<<" ";}
   cout<<endl;
   
   quicksort( inputSeries.begin(), inputSeries.end()-1);
   cout<<"The sort series is : ";
   for(auto item : inputSeries){cout<<item<<" ";}
   cout<<endl;


}

void quicksort( 
               vector<int>::iterator leftPointer, 
               vector<int>::iterator rightPointer){
          
        if(leftPointer < rightPointer){      
           vector<int>::iterator i = adjustArray(leftPointer, rightPointer);
           quicksort(leftPointer, i-1 );
           quicksort( i+1, rightPointer);

	}
        
  
}



vector<int>::iterator adjustArray( vector<int>::iterator leftPointer, 
               		           vector<int>::iterator rightPointer){

              int anchor = *leftPointer;
              while(leftPointer< rightPointer){
               
  	 
                   while(leftPointer<rightPointer && *rightPointer>= anchor){--rightPointer;}
                   if(leftPointer<rightPointer){
                       *leftPointer= *rightPointer;
                       ++leftPointer;
                  }
                  
                  while(leftPointer<rightPointer && *leftPointer< anchor){++leftPointer;}
                  if(leftPointer<rightPointer){
                       *rightPointer= *leftPointer;
                       --rightPointer;
                  }

             }
            
             *leftPointer = anchor;
             return leftPointer;

   

}




```


## 利用swap实现
  - 参考[算法 3：最常用的排序——快速排序](https://wiki.jikexueyuan.com/project/easy-learn-algorithm/fast-sort.html)写出来的
  - 理解思路是交换
  - 代码实现中使用了swap。 注意如果是交换迭代器里面的值，应该写成swap(*iter1, *iter2). 如果想直接交换迭代器，则应该用iter_swap(iter1, iter2).
  - 注意必须要写入推出条件，当左指针在有指针右侧时候， 则直接返回
  - 控制两个指针的循环条件可以是左指针小于右指针， 也可以是左右指针不相等。


```c++
#include<iostream>
#include<vector>
using namespace std;
void execute();
void quicksortWithSwap(vector<int>::iterator leftSide, vector<int>::iterator rightSide);


int main(){
       execute();

	return 0;
}


void execute(){
   cout<< "This program is an implementation of the QuickSort Algorithm"<< endl;
   cout<< "Please enter a number series: "<<endl;
   vector<int> inputSeries;
   for(int x; std::cin>>x; inputSeries.push_back(x)){}
   cout<<"The input series is : ";
   for(auto item : inputSeries){cout<<item<<" ";}
   cout<<endl;
   
   quicksortWithSwap( inputSeries.begin(), inputSeries.end()-1);
   cout<<"The sort series is : ";
   for(auto item : inputSeries){cout<<item<<" ";}
   cout<<endl;


}


void quicksortWithSwap(vector<int>::iterator leftSide,
                       vector<int>::iterator rightSide){

                if(leftSide>rightSide){return;}
                int anchor = *leftSide;
                auto leftPointer = leftSide;
                auto rightPointer = rightSide;
              
                while(leftPointer<rightPointer){

                   while( *rightPointer>anchor && leftPointer<rightPointer ){--rightPointer;}
                   while( *leftPointer <= anchor && leftPointer<rightPointer ){++leftPointer;}
                   
                   swap(*leftPointer, *rightPointer);
 
            	}

                swap(*leftPointer, *leftSide);

              quicksortWithSwap(leftSide, leftPointer-1);
              quicksortWithSwap(leftPointer+1, rightSide);


}
```


## 随机快速排序
 - 原快速排序的算法总是选取数列最左边的元素作为基准数。
 - 在快速排序的基础上在选取基准数时加入随机模块，就变成随机快速排序
 - 选取数列中任意一个元素作为基准数，选取了之后，将其与最左边的元素交换位置。之后的步骤按照普通的快速排序算法执行
 - 需要用到c++里面的random 模块。 具体使用可以参考[【C++11】随机值获取——random](https://www.jianshu.com/p/05863a00af8d)
 - 在实现中，先生成一个随机数， 然后将左指针根据随机数移动一定长度， 然后抽取该指针指向的元素作为基准数。
 - 参考资料： [算法导论（一）：快速排序与随机化快排](https://blog.csdn.net/haelang/article/details/44496387)


```c++
#include<iostream>
#include<vector>
#include<random>
using namespace std;
void execute();
void quicksortRandom(vector<int>::iterator leftSide,  vector<int>::iterator rightSide);


int main(){
       execute();

	return 0;
}


void execute(){
   cout<< "This program is an implementation of the random QuickSort Algorithm"<< endl;
   cout<< "Please enter a number series: "<<endl;
   vector<int> inputSeries;
   for(int x; std::cin>>x; inputSeries.push_back(x)){}
   cout<<"The input series is : ";
   for(auto item : inputSeries){cout<<item<<" ";}
   cout<<endl;
   
   quicksortRandom( inputSeries.begin(), inputSeries.end()-1);
   cout<<"The sort series is : ";
   for(auto item : inputSeries){cout<<item<<" ";}
   cout<<endl;


}

void quicksortRandom(vector<int>::iterator leftSide, 
		     vector<int>::iterator rightSide){
                    
                    if (leftSide>rightSide){return;}
                      
                    int pos_range = rightSide-leftSide;
                    default_random_engine e;
                    uniform_int_distribution<int> u(0, pos_range);
                    int rand_pos = u(e);
                    
                    swap(*(leftSide+rand_pos) , *leftSide );
                   
                    int anchor = *leftSide;
                    auto leftPointer = leftSide;
                    auto rightPointer = rightSide;

                    while(leftPointer<rightPointer){

                     while(*rightPointer>=anchor && leftPointer< rightPointer ){--rightPointer;}
                     while(*leftPointer <= anchor && leftPointer< rightPointer){++leftPointer;}
                     swap(*leftPointer, *rightPointer);


                   }
                   
                   swap(*leftSide, *leftPointer);

                  quicksortRandom(leftSide, leftPointer-1);
                  quicksortRandom(leftPointer+1, rightSide);

}

```
 
