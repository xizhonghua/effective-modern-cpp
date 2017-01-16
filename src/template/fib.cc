#include <iostream>
using namespace std;

template<size_t N> struct fib;

template<> struct fib<0>{ const static auto value = 1LL; };

template<> struct fib<1>{ const static auto value = 1LL; };

template<size_t N> struct fib {
  const static auto value = fib<N-1>::value + fib<N-2>::value;
};

int main() {
  cout<<fib<0>::value<<" "<<fib<1>::value<<" "<<fib<2>::value<<" "<<fib<3>::value<<" "<<fib<10>::value<<endl;
  return 0;
}