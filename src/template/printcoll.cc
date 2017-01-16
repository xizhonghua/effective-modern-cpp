#include <iostream>
#include <vector>
#include <string>

template <typename T>
void printcoll(const T& coll) {

  typename T::const_iterator pos;
  typename T::const_iterator end(coll.end());

  for(pos=coll.begin(); pos != end; ++pos)
    std::cout << *pos << ' ';

  std::cout << std::endl;
}

int main(int argc, char const *argv[])
{
  std::vector<int> v{1,2,3};
  printcoll(v);

  std::string s{"Hello world!"};
  printcoll(s);

  return 0;
}