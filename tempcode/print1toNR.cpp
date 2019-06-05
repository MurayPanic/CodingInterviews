#include<iostream>
#include<string>
using namespace std;

void PrintNumber(string number){
	  bool notZero{false};
	  for(auto digit : number){
		  
		  if(!notZero && digit=='0'){continue;}
		  else{notZero =true;}
		  cout <<digit;
	  }
	  cout<<endl;
      
}


void Print1toMaxOfNDigitsRecursively(string& number, int length, int index){
     if(index == length-1){
        PrintNumber(number);
        return;
       }
     
      for(int i =0; i<10;++i){
      number[index+1] = i+'0';
      Print1toMaxOfNDigitsRecursively(number, length, index+1);
         }


}


void Print1toMaxOfNDigits(int n){
  if(n<=0){return;}
  
  string number(n,0);

  for(int i =0; i<10; ++i){
     number[0] = i + '0';
     Print1toMaxOfNDigitsRecursively(number, n,0);
  }

  number.~string();

}


void execute(){
  cout<<"This program prints from 1 to the max of the n digits." <<endl;
  cout<<"Please enter an integer: " << endl;
  int n;
  cin >>n;
  
  Print1toMaxOfNDigits(n);


}




int main(){
  execute();

  return 0;
}

