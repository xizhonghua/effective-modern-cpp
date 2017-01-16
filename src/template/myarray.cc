#include <iostream>
#include <vector>
#include <initializer_list>
#include <cassert>
using namespace std;


template <typename T, size_t SIZE>
class myarray {
public:
  myarray() {
    size_ = SIZE;
    data_ = new T[size_];
  }

  myarray(initializer_list<T> init_list) : myarray() {
    assert(init_list.size() == size_);
    std::copy(init_list.begin(), init_list.end(), data_);
  }

  ~myarray() {
    delete data_;
    data_ = nullptr;
    size_ = 0;
  }

  const T& operator[](int i) const {
    assert(i>=0 && i<=size_);
    return data_[i];
  }

  T& operator[](int i) {
    assert(i>=0 && i<=size_);
    return data_[i];
  }

  const size_t size() const {
    return size_;
  }

private:
  T* data_;
  size_t size_;
};

int main() {

  myarray<int, 5> a{1,2,3,4,5};

  for(int i=0;i<a.size();++i)
    cout << a[i] << endl;

  myarray<double, 3> b{3.14, 2.718, 1.414};
  for(int i=0;i<b.size();++i)
    cout << b[i] << endl; 

  return 0;
}