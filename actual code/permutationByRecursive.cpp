#include<iostream>
#include<string>

using namespace std;

void iter_swap(std::string::iterator a, std::string::iterator b){
     auto temp = (*a);
     *a= (*b);
     *b=temp;

}





void printPermutationRecursively(string*  input_str,
                                 std::string::iterator cursor){
       auto tail = input_str->end();
       if (cursor ==tail){cout<<(*input_str)<<endl;}
       else{
           
           for(auto iter = cursor;iter!=tail; ++iter){
		iter_swap(cursor, iter);
           	printPermutationRecursively(input_str, cursor+1);
           	iter_swap(cursor,iter);
           }
          

}
          

}


void main_func(){
   cout<< "This function try to print the permutation of a string with recursive function"<<endl;
   cout<< "Please enter a string:";
   string input_str;
   getline(cin, input_str);
   
   string* p_str = &input_str;
   auto cursor = input_str.begin();   
   auto tail = input_str.end();
   printPermutationRecursively(p_str, cursor);
}



int main(){
     main_func();
    

    return 0;
}
