#include<iostream>
#include<string>
#include<vector>
using namespace std;
void execute();
void combination( string str);
void combinationCore(string &str, string::iterator str_iter, int number, vector<char> &result);
vector<string> combResult;

int main(){
       execute();

	return 0;
}


void execute(){
   cout << "This program is to generate the combination of all string using recursive function"<<endl;
   cout << "Please input a string: " ;  
   string str;
   cin >> str;
   cout <<endl;
   combination(str);

}

void combination( string str){
       if(str.empty()){ cout<<"Empty input. "<< endl;}
      
       vector<char> result;
       int i, len = str.size();
       string::iterator str_iter=str.begin();
       for(int i=1; i<=len; ++i){combinationCore(str, str_iter, i, result);} 
       
       for(auto item: combResult){cout<<item<<endl;}

}

void combinationCore(string &str, string::iterator str_iter, int number, vector<char> &result){
          if(str.empty()){return;}
         
          if(number==0){

            
               string tmp(result.begin(), result.end());
               combResult.push_back(tmp);          
               return;

           }
          

          if(str_iter == str.end()){return;}
          result.push_back(*str_iter);
          combinationCore(str, str_iter+1, number-1, result);
          result.pop_back();
          combinationCore(str, str_iter+1, number,result);

}











