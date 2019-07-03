#include<iostream>
#include<vector>
using namespace std;
void execute();
void quicksortWithSwap(vector<int>::iterator leftSide, vector<int>::iterator rightSide);


int main(){
       execute();

	return 0;
}


void execute(){
   cout<< "This program is an implementation of the QuickSort Algorithm"<< endl;
   cout<< "Please enter a number series: "<<endl;
   vector<int> inputSeries;
   for(int x; std::cin>>x; inputSeries.push_back(x)){}
   cout<<"The input series is : ";
   for(auto item : inputSeries){cout<<item<<" ";}
   cout<<endl;
   
   quicksortWithSwap( inputSeries.begin(), inputSeries.end()-1);
   cout<<"The sort series is : ";
   for(auto item : inputSeries){cout<<item<<" ";}
   cout<<endl;


}


void quicksortWithSwap(vector<int>::iterator leftSide,
                       vector<int>::iterator rightSide){

                if(leftSide>rightSide){return;}
                int anchor = *leftSide;
                auto leftPointer = leftSide;
                auto rightPointer = rightSide;
              
                while(leftPointer<rightPointer){

                   while( *rightPointer>anchor && leftPointer<rightPointer ){--rightPointer;}
                   while( *leftPointer <= anchor && leftPointer<rightPointer ){++leftPointer;}
                   
                   swap(*leftPointer, *rightPointer);
 
            	}

                swap(*leftPointer, *leftSide);

              quicksortWithSwap(leftSide, leftPointer-1);
              quicksortWithSwap(leftPointer+1, rightSide);


}
