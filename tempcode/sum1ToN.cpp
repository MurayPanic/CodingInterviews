#include<iostream>
using namespace std;



template < int n> class Sum
{
   public:
    enum Value
    {
        N = Sum< n - 1 >::N + n
    };
};

template <> struct Sum<1>
{
  public:
    enum Value
    {
        N = 1
    };
};


int main( )
{
  
    cout <<Sum<100>::N <<endl;

    return 0;
}

