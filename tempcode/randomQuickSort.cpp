#include<iostream>
#include<vector>
#include<random>
using namespace std;
void execute();
void quicksortRandom(vector<int>::iterator leftSide,  vector<int>::iterator rightSide);


int main(){
       execute();

	return 0;
}


void execute(){
   cout<< "This program is an implementation of the random QuickSort Algorithm"<< endl;
   cout<< "Please enter a number series: "<<endl;
   vector<int> inputSeries;
   for(int x; std::cin>>x; inputSeries.push_back(x)){}
   cout<<"The input series is : ";
   for(auto item : inputSeries){cout<<item<<" ";}
   cout<<endl;
   
   quicksortRandom( inputSeries.begin(), inputSeries.end()-1);
   cout<<"The sort series is : ";
   for(auto item : inputSeries){cout<<item<<" ";}
   cout<<endl;


}

void quicksortRandom(vector<int>::iterator leftSide, 
		     vector<int>::iterator rightSide){
                    
                    if (leftSide>rightSide){return;}
                      
                    int pos_range = rightSide-leftSide;
                    default_random_engine e;
                    uniform_int_distribution<int> u(0, pos_range);
                    int rand_pos = u(e);
                    
                    swap(*(leftSide+rand_pos) , *leftSide );
                   
                    int anchor = *leftSide;
                    auto leftPointer = leftSide;
                    auto rightPointer = rightSide;

                    while(leftPointer<rightPointer){

                     while(*rightPointer>=anchor && leftPointer< rightPointer ){--rightPointer;}
                     while(*leftPointer <= anchor && leftPointer< rightPointer){++leftPointer;}
                     swap(*leftPointer, *rightPointer);


                   }
                   
                   swap(*leftSide, *leftPointer);

                  quicksortRandom(leftSide, leftPointer-1);
                  quicksortRandom(leftPointer+1, rightSide);

}

