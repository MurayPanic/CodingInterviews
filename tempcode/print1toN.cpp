#include<iostream>
#include<string>
using namespace std;




bool Increment(string& number){
     
     bool isOverflow = false;
     int nTakeOver =0;
     int nLength = number.size();

     for (int i =nLength; i>=0; i--){
     
          int nSum = number[i]+1;
	  cout<< "nSUm:"<<nSum<<endl;
         
          
         if (nSum <10){
             string newDigit = to_string(nSum) ;
             number.replace(number.begin()+i-1, number.begin()+i, newDigit);
             return isOverflow;
             
          }else{
             string newDigit = to_string(nTakeOver) ;
             number.replace(number.begin()+i, number.begin()+i+1, newDigit);       
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
     
     string testInput(3,'0');
     cout<<testInput<<endl;
     Increment(testInput);
     cout<<testInput<<endl;
     Increment(testInput);
     cout<<testInput<<endl;
     Increment(testInput);
     cout<<testInput<<endl;



}


void PrintNumber(string number){
      cout<<endl;
      
}



void print1ToMaxofNDigits(int n){
	if(n<=0){return ;}
        string number(n, '0');
	number.push_back('\0');

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
    test_Increment();

    return 0;
}
