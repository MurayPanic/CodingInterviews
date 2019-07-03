#include<iostream>
#include<vector>
using namespace std;

void execute();
void quicksort(vector<int>::iterator leftPointer, 
               vector<int>::iterator rightPointer);

vector<int>::iterator adjustArray(vector<int>::iterator leftPointer,  vector<int>::iterator rightPointer);


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
   
   quicksort( inputSeries.begin(), inputSeries.end()-1);
   cout<<"The sort series is : ";
   for(auto item : inputSeries){cout<<item<<" ";}
   cout<<endl;


}

void quicksort( 
               vector<int>::iterator leftPointer, 
               vector<int>::iterator rightPointer){
          
        if(leftPointer < rightPointer){      
           vector<int>::iterator i = adjustArray(leftPointer, rightPointer);
           quicksort(leftPointer, i-1 );
           quicksort( i+1, rightPointer);

	}
        
  
}



vector<int>::iterator adjustArray( vector<int>::iterator leftPointer, 
               		           vector<int>::iterator rightPointer){

              int anchor = *leftPointer;
              while(leftPointer< rightPointer){
               
  	 
                   while(leftPointer<rightPointer && *rightPointer>= anchor){--rightPointer;}
                   if(leftPointer<rightPointer){
                       *leftPointer= *rightPointer;
                       ++leftPointer;
                  }
                  
                  while(leftPointer<rightPointer && *leftPointer< anchor){++leftPointer;}
                  if(leftPointer<rightPointer){
                       *rightPointer= *leftPointer;
                       --rightPointer;
                  }

             }
            
             *leftPointer = anchor;
             return leftPointer;

   

}




