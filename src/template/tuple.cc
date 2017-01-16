#include <iostream>
// using namespace std;

template <typename... Ttypes> class Tuple;

// Empty tuple
template <> class Tuple<> { /* empty */ };

template <typename Tfirst, typename... Trest>
class Tuple<Tfirst, Trest...> : public Tuple<Trest...> {
public:
  Tfirst value;
};

template <size_t idx, typename Ttuple> struct TupleElement;

template <typename Tfirst, typename... Trest>
struct TupleElement<0, Tuple<Tfirst, Trest...>> {
  using type_t = Tfirst;
  using TupleType_t = Tuple<Tfirst, Trest...>;
};

template <size_t idx, typename Tfirst, typename... Trest>
struct TupleElement<idx, Tuple<Tfirst, Trest...>> : public TupleElement<idx-1, Tuple<Trest...>> {
  /* empty */
};

template <size_t idx, typename... Ttypes>
typename TupleElement<idx, Tuple<Ttypes...>>::type_t& get(Tuple<Ttypes...>& tuple) {
  using TupleType_t = typename TupleElement<idx, Tuple<Ttypes...>>::TupleType_t;
  return static_cast<TupleType_t&>(tuple).value;
}


// Basic case
template<size_t idx, typename Ttuple>
void fillTuple(Ttuple& toFill) {};

// Recursive fill
template<size_t idx, typename Ttuple, typename Tfirst, typename... Trest>
void fillTuple(Ttuple& toFill, const Tfirst& first, Trest... rest) {
  get<idx>(toFill) = first;
  fillTuple<idx+1>(toFill, rest...);
}

template <typename... Ttypes>
Tuple<Ttypes...> makeTuple(Ttypes... args) {
  Tuple<Ttypes...> result;
  fillTuple<0>(result, args...);
  return result;
}

int main() {

  auto tuple = makeTuple(5, std::string{"hello"}, 3.14);
  std::cout << get<0>(tuple) << " " << get<1>(tuple) << " " << get<2>(tuple) << std::endl;

  return 0;
}