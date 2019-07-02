#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;


vector<string> genCombination(string str, vector<string> bitmap){
        vector<string> combination;
        
        for(auto item : bitmap){
           string tmp;
           for(int i =0; i<str.size(); ++i){
            if(item[i]=='1'){tmp += str[i];}
     	  }
           combination.push_back(tmp);
	}
          
        return combination;


}


void genBitmapRecursively ( vector<string> &bitmap, string &tmp, string::iterator pointer){
      if(pointer == tmp.end() ){
         bitmap.push_back(tmp);
        return;}
       
       for(int i = 0; i<2; ++i){
           *pointer = i+'0';
           genBitmapRecursively(bitmap, tmp, pointer+1);
  }
 
}



vector<string> genBitmap(int n){

    string tmp(n,'0');
    
    vector<string> bitmap;
    
    genBitmapRecursively(bitmap, tmp,tmp.begin());
    
    return bitmap;
}


void printCombination(string str){
    
   
     int  n = str.size();
     vector<string> bitmap;
     bitmap= genBitmap(n); 
     vector<string> combination;
     combination = genCombination(str, bitmap);
     sort(combination.begin(), combination.end() );
     for(auto item :combination){
      cout<<item<<endl;
}

     return;

}


void execute(){
     cout<<"This program is to print the all combination of a string"<< endl;
     string str;
     cin>> str;
     printCombination(str);

}


int main(){
      execute();

	return 0;
}
