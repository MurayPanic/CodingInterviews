#include<iostream>
#include<string>
#include <typeinfo>
using namespace std;




bool Increment(string& number){
     
     bool isOverflow = false;
     int nTakeOver =0;
     int nLength = number.size();

     for (int i =nLength-1; i>=0; i--){
		  //string cur_digit_str (number[i]);
		  int cur_digit = number[i]-'0';
     
          int nSum = cur_digit+1;
		  //cout<<"cur_digit:"<<cur_digit<<endl;
	      //cout<< "nSUm:"<<nSum<<endl;
         
          
         if (nSum <10){
             string newDigit = to_string(nSum) ;
			 //cout<< "newDigit: "<< newDigit<<endl;
			 //cout<<"newDigit type: "<<typeid(newDigit).name()<<endl;
             number.replace(i, 1, newDigit);
             return isOverflow;
             
          }else{
             string newDigit = to_string(nTakeOver) ;
             number.replace(i, 1, newDigit);       
          }
          
     }
  	
    
     isOverflow = true;
     return isOverflow;
}

void test_Increment(){
     string inputNumber(10,'0');
     cout<<inputNumber<<endl;
     
     inputNumber.replace(inputNumber.begin(), inputNumber.begin()+1,"8");
     cout<<inputNumber<<endl;
     inputNumber[3]-'0'+'6';
     cout<<inputNumber<<endl;
     
     string testInput(1,'0');
     /*cout<<testInput<<endl;
     Increment(testInput);
     cout<<testInput<<endl;
     Increment(testInput);
     cout<<testInput<<endl;
     Increment(testInput);
     cout<<testInput<<endl;
	 */
	 
	 for(int i =0; i<10; ++i){
		 bool overflowOrNot=Increment(testInput);
         cout <<"Overflow:"<<overflowOrNot<<endl;		 
		cout<<testInput<<endl;
	 }
	 
	 string testInput2(3,'0');
	 
	 while(not Increment(testInput2)){
		 cout<< testInput2<<endl;
	 }


}


void PrintNumber(string number){
	  bool notZero{false};
	  for(auto digit : number){
		  
		  if(!notZero && digit=='0'){continue;}
		  else{notZero =true;}
		  cout <<digit;
	  }
	  cout<<endl;
      
}


void test_PrintNumber(){
	string a("00010240309");
	PrintNumber(a);
	
}


void print1ToMaxofNDigits(int n){
	if(n<=0){return ;}
        string number(n, '0');
	//number.push_back('\0');

    while(!Increment(number) ){
    PrintNumber(number);
    }
  
    number.~string();


}

void execute(){
    cout<<"This program is used to output the largest number with n digit"<<endl;
    cout << "Please enter the number of digits : ";
    int n;
    cin>> n;
    print1ToMaxofNDigits(n);

}


int main(){
    execute();

    return 0;
}
