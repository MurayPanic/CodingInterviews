#include<iostream>
#include<bitset>
using namespace std;

int main(){
        int c=2;
	bitset<sizeof(int)*8> bitshow(c);
	cout <<"Original C: "<< c <<endl;
	cout <<"Show in bit: "<< bitshow<<endl;
	cout <<"The length of the bit is : " << bitshow.size()<<endl;

	cout <<"Now find the most right 1: "<<endl;
	    
	for(int i=bitshow.size()-1; i>=0; --i){
		if(bitshow[i]==1){
	        cout<< "It is in position : " << i <<endl;
		break;
		}
	}

	cout << "Now print the num digit by digit" <<endl;
	
	for(int i=bitshow.size()-1; i>=0; --i){
		cout<<"The " <<i << " digit is :" << bitshow[i] <<endl;
	}

        cout << "Now try to print in another way." << endl;
	for(int i =0; i<bitshow.size();++i){
		cout<< "The"<<i << " digit is :" <<bitshow[i] <<endl;
	}



	return 0;
}
