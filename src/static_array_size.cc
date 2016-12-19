#include <iostream>
#include <array>

template<typename T, std::size_t N>
constexpr std::size_t arraySize(T (&)[N]) noexcept
{
  return N;
}

int main(int argc, char** argv) {
  int keyVales[] = {1, 3, 7, 9, 11, 22, 35};
  // T -> int
  std::cout << "Array size: "<< arraySize(keyVales) << std::endl;
  return 0;
}