#include<iostream>
#include<math.h>
#include <climits>
using namespace std;


int numRange(int i){
       int numCount{0};
       if(i<9){numCount = i*(pow(10,i)-pow(10,i-1)) ;}
       else{numCount = INT_MAX - pow(10, 8);}
       
       return numCount;
    }

int main(){
       for (int i =1; i <=20; ++i){
       cout<< i<< ":  "<<numRange(i)<<endl;
      
    }


	return 0;
}
