#include<iostream>
#include<typeinfo>
using namespace std;

int main(){

       int a =1;
       char b;
       b=a;
       cout<<typeid(a).name()<<endl;
       cout<<typeid(b).name()<<endl;
	return 0;
}
