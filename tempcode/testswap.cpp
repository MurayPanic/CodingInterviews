#include<iostream>
#include<vector>
using namespace std;

int main(){
       vector<int> number{1,2,3,4,5,6,7,8,9};
       for(auto item : number){
         cout<<item<<" ";
   	}
        cout<<endl;
     
       iter_swap(number.begin(), (number.begin()+2));
       cout<<"After swap"<<endl;
       for(auto item : number){
         cout<<item<<" ";
   	}
        cout<<endl;

	return 0;
}
