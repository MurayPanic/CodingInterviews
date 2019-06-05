#include<iostream>
#include<string>
using namespace std;


void print1toNMaxofNdigitsRecursive(string* number_pointer, std::string::iterator index){
    if (index == number_pointer->end()){cout<<*number_pointer<<endl;}
    else{
     for(int i =1; i<10; ++i){
     (*index) = i +'0';
     auto next = index+1;
     print1toNMaxofNdigitsRecursive(number_pointer, next);
    }

}
     


}


void print1toNMaxofNdigits(int n){
    if(n<0){return;}
    string number(n,'0');
    string* number_pointer=&number;
    
    auto index = number_pointer->begin();
    print1toNMaxofNdigitsRecursive(number_pointer, index);


}



void execute(){
   cout<<"This program print the 1 to the max digit number recursively"<<endl;
   cout<<"PLease enter the number of digits: ";
   int n;
   cin>>n;
   cout<<endl;
   print1toNMaxofNdigits(n);


}


int main(){
     execute();


	return 0;
}
