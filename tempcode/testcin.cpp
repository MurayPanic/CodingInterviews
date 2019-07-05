#include<iostream>
#include<vector>
using namespace std;

int main(){
     cout<<"This Program is to test cin" <<endl;
     int a ;
      cout << "PLease enter a value"<<endl;
      cin>>a;
      cout << "Please enter b value"<< endl;
      int b;
     if(cin.fail()){cin.clear();cin.ignore(1024,'\n');}
      cin>>b;
     cout <<"The value of a is:  "<< a <<endl;
     cout<<"The value of b is "<< b <<endl; 
     
     vector<int> test;
    for(int x; cin >>x; test.push_back(x)){}

    for(auto item :test){cout<<item << " ";}
    cout <<endl;
      

	return 0;
}
