#include<iostream>
#include<vector>
using namespace std;

void rockDice(vector<int>& dice, vector<int>::iterator pointer, vector<int>& result){

        if(pointer==dice.end()){
            int tmpSum{0};
            int len = dice.size();
            for(auto item: dice){tmpSum+=item;}
            ++result[tmpSum-len];

            return;
        }

        for(int i =1; i<=6;++i){
            *pointer = i;
            rockDice(dice, pointer+1, result);
        }


    }



vector<int> numberOfDice(int n) {
        vector<int> result(5*n+1,0);
        vector<int> dice(n,0);
        rockDice(dice, dice.begin(), result);
        return result;
    }


void process(){
      cout<<"This program return the combination of the N dice."<<endl;
      int n;
      cout<< "PLease enter a number: ";
      cin >> n;
      cout<<endl;
      vector<int> combination = numberOfDice(n);
      for(auto item: combination){
	      cout<<item<<" ";
      }
      cout<<endl;


}




int main(){
 	process();

	return 0;
}
