#include <iostream>
using namespace std;

void printStuff() {
  cout << endl;
}

template<typename TFirst, typename... TRest>
void printStuff(TFirst first, TRest... rest) {
  cout << first << " ";
  printStuff(rest...);
}


int main() {
  printStuff(3.14, "Hello World!", 89);
  return 0;
}