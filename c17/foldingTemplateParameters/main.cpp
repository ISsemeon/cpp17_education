#include <iostream>

#include <vector>
#include <array>


namespace ex1
{
  template<typename... T> auto summa(T ... s)
  {
    return (... + s);
  }

  void exFoo()
  {
    std::cout << summa(1,2,3) << std::endl;
  }
}

namespace ex2
{
  template<typename Fnc, typename... T>
  void call(Fnc pFunc, T&&... vr)
  {
    (pFunc(vr), ...);
  }

  void exFoo()
  {
    call([](auto v) { std::cout << v << " "; }, 69 ," <- | -> ", 100);
    std::cout << std::endl;
  }
}

namespace ex3
{
  template<typename... Args>
  auto unary_right(Args... args)
  {
    return (args + ...);
  }

  template<typename... Args>
  auto unary_left(Args... args)
  {
      return (... + args);
  }

  template<typename... Args>
  auto binary_right(Args... args)
  {
      return (args + ... + 0);
  }

  template<typename... Args>
  auto binary_left(Args... args)
  {
      return (100 + ... + args);
  }

  void exFoo()
  {
    std::cout << unary_right(2, 2)  << std::endl;
    std::cout << unary_left(2, 2)   << std::endl;
    std::cout << binary_right(2, 2) << std::endl;
    std::cout << binary_left(2, 2)  << std::endl;
  }
}

namespace ex4
{
  template <class... Args>
  bool containsZero(Args const&... args)
  {
    return ((args == 0) || ...);
  }

  void exFoo()
  {
    std::cout << (containsZero(1, 2, 3, 4, 5) ? "yes" : "no") << std::endl;
    std::cout << (containsZero(1, 0, 3, 4, 5) ? "yes" : "no") << std::endl;
  }
}

namespace ex5
{
  template <class... Args> bool isOk(Args ... args)
  {
    return (args() && ...);
  }

  void exFoo()
  {
    // sensors
    auto s1 = []{ return true;};
    auto s2 = []{ return true;};
    auto s3 = []{ return true;};
    auto s4 = []{ return true;};
    auto s5 = []{ return true;};

    std::cout << (isOk(s1, s2, s3, s4, s5) ? "all Ok. Go! brrrr" : "stop" ) << std::endl;
  }
}

int main()
{
  ex1::exFoo();
  ex2::exFoo();
  ex3::exFoo();
  ex4::exFoo();
  ex5::exFoo();
  return 0;
}