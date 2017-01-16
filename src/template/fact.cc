#include <iostream>
using namespace std;

template <size_t N> struct fact;

template<>
struct fact<0> {
  static const auto value = 1;
};

template<size_t N>
struct fact
{
  static const auto value = N * fact<N-1>::value;
};

int main() {
  cout<<"fact<1>::value = "<<fact<1>::value<<endl;
  cout<<"fact<2>::value = "<<fact<2>::value<<endl;
  cout<<"fact<3>::value = "<<fact<3>::value<<endl;
  cout<<"fact<4>::value = "<<fact<4>::value<<endl;
  cout<<"fact<5>::value = "<<fact<5>::value<<endl;
  cout<<"fact<6>::value = "<<fact<6>::value<<endl;
  return 0;
}