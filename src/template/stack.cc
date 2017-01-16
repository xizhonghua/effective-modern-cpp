#include <iostream>
#include <vector>
#include <stdexcept>
#include <string>
#include <typeinfo>

template <typename T>
class Stack {
public:
  Stack() {}
  ~Stack() {}

  Stack(const Stack<T>& other) {
    elements_ = other.elements_;
  }

  Stack<T>& operator=(const Stack<T>& other) {
    elements_ = other.elements_;
    return *this;
  }

  Stack(const std::initializer_list<T>& list) {
    for(const T& e : list)
      this->push(e);
  }

  void push(const T& element) {
    elements_.push_back(element);
  }

  void pop() {
    if(empty()) {
      throw std::out_of_range(std::string("Stack<") + ">::pop(): empty stack");
    }
    elements_.pop_back();
  }

  T top() const {
    if(empty()) {
      throw std::out_of_range(std::string("Stack<") + ">::top(): empty stack"); 
    }
    return elements_.back();
  }

  bool empty() const {
    return elements_.empty();
  }
private:
  std::vector<T> elements_;
};

template <typename T>
void testStack(Stack<T> s) {
  try {
    s.top();
  } catch(const std::out_of_range& e) {
    std::cerr << e.what() << std::endl;
  }

  while(!s.empty()) {
    T e = s.top();
    std::cout << e << " ";
    s.pop();
  }
  std::cout << std::endl;

  try {
    s.top();
  } catch(const std::out_of_range& e) {
    std::cerr << e.what() << std::endl;
  }

  try {
    s.pop();
  } catch(const std::out_of_range& e) {
    std::cerr << e.what() << std::endl;
  }
}

int main() {
  Stack<int> s1{{1,2,3,4,5}};

  testStack(s1);

  Stack<std::string> s2{{"world!", "templeta", "Hello"}};
  Stack<std::string> s3{s2};
  Stack<std::string> s4 = s3;

  testStack(s2);
  testStack(s3);
  testStack(s4);

  return 0;
}